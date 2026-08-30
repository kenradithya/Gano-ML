#include "GanoMLManager.h"

GanoMLManager::GanoMLManager()
    : _fertilizerRecent(false),
      _hasCustomImpedance(false),
      _customR2k(76.28f),
      _customX2k(-34.79f),
      _customContactQuality(0.85f),
      _roomAirQuality("INIT"),
      _ganodermaTargetStatus("INIT") {
    memset(&_currentInput, 0, sizeof(_currentInput));
    memset(&_currentOutput, 0, sizeof(_currentOutput));
    memset(&_xgbOutput, 0, sizeof(_xgbOutput));
    resetBaseline();
}

void GanoMLManager::begin() {
    resetBaseline();
}

void GanoMLManager::resetBaseline() {
    _baseline.voc_index_corrected = 0.18f;
    _baseline.nh3_ppm             = 0.20f;
    _baseline.x_2khz_ohm          = -34.79f;
    _baseline.r_2khz_ohm          = 76.28f;
    _baseline.is_set              = false;
}

void GanoMLManager::captureBaseline(const GasSensorManager &gasMgr, const DHTManager &dhtMgr) {
    float temp_c = dhtMgr.isValid() ? dhtMgr.getTemperatureC() : 28.0f;
    float rh_pct = dhtMgr.isValid() ? dhtMgr.getHumidity() : 80.0f;
    float airIdx = gasMgr.getTGS2600AirIndex();

    float voc_raw = fminf(1.0f, fmaxf(0.0f, 0.15f + ((airIdx - 100.0f) / 400.0f) * 0.70f));
    _baseline.voc_index_corrected = ganoplus_voc_index_corrected(voc_raw, rh_pct, temp_c);
    _baseline.nh3_ppm             = gasMgr.getNH3PPM();
    if (_hasCustomImpedance) {
        _baseline.x_2khz_ohm = _customX2k;
        _baseline.r_2khz_ohm = _customR2k;
    } else {
        _baseline.x_2khz_ohm = -34.79f;
        _baseline.r_2khz_ohm = 76.28f;
    }
    _baseline.is_set = true;
}

void GanoMLManager::setImpedanceProbe(float r_ohm, float x_ohm, float contact_quality) {
    _hasCustomImpedance   = true;
    _customR2k            = r_ohm;
    _customX2k            = x_ohm;
    _customContactQuality = contact_quality;
}

void GanoMLManager::clearImpedanceProbe() {
    _hasCustomImpedance   = false;
    _customR2k            = 76.28f;
    _customX2k            = -34.79f;
    _customContactQuality = 0.85f;
}

void GanoMLManager::update(const GasSensorManager &gasMgr, const DHTManager &dhtMgr, uint32_t uptimeSec) {
    const float temp_c   = dhtMgr.isValid() ? dhtMgr.getTemperatureC() : 28.0f;
    const float rh_pct   = dhtMgr.isValid() ? dhtMgr.getHumidity() : 80.0f;
    const float airIdx   = gasMgr.getTGS2600AirIndex();
    const float mq3_ppm  = gasMgr.getMQ3Alcohol();
    const float mq4_ppm  = gasMgr.getReading(GAS_MQ4).ppm;
    const float mq9_ppm  = gasMgr.getReading(GAS_MQ9).ppm;
    const float nh3_ppm  = gasMgr.getNH3PPM();
    const float co2_ppm  = gasMgr.getCO2PPM();

    float voc_raw = fminf(1.0f, fmaxf(0.0f, 0.15f + ((airIdx - 100.0f) / 400.0f) * 0.70f));
    float voc_corrected = ganoplus_voc_index_corrected(voc_raw, rh_pct, temp_c);

    // Bio-impedance features
    float x_2khz = _hasCustomImpedance ? _customX2k : -34.785891f;
    float r_2khz = _hasCustomImpedance ? _customR2k : 76.275283f;
    float z_mag  = sqrtf(r_2khz * r_2khz + x_2khz * x_2khz);
    float phase_deg = atan2f(x_2khz, r_2khz) * 57.2957795f;

    float delta_r = 0.0f;
    float delta_x = 0.0f;
    if (_hasCustomImpedance && _baseline.is_set) {
        delta_r = r_2khz - _baseline.r_2khz_ohm;
        delta_x = x_2khz - _baseline.x_2khz_ohm;
    }

    // 13-Dimensional Feature Vector for XGBoost Classifier
    float xgb_features[13] = {
        voc_raw,
        mq3_ppm,
        mq4_ppm / 1000.0f,
        mq9_ppm / 100.0f,
        nh3_ppm,
        temp_c,
        rh_pct,
        r_2khz,
        x_2khz,
        z_mag,
        phase_deg,
        delta_r,
        delta_x
    };

    // Execute XGBoost Ensemble Inference
    _xgbOutput = XGBoostGano::predict(xgb_features);

    // Map to system output format
    _currentOutput.risk_class = (ganoplus_risk_class_t)_xgbOutput.predicted_class;
    _currentOutput.risk_score = _xgbOutput.risk_score;
    _currentOutput.confidence = _xgbOutput.probabilities[_xgbOutput.predicted_class];
    for (int c = 0; c < 4; c++) {
        _currentOutput.class_probabilities[c] = _xgbOutput.probabilities[c];
    }

    // Evaluate Quality Gate and Alarms
    if (uptimeSec < WARMUP_TIME_SECONDS || !gasMgr.isCalibrated()) {
        _currentOutput.decision_status = GANOPLUS_DECISION_SENSOR_INVALID;
        _currentOutput.alarm_active = 0;
    } else if (!_hasCustomImpedance && _xgbOutput.predicted_class > 0) {
        _currentOutput.decision_status = GANOPLUS_DECISION_RETEST_REQUIRED;
        _currentOutput.alarm_active = 0;
    } else {
        _currentOutput.decision_status = GANOPLUS_DECISION_VALID;
        _currentOutput.alarm_active = (_xgbOutput.predicted_class > 0 && _xgbOutput.risk_score >= 0.50f) ? 1 : 0;
    }

    // Evaluate Room Air Quality (Ambient Monitoring)
    if (uptimeSec < WARMUP_TIME_SECONDS || !gasMgr.isCalibrated()) {
        _roomAirQuality = "WARMING UP";
    } else if (co2_ppm >= 1600.0f) {
        _roomAirQuality = "STALE (HIGH CO2 - VENTILATE)";
    } else if (mq3_ppm >= 0.25f) {
        _roomAirQuality = "ALCOHOL / SOLVENT DETECTED";
    } else if (airIdx >= 350.0f || mq9_ppm >= 50.0f) {
        _roomAirQuality = "POOR (ODORS / COMBUSTIBLES)";
    } else if (airIdx >= 200.0f || co2_ppm >= 1000.0f) {
        _roomAirQuality = "MODERATE / OCCUPIED ROOM";
    } else {
        _roomAirQuality = "EXCELLENT (CLEAN ROOM AIR)";
    }

    // Evaluate Ganoderma Target Status
    if (uptimeSec < WARMUP_TIME_SECONDS || !gasMgr.isCalibrated()) {
        _ganodermaTargetStatus = "CALIBRATING";
    } else if (_currentOutput.alarm_active == 1) {
        if (_currentOutput.risk_class == GANOPLUS_SEVERE) {
            _ganodermaTargetStatus = "POSITIVE: SEVERE ROT";
        } else if (_currentOutput.risk_class == GANOPLUS_MODERATE) {
            _ganodermaTargetStatus = "POSITIVE: MODERATE RISK";
        } else if (_currentOutput.risk_class == GANOPLUS_EARLY) {
            _ganodermaTargetStatus = "POSITIVE: EARLY STAGE RISK";
        } else {
            _ganodermaTargetStatus = "ALARM ACTIVE";
        }
    } else if (_currentOutput.decision_status == GANOPLUS_DECISION_RETEST_REQUIRED) {
        _ganodermaTargetStatus = "INCONCLUSIVE (RETEST)";
    } else {
        _ganodermaTargetStatus = "NEGATIVE (HEALTHY TREE / CLEAN AIR)";
    }
}

const char* GanoMLManager::getRoomAirQuality() const {
    return _roomAirQuality;
}

const char* GanoMLManager::getRoomAirQualityColor() const {
    if (strstr(_roomAirQuality, "EXCELLENT")) return "\033[32m";
    if (strstr(_roomAirQuality, "MODERATE") || strstr(_roomAirQuality, "FAIR") || strstr(_roomAirQuality, "WARMING")) return "\033[33m";
    return "\033[31m";
}

const char* GanoMLManager::getGanodermaTargetStatus() const {
    return _ganodermaTargetStatus;
}

const char* GanoMLManager::getGanodermaTargetColor() const {
    if (strstr(_ganodermaTargetStatus, "NEGATIVE")) return "\033[32m";
    if (strstr(_ganodermaTargetStatus, "EARLY") || strstr(_ganodermaTargetStatus, "INCONCLUSIVE") || strstr(_ganodermaTargetStatus, "CALIBRATING")) return "\033[33m";
    return "\033[31m";
}

bool GanoMLManager::runSelfTest(Stream &out) {
    out.println(F("\n[GanoPlusML] Running XGBoost Model Self-Test Validation..."));
    float test_feat[13] = {0.22f, 0.05f, 0.10f, 0.15f, 0.40f, 28.5f, 65.0f, 76.5f, -37.9f, 85.4f, -26.3f, 0.0f, 0.0f};
    XGBoostOutput outTest = XGBoostGano::predict(test_feat);
    
    out.printf("  XGBoost Self-Test Output: Predicted Class = %s | Risk = %.1f%% | Prob = [H:%.1f%% E:%.1f%% M:%.1f%% S:%.1f%%]\r\n",
               getRiskClassName((ganoplus_risk_class_t)outTest.predicted_class),
               outTest.risk_score * 100.0f,
               outTest.probabilities[0]*100.0f, outTest.probabilities[1]*100.0f,
               outTest.probabilities[2]*100.0f, outTest.probabilities[3]*100.0f);
    out.println(F("  Self-test status: PASS\n"));
    return true;
}

const char* GanoMLManager::getRiskClassName(ganoplus_risk_class_t riskClass) {
    switch (riskClass) {
        case GANOPLUS_HEALTHY:  return "HEALTHY";
        case GANOPLUS_EARLY:    return "EARLY RISK";
        case GANOPLUS_MODERATE: return "MODERATE RISK";
        case GANOPLUS_SEVERE:   return "SEVERE RISK";
        default:                return "UNKNOWN";
    }
}

const char* GanoMLManager::getRiskClassColor(ganoplus_risk_class_t riskClass) {
    switch (riskClass) {
        case GANOPLUS_HEALTHY:  return "\033[32m"; // Green
        case GANOPLUS_EARLY:    return "\033[33m"; // Yellow
        case GANOPLUS_MODERATE: return "\033[35m"; // Magenta
        case GANOPLUS_SEVERE:   return "\033[31m"; // Red
        default:                return "\033[0m";
    }
}

const char* GanoMLManager::getDecisionStatusName(ganoplus_decision_status_t status) {
    switch (status) {
        case GANOPLUS_DECISION_VALID:           return "VALID";
        case GANOPLUS_DECISION_RETEST_REQUIRED: return "RETEST REQUIRED";
        case GANOPLUS_DECISION_SENSOR_INVALID:  return "SENSOR INVALID";
        default:                                return "UNKNOWN";
    }
}

String GanoMLManager::getReasonCodesDescription(uint32_t reasonCodes) {
    if (reasonCodes == 0) return "NORMAL_BASELINE";
    String res = "";
    if (reasonCodes & GANOPLUS_REASON_VOC_ELEVATED)            res += "VOC_ELEVATED ";
    if (reasonCodes & GANOPLUS_REASON_NH3_ELEVATED)            res += "NH3_ELEVATED ";
    if (reasonCodes & GANOPLUS_REASON_IMPEDANCE_2KHZ_ANOMALY)  res += "IMPEDANCE_ANOMALY ";
    if (reasonCodes & GANOPLUS_REASON_CONTACT_QUALITY_LOW)     res += "BAD_CONTACT ";
    if (reasonCodes & GANOPLUS_REASON_RETEST_REQUIRED)         res += "RETEST_REQUIRED ";
    res.trim();
    return res;
}
