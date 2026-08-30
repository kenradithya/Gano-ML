#include "GasSensors.h"
#include <math.h>

struct SensorConfig {
    GasSensorType type;
    const char*   name;
    const char*   targetGas;
    const char*   unit;
    uint8_t       pin;
    float         rl_kohm;
    float         cleanAirRatio;
    float         defaultPpm;
};

static const SensorConfig SENSOR_DEFS[GAS_COUNT] = {
    { GAS_TGS2600, "TGS 2600", "Air Quality / Odor / H2", "AirIdx", PIN_TGS2600, RL_TGS2600_KOHM, CLEAN_AIR_RATIO_TGS2600, 100.0f },
    { GAS_MQ3,     "MQ-3",     "Alcohol / Ethanol Vapor",  "mg/L",   PIN_MQ3,     RL_MQ3_KOHM,     CLEAN_AIR_RATIO_MQ3,     0.0f },
    { GAS_MQ4,     "MQ-4",     "Methane (CH4) / CNG",      "ppm",    PIN_MQ4,     RL_MQ4_KOHM,     CLEAN_AIR_RATIO_MQ4,     0.0f },
    { GAS_MQ9,     "MQ-9",     "Carbon Monoxide (CO)/LPG", "ppm",    PIN_MQ9,     RL_MQ9_KOHM,     CLEAN_AIR_RATIO_MQ9,     0.0f },
    { GAS_MQ135,   "MQ-135",   "Air Quality / CO2 / NH3",  "ppm",    PIN_MQ135,   RL_MQ135_KOHM,   CLEAN_AIR_RATIO_MQ135,   400.0f }
};

GasSensorManager::GasSensorManager() 
    : _emaInit(false), _calibrated(false), _warmingUp(true) {
    for (int i = 0; i < GAS_COUNT; i++) {
        _emaVoltages[i] = 0.0f;
        _loadResistors[i] = SENSOR_DEFS[i].rl_kohm;
        _cleanAirRatios[i] = SENSOR_DEFS[i].cleanAirRatio;

        _readings[i] = {
            SENSOR_DEFS[i].type,
            SENSOR_DEFS[i].name,
            SENSOR_DEFS[i].targetGas,
            SENSOR_DEFS[i].unit,
            SENSOR_DEFS[i].pin,
            0,
            0.0f,
            SENSOR_DEFS[i].rl_kohm,
            SENSOR_DEFS[i].rl_kohm,
            1.0f,
            SENSOR_DEFS[i].defaultPpm,
            "INIT",
            true
        };
    }
}

void GasSensorManager::begin() {
    analogReadResolution(12);
    #if defined(SOC_ADC_SUPPORTED) || defined(ESP32)
    analogSetAttenuation(ADC_11db);
    #endif

    for (int i = 0; i < GAS_COUNT; i++) {
        pinMode(_readings[i].pin, INPUT);
    }
}

void GasSensorManager::setSensorPin(GasSensorType type, uint8_t pin) {
    if (type >= 0 && type < GAS_COUNT) {
        _readings[type].pin = pin;
        pinMode(pin, INPUT);
        _emaInit = false;
    }
}

float GasSensorManager::readFilteredMilliVolts(uint8_t pin, uint16_t &outRawADC, uint16_t oversamples) {
    uint32_t adcSum = 0;
    uint32_t mvSum = 0;

    for (uint16_t i = 0; i < oversamples; i++) {
        adcSum += analogRead(pin);
        #if defined(ESP32)
        mvSum += analogReadMilliVolts(pin);
        #else
        mvSum += (uint32_t)((analogRead(pin) / ADC_MAX_VALUE) * BOARD_VCC_MV);
        #endif
        delayMicroseconds(100);
    }

    outRawADC = (uint16_t)(adcSum / oversamples);
    return (float)mvSum / (float)oversamples;
}

float GasSensorManager::calculateRs(float voltageMV, float rl_kohm) {
    float vc = BOARD_VCC_MV;
    if (voltageMV <= 50.0f) voltageMV = 50.0f;
    if (voltageMV >= (vc - 10.0f)) voltageMV = vc - 10.0f;
    float rs = rl_kohm * ((vc - voltageMV) / voltageMV);
    return (rs < 0.05f) ? 0.05f : rs;
}

float GasSensorManager::calculatePPM(GasSensorType type, float ratio) {
    if (ratio <= 0.001f) ratio = 0.001f;

    switch (type) {
        case GAS_TGS2600:
            return 100.0f / ratio;
        case GAS_MQ3: {
            float val = MQ3_A_ALCOHOL * powf(ratio, MQ3_B_ALCOHOL);
            return (val < 0.0f) ? 0.0f : (val > 10.0f ? 10.0f : val);
        }
        case GAS_MQ4: {
            float val = MQ4_A_CH4 * powf(ratio, MQ4_B_CH4);
            return (val < 0.0f) ? 0.0f : (val > 20000.0f ? 20000.0f : val);
        }
        case GAS_MQ9: {
            float val = MQ9_A_CO * powf(ratio, MQ9_B_CO);
            return (val < 0.0f) ? 0.0f : (val > 2000.0f ? 2000.0f : val);
        }
        case GAS_MQ135: {
            float val = MQ135_A_CO2 * powf(ratio, MQ135_B_CO2);
            if (val < 400.0f) val = 400.0f;
            return (val > 5000.0f ? 5000.0f : val);
        }
        default:
            return 0.0f;
    }
}

const char* GasSensorManager::evaluateStatus(GasSensorType type, float ratio, float ppm) {
    if (_warmingUp) return "WARMING UP";

    switch (type) {
        case GAS_TGS2600:
            if (ppm < 160.0f) return "CLEAN AIR";
            if (ppm < 300.0f) return "MODERATE";
            if (ppm < 600.0f) return "POOR QUALITY";
            return "HAZARDOUS";

        case GAS_MQ3:
            if (ppm < 0.05f) return "SOBER / NORMAL";
            if (ppm < 0.25f) return "LOW ALCOHOL";
            if (ppm < 0.50f) return "MEDIUM ALCOHOL";
            return "HIGH ALCOHOL (ALERT)";

        case GAS_MQ4:
            if (ppm < 500.0f)  return "NORMAL (SAFE)";
            if (ppm < 1200.0f) return "ELEVATED CH4";
            if (ppm < 3000.0f) return "GAS LEAK WARNING";
            return "DANGER: HIGH CH4";

        case GAS_MQ9:
            if (ppm < 30.0f)  return "SAFE (CLEAN)";
            if (ppm < 70.0f)  return "MODERATE CO";
            if (ppm < 150.0f) return "CO WARNING";
            return "DANGER: TOXIC CO";

        case GAS_MQ135:
            if (ppm < 800.0f)  return "EXCELLENT AIR";
            if (ppm < 1200.0f) return "GOOD AIR";
            if (ppm < 1800.0f) return "VENTILATE ROOM";
            return "POOR AIR QUALITY";

        default:
            return "OK";
    }
}

void GasSensorManager::calibrate(uint16_t samples) {
    Serial.println(F("\n[CALIBRATION] Starting clean air baseline R0 measurement..."));
    Serial.println(F("Sampling sensor baselines across 100 iterations..."));

    float rsSum[GAS_COUNT] = {0};

    for (uint16_t s = 0; s < samples; s++) {
        for (int i = 0; i < GAS_COUNT; i++) {
            uint16_t raw;
            float mv = readFilteredMilliVolts(_readings[i].pin, raw, ADC_OVERSAMPLES);
            rsSum[i] += calculateRs(mv, _loadResistors[i]);
        }
        if (s % 25 == 0 || s == samples - 1) {
            Serial.printf("  Progress: %d / %d samples...\r\n", s + 1, samples);
        }
        delay(20);
    }

    for (int i = 0; i < GAS_COUNT; i++) {
        float avgRs = rsSum[i] / (float)samples;
        float calculatedR0 = avgRs / _cleanAirRatios[i];
        if (calculatedR0 < 0.1f) calculatedR0 = 0.1f;
        _readings[i].r0_kohm = calculatedR0;
        
        Serial.printf("  %-8s (GPIO %2d) : Baseline R0 = %.2f kOhm (Avg Rs = %.2f kOhm)\r\n", 
                      _readings[i].name, _readings[i].pin, _readings[i].r0_kohm, avgRs);
    }

    _calibrated = true;
    _warmingUp = false;
    _emaInit = false;
    Serial.println(F("[CALIBRATION] Finished successfully.\n"));
}

void GasSensorManager::setR0(GasSensorType type, float r0_kohm) {
    if (type >= 0 && type < GAS_COUNT) {
        _readings[type].r0_kohm = (r0_kohm > 0.05f) ? r0_kohm : 0.05f;
    }
}

void GasSensorManager::update(float ambientTempC, float ambientHumidity) {
    for (int i = 0; i < GAS_COUNT; i++) {
        uint16_t raw;
        float rawMv = readFilteredMilliVolts(_readings[i].pin, raw, ADC_OVERSAMPLES);

        _emaVoltages[i] = _emaInit ? ((EMA_ALPHA * rawMv) + ((1.0f - EMA_ALPHA) * _emaVoltages[i])) : rawMv;

        float mv = _emaVoltages[i];
        float rs = calculateRs(mv, _loadResistors[i]);

        float tempHumFactor = 1.0f - 0.005f * (ambientTempC - 20.0f) - 0.002f * (ambientHumidity - 50.0f);
        if (tempHumFactor < 0.6f) tempHumFactor = 0.6f;
        if (tempHumFactor > 1.5f) tempHumFactor = 1.5f;

        float compensatedRs = rs / tempHumFactor;
        float r0 = _readings[i].r0_kohm <= 0.01f ? 10.0f : _readings[i].r0_kohm;

        // Pelacakan baseline adaptif berpagar (Gated Baseline Tracking):
        // R0 hanya diperbarui saat udara stabil dan bersih (rasio ~ 0.85 s.d. 1.25).
        // Begitu tercium gas Ganoderma (rasio anjlok < 0.85), R0 langsung DIKUNCI MATI
        // agar deteksi tetap tajam dan tidak tertelan sebagai udara normal.
        if (!_warmingUp && r0 > 0.1f) {
            float currentRatio = compensatedRs / r0;
            bool isCleanAir = (currentRatio >= 0.85f && currentRatio <= 1.30f);
            
            if (isCleanAir) {
                float targetR0 = compensatedRs / _cleanAirRatios[i];
                // Adaptasi halus R0 ke baseline panas ruangan
                _readings[i].r0_kohm = (0.002f * targetR0) + (0.998f * r0);
                r0 = _readings[i].r0_kohm;
            }
            // Jika ada gas (rasio < 0.85), R0 tetap terkunci (frozen)
        }

        float ratio = compensatedRs / r0;
        float ppm = calculatePPM((GasSensorType)i, ratio);

        _readings[i].rawADC      = raw;
        _readings[i].voltageMV   = mv;
        _readings[i].rs_kohm     = compensatedRs;
        _readings[i].ratio       = ratio;
        _readings[i].ppm         = ppm;
        _readings[i].isWarmingUp = _warmingUp;
        _readings[i].status      = evaluateStatus((GasSensorType)i, ratio, ppm);
    }
    _emaInit = true;
}

const GasReading& GasSensorManager::getReading(GasSensorType type) const {
    return _readings[type];
}

const GasReading* GasSensorManager::getAllReadings() const {
    return _readings;
}

float GasSensorManager::calculateNH3(float ratio) {
    if (ratio <= 0.01f) ratio = 0.01f;
    float normalizedRatio = ratio / CLEAN_AIR_RATIO_MQ135;
    if (normalizedRatio > 1.2f) normalizedRatio = 1.2f;
    float val = 0.20f * powf(normalizedRatio, -2.473f);
    if (val < 0.05f) val = 0.05f;
    if (val > 100.0f) val = 100.0f;
    return val;
}

float GasSensorManager::calculateCO2(float ratio) {
    if (ratio <= 0.01f) ratio = 0.01f;
    float normalizedRatio = ratio / CLEAN_AIR_RATIO_MQ135;
    if (normalizedRatio > 1.2f) normalizedRatio = 1.2f;
    float val = 415.0f * powf(normalizedRatio, -1.85f);
    if (val < 400.0f) val = 400.0f;
    if (val > 5000.0f) val = 5000.0f;
    return val;
}

float GasSensorManager::getNH3PPM() const {
    return calculateNH3(_readings[GAS_MQ135].ratio);
}

float GasSensorManager::getCO2PPM() const {
    return calculateCO2(_readings[GAS_MQ135].ratio);
}

float GasSensorManager::getTGS2600AirIndex() const {
    return _readings[GAS_TGS2600].ppm;
}

float GasSensorManager::getMQ3Alcohol() const {
    return _readings[GAS_MQ3].ppm;
}
