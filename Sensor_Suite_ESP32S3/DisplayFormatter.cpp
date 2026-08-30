#include "DisplayFormatter.h"
#include "XGBoostGano.h"

#define ANSI_RESET    "\033[0m"
#define ANSI_BOLD     "\033[1m"
#define ANSI_RED      "\033[31m"
#define ANSI_GREEN    "\033[32m"
#define ANSI_YELLOW   "\033[33m"
#define ANSI_BLUE     "\033[34m"
#define ANSI_MAGENTA  "\033[35m"
#define ANSI_CYAN     "\033[36m"

static const uint8_t PROBE_PINS[] = {1, 2, 5, 7, 9, 10};
static const uint8_t NUM_PROBE_PINS = sizeof(PROBE_PINS) / sizeof(PROBE_PINS[0]);

static const uint8_t ALL_ADC_PINS[] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
static const uint8_t NUM_ALL_ADC_PINS = sizeof(ALL_ADC_PINS) / sizeof(ALL_ADC_PINS[0]);

DisplayFormatter::DisplayFormatter(GasSensorManager &gasMgr, DHTManager &dhtMgr, GanoMLManager &mlMgr, ImpedanceProbe &impProbe)
    : _gasMgr(gasMgr), _dhtMgr(dhtMgr), _mlMgr(mlMgr), _impProbe(impProbe), _currentMode(DEFAULT_OUTPUT_MODE), _inputBuffer("") {
}

void DisplayFormatter::begin() {
    _inputBuffer.reserve(64);
}

void DisplayFormatter::printWelcomeHeader() {
    Serial.println(F("ESP32-S3 Multi-Modal Gas & Bio-Impedance GanoPlusML Suite"));
    Serial.println(F("Sensors   : TGS 2600, MQ-3, MQ-4, MQ-9, MQ-135, DHT22"));
    Serial.println(F("Impedance : LM358 100x Front-End (2 kHz AC Excitation)"));
    Serial.println(F("ML Model  : GanoPlus Edge v1 (Distilled Logistic Regression)"));
    Serial.println(F("Type 'help' for available commands.\n"));
    printPinMapping();
}

void DisplayFormatter::printPinMapping() {
    const GasReading *r = _gasMgr.getAllReadings();
    Serial.println(F("Pin Assignments:"));
    for (int i = 0; i < GAS_COUNT; i++) {
        Serial.printf("  %-8s : GPIO %d (%s)\r\n", r[i].name, r[i].pin, r[i].targetGas);
    }
    Serial.printf("  DHT22    : GPIO %d (Temperature & Humidity)\r\n", PIN_DHT22);
    Serial.printf("  EIS TX   : GPIO %d (2 kHz Excitation Output)\r\n", PIN_IMPEDANCE_TX);
    Serial.printf("  EIS RX   : GPIO %d (LM358 OUT -> ADC2_CH1)\r\n\n", PIN_IMPEDANCE_RX);
}

void DisplayFormatter::printHelp() {
    Serial.println(F("\nCommands:"));
    Serial.println(F("  help           - Show available commands"));
    Serial.println(F("  ml             - Detailed Machine Learning feature breakdown & diagnosis"));
    Serial.println(F("  ml selftest    - Run GanoPlusML golden vector validation test"));
    Serial.println(F("  baseline       - Capture current readings as tree reference baseline"));
    Serial.println(F("  reset baseline - Reset tree reference baseline to default"));
    Serial.println(F("  fert on / off  - Toggle recent fertilizer flag (affects NH3 interpretation)"));
    Serial.println(F("  cal            - Recalibrate clean-air baseline resistances"));
    Serial.println(F("  auto or wizard - Interactive stimulus wizard to detect sensor pins"));
    Serial.println(F("  scan           - Scan all ESP32-S3 ADC pins (1..18) for active signals"));
    Serial.println(F("  probe          - Show live voltages on active pins"));
    Serial.println(F("  mode dashboard - Terminal table"));
    Serial.println(F("  mode json      - JSON stream format"));
    Serial.println(F("  mode plotter   - Arduino Serial Plotter format"));
    Serial.println(F("  pins           - Display current pin mappings"));
    Serial.println(F("  r0             - Display current R0 baseline resistances\n"));
}

void DisplayFormatter::printR0Baselines() {
    const GasReading *r = _gasMgr.getAllReadings();
    Serial.println(F("\nR0 Baselines (kOhm):"));
    for (int i = 0; i < GAS_COUNT; i++) {
        Serial.printf("  %-8s (GPIO %2d) : %6.2f kOhm (%s)\r\n", r[i].name, r[i].pin, r[i].r0_kohm, r[i].targetGas);
    }
    Serial.println();
}

void DisplayFormatter::printMLReport() {
    const ganoplus_edge_input_t &in = _mlMgr.getInput();
    const ganoplus_edge_output_t &out = _mlMgr.getOutput();
    const GanoTreeBaseline &base = _mlMgr.getBaseline();

    Serial.println(F("\n[GANOPLUS ML EDGE DIAGNOSIS REPORT]"));

    const char *color = GanoMLManager::getRiskClassColor(out.risk_class);
    Serial.printf("  Disease Stage     : %s%s%s\r\n", color, GanoMLManager::getRiskClassName(out.risk_class), ANSI_RESET);
    Serial.printf("  Risk Score        : %.2f %% (Raw: %.4f)\r\n", out.risk_score * 100.0f, out.risk_score);
    Serial.printf("  Confidence        : %.2f %%\r\n", out.confidence * 100.0f);
    Serial.printf("  Alarm Triggered   : %s\r\n", out.alarm_active ? ANSI_RED "YES (ACTIVE ALARM)" ANSI_RESET : ANSI_GREEN "NO (NORMAL)" ANSI_RESET);
    Serial.printf("  Quality Status    : %s\r\n", GanoMLManager::getDecisionStatusName(out.decision_status));
    Serial.printf("  Quality Score     : %.2f\r\n", out.measurement_quality);
    Serial.printf("  Reason Codes      : %s (0x%04lX)\r\n", GanoMLManager::getReasonCodesDescription(out.reason_codes).c_str(), (unsigned long)out.reason_codes);
    Serial.printf("  Fertilizer Flag   : %s\r\n", _mlMgr.getFertilizerRecent() ? "YES" : "NO");
    Serial.printf("  Tree Baseline Set : %s\r\n", base.is_set ? "YES" : "NO (Using Defaults)");

    Serial.println(F("\n  [Class Probabilities]:"));
    Serial.printf("    Healthy  : %5.1f %%\r\n", out.class_probabilities[GANOPLUS_HEALTHY] * 100.0f);
    Serial.printf("    Early    : %5.1f %%\r\n", out.class_probabilities[GANOPLUS_EARLY] * 100.0f);
    Serial.printf("    Moderate : %5.1f %%\r\n", out.class_probabilities[GANOPLUS_MODERATE] * 100.0f);
    Serial.printf("    Severe   : %5.1f %%\r\n", out.class_probabilities[GANOPLUS_SEVERE] * 100.0f);

    Serial.println(F("\n  [17 Feature Vector Inputs]:"));
    Serial.printf("    0: voc_aromatic_proxy   = %.4f\r\n", in.features[0]);
    Serial.printf("    1: nh3_ppm              = %.4f ppm\r\n", in.features[1]);
    Serial.printf("    2: voc_index_corrected  = %.4f\r\n", in.features[2]);
    Serial.printf("    3: voc_sulfur_proxy     = %.4f\r\n", in.features[3]);
    Serial.printf("    4: fertilizer_recent    = %.1f\r\n", in.features[4]);
    Serial.printf("    5: x_2khz_ohm           = %.2f ohm\r\n", in.features[5]);
    Serial.printf("    6: r_2khz_ohm           = %.2f ohm\r\n", in.features[6]);
    Serial.printf("    7: co2_ppm              = %.1f ppm\r\n", in.features[7]);
    Serial.printf("    8: measurement_quality  = %.2f\r\n", in.features[8]);
    Serial.printf("    9: electrode_contact    = %.2f\r\n", in.features[9]);
    Serial.printf("   10: voc_valid            = %.1f\r\n", in.features[10]);
    Serial.printf("   11: impedance_valid      = %.1f\r\n", in.features[11]);
    Serial.printf("   12: voc_index_delta      = %+.4f\r\n", in.features[12]);
    Serial.printf("   13: nh3_ppm_delta        = %+.4f ppm\r\n", in.features[13]);
    Serial.printf("   14: reactance_abs_delta  = %+.2f ohm\r\n", in.features[14]);
    Serial.printf("   15: reactance_pct_drop   = %+.4f\r\n", in.features[15]);
    Serial.printf("   16: r_temp_diam_pct_drop = %+.4f\r\n", in.features[16]);
    Serial.println(F("========================================================\n"));
}

void DisplayFormatter::scanAllPins() {
    Serial.println(F("\n[ESP32-S3 FULL ADC PIN SCAN]"));
    Serial.println(F("Scanning analog channels for connected signals..."));
    
    int activeCount = 0;
    for (int i = 0; i < NUM_ALL_ADC_PINS; i++) {
        uint8_t pin = ALL_ADC_PINS[i];
        if (pin == PIN_DHT22) continue;

        uint16_t raw = 0;
        float mv = _gasMgr.readFilteredMilliVolts(pin, raw);
        
        const char *indicator = "";
        if (mv > 20.0f) {
            indicator = " <-- ACTIVE SIGNAL DETECTED";
            activeCount++;
        }
        Serial.printf("  GPIO %-2d : %5u ADC | %6.1f mV%s\r\n", pin, raw, mv, indicator);
    }
    Serial.printf("Total active analog signals found: %d\r\n\n", activeCount);
}

void DisplayFormatter::runAutoDetectWizard() {
    Serial.println(F("\nSensor Pin Detection Wizard"));
    Serial.println(F("Detects which sensor is on which GPIO pin by measuring delta-V during exposure.\n"));

    struct TargetSensor {
        GasSensorType type;
        const char* name;
        const char* stimulusInstruction;
    };

    TargetSensor targets[] = {
        {GAS_MQ3,     "MQ-3",     "Bring alcohol or hand sanitizer near MQ-3"},
        {GAS_MQ4,     "MQ-4",     "Release a small amount of lighter gas near MQ-4"},
        {GAS_MQ9,     "MQ-9",     "Expose MQ-9 to flammable gas or CO"},
        {GAS_MQ135,   "MQ-135",   "Breathe directly onto MQ-135 or expose to room contaminant"},
        {GAS_TGS2600, "TGS 2600", "Expose TGS 2600 to air contaminants"}
    };

    for (size_t t = 0; t < 5; t++) {
        Serial.printf("\n[%d/5] Detecting %s:\r\n", (int)(t + 1), targets[t].name);
        Serial.printf("Action: %s\r\n", targets[t].stimulusInstruction);
        Serial.println(F("Waiting up to 15 seconds for voltage delta..."));

        float baselines[NUM_PROBE_PINS];
        for (int p = 0; p < NUM_PROBE_PINS; p++) {
            uint16_t r;
            baselines[p] = _gasMgr.readFilteredMilliVolts(PROBE_PINS[p], r);
        }

        uint8_t detectedPin = 255;
        float maxDelta = 0.0f;
        uint32_t startWait = millis();

        while (millis() - startWait < 15000) {
            for (int p = 0; p < NUM_PROBE_PINS; p++) {
                uint16_t r;
                float currentV = _gasMgr.readFilteredMilliVolts(PROBE_PINS[p], r);
                float delta = currentV - baselines[p];

                if (delta > 80.0f && delta > maxDelta) {
                    maxDelta = delta;
                    detectedPin = PROBE_PINS[p];
                }
            }

            if (detectedPin != 255 && maxDelta > 150.0f) {
                break;
            }

            delay(200);
            if (Serial.available() > 0 && Serial.peek() == 's') {
                Serial.read();
                Serial.println(F("Skipped by user."));
                break;
            }
        }

        if (detectedPin != 255) {
            _gasMgr.setSensorPin(targets[t].type, detectedPin);
            Serial.printf("Match found: %s is on GPIO %d (+%.1f mV delta)\r\n",
                          targets[t].name, detectedPin, maxDelta);
        } else {
            Serial.printf("No delta detected for %s (retaining current pin).\r\n", targets[t].name);
        }
        delay(1000);
    }

    Serial.println(F("\nAuto-detection finished."));
    printPinMapping();
    Serial.println(F("Recalibrating baselines on newly assigned pins..."));
    _gasMgr.calibrate(CALIBRATION_SAMPLES);
}

void DisplayFormatter::printOutput(OutputMode mode, uint32_t uptimeSeconds) {
    switch (mode) {
        case OUTPUT_MODE_DASHBOARD:
            printDashboard(uptimeSeconds);
            break;
        case OUTPUT_MODE_JSON:
            printJson(uptimeSeconds);
            break;
        case OUTPUT_MODE_PLOTTER:
            printPlotter();
            break;
        case OUTPUT_MODE_PROBE:
            printProbe();
            break;
    }
}

void DisplayFormatter::printProbe() {
    Serial.println(F("\n[PIN PROBE - RAW LIVE ADC & VOLTAGES]"));
    Serial.println(F("  GPIO PIN | RAW ADC (0-4095) | VOLTAGE (mV)"));
    for (int i = 0; i < NUM_PROBE_PINS; i++) {
        uint8_t pin = PROBE_PINS[i];
        uint16_t raw = 0;
        float mv = _gasMgr.readFilteredMilliVolts(pin, raw);
        Serial.printf("   GPIO %-2d |     %5u        |   %6.1f mV\r\n", pin, raw, mv);
    }
    Serial.println();
}

void DisplayFormatter::printDashboard(uint32_t uptimeSeconds) {
    const GasReading *g = _gasMgr.getAllReadings();
    const DHTReading &d = _dhtMgr.getReading();
    const ganoplus_edge_output_t &ml = _mlMgr.getOutput();

    uint32_t hrs = uptimeSeconds / 3600;
    uint32_t mins = (uptimeSeconds % 3600) / 60;
    uint32_t secs = uptimeSeconds % 60;

    Serial.printf(ANSI_BOLD "[DASHBOARD] Uptime: %02u:%02u:%02u | Calibrated: %s" ANSI_RESET "\r\n",
                  hrs, mins, secs, _gasMgr.isCalibrated() ? ANSI_GREEN "YES" ANSI_RESET : ANSI_YELLOW "NO (WARMING UP)" ANSI_RESET);
    
    if (d.isValid) {
        Serial.printf("  [DHT22 - GPIO %d] Temp: %.1f C (%.1f F) | Hum: %.1f %% | HeatIdx: %.1f C | DewPt: %.1f C\r\n",
                      PIN_DHT22, d.temperatureC, d.temperatureF, d.humidity, d.heatIndexC, d.dewPointC);
    } else {
        Serial.printf("  [DHT22 - GPIO %d] Status: %s\r\n", PIN_DHT22, d.errorMsg);
    }

    Serial.println(F("  SENSOR   | PIN | RAW ADC | VOLT (mV) | Rs (kOhm) | R0 (kOhm) | Rs/R0 | VALUE / PPM | STATUS"));

    for (int i = 0; i < GAS_COUNT; i++) {
        const char *statusColor = ANSI_GREEN;
        if (strstr(g[i].status, "WARMING") || strstr(g[i].status, "MODERATE") || strstr(g[i].status, "LOW") || strstr(g[i].status, "VENTILATE") || strstr(g[i].status, "ELEVATED")) {
            statusColor = ANSI_YELLOW;
        } else if (strstr(g[i].status, "DANGER") || strstr(g[i].status, "ALERT") || strstr(g[i].status, "HAZARDOUS") || strstr(g[i].status, "POOR") || strstr(g[i].status, "WARNING")) {
            statusColor = ANSI_RED;
        }

        Serial.printf("  %-8s | %3d |  %5u  |   %6.1f  |  %7.2f  |  %7.2f  | %5.2f | %7.2f %-4s | %s%s" ANSI_RESET "\r\n",
                      g[i].name,
                      g[i].pin,
                      g[i].rawADC,
                      g[i].voltageMV,
                      g[i].rs_kohm,
                      g[i].r0_kohm,
                      g[i].ratio,
                      g[i].ppm,
                      g[i].unit,
                      statusColor,
                      g[i].status);
    }

    // Dual Assessment Banner: Room Air Quality & Ganoderma Screening
    const char *roomColor = _mlMgr.getRoomAirQualityColor();
    const char *ganoColor = _mlMgr.getGanodermaTargetColor();
    const char *riskColor = GanoMLManager::getRiskClassColor(ml.risk_class);
    const ImpedanceReading &imp = _impProbe.getReading();
    const char *impColor = imp.is_connected ? (imp.contact_quality > 0.80f ? ANSI_GREEN : ANSI_YELLOW) : ANSI_CYAN;

    Serial.println(F("  --------------------------------------------------------------------------------------------"));
    Serial.printf("  [BIO-IMPEDANCE 2kHz] : %s%-32s" ANSI_RESET " | Z: %5.1f Ohm | R: %5.1f Ohm | X: %5.1f Ohm (Vpp: %.0fmV)\r\n",
                  impColor,
                  imp.status,
                  imp.z_ohm,
                  imp.r_ohm,
                  imp.x_ohm,
                  imp.vpp_mv);
    Serial.printf("  [ROOM AIR QUALITY]   : %s%-32s" ANSI_RESET " | CO2: %4.0f ppm | NH3: %.2f ppm\r\n",
                  roomColor,
                  _mlMgr.getRoomAirQuality(),
                  _gasMgr.getCO2PPM(),
                  _gasMgr.getNH3PPM());

    Serial.printf("  [GANODERMA TARGET]   : %s%-32s" ANSI_RESET " | Stage: %s%-13s" ANSI_RESET " | Risk: %5.1f %%\r\n",
                  ganoColor,
                  _mlMgr.getGanodermaTargetStatus(),
                  riskColor,
                  GanoMLManager::getRiskClassName(ml.risk_class),
                  ml.risk_score * 100.0f);

    Serial.printf("                         Alarm: %s%-12s" ANSI_RESET " | Conf: %4.1f%% | Prob: [H:%2.0f%% E:%2.0f%% M:%2.0f%% S:%2.0f%%]\r\n",
                  ml.alarm_active ? ANSI_RED : ANSI_GREEN,
                  ml.alarm_active ? "ACTIVE ALARM" : "NORMAL",
                  ml.confidence * 100.0f,
                  ml.class_probabilities[GANOPLUS_HEALTHY] * 100.0f,
                  ml.class_probabilities[GANOPLUS_EARLY] * 100.0f,
                  ml.class_probabilities[GANOPLUS_MODERATE] * 100.0f,
                  ml.class_probabilities[GANOPLUS_SEVERE] * 100.0f);
    
    Serial.printf("                         Diagnosis Reasons: %s\r\n",
                  GanoMLManager::getReasonCodesDescription(ml.reason_codes).c_str());
    Serial.println(F("  --------------------------------------------------------------------------------------------"));

    Serial.print(F("  [PIN PROBE (mV)]: "));
    for (int p = 0; p < NUM_PROBE_PINS; p++) {
        uint16_t r;
        float v = _gasMgr.readFilteredMilliVolts(PROBE_PINS[p], r);
        Serial.printf("GPIO%d: %.0fmV  ", PROBE_PINS[p], v);
    }
    uint16_t r12;
    float v12 = _gasMgr.readFilteredMilliVolts(PIN_IMPEDANCE_RX, r12);
    Serial.printf("GPIO%d (LM358): %.0fmV\r\n\n", PIN_IMPEDANCE_RX, v12);
}

void DisplayFormatter::printJson(uint32_t uptimeSeconds) {
    const GasReading *g = _gasMgr.getAllReadings();
    const DHTReading &d = _dhtMgr.getReading();
    const ganoplus_edge_output_t &ml = _mlMgr.getOutput();
    const ganoplus_edge_input_t &in = _mlMgr.getInput();
    const GanoTreeBaseline &base = _mlMgr.getBaseline();

    Serial.print(F("{\"uptime\":"));
    Serial.print(uptimeSeconds);
    Serial.print(F(",\"calibrated\":"));
    Serial.print(_gasMgr.isCalibrated() ? "true" : "false");
    
    Serial.print(F(",\"climate\":{"));
    if (d.isValid) {
        Serial.printf("\"temp_c\":%.2f,\"temp_f\":%.2f,\"humidity\":%.2f,\"heat_index\":%.2f,\"dew_point\":%.2f,\"valid\":true",
                      d.temperatureC, d.temperatureF, d.humidity, d.heatIndexC, d.dewPointC);
    } else {
        Serial.print(F("\"valid\":false"));
    }
    Serial.print(F("},\"sensors\":{"));

    for (int i = 0; i < GAS_COUNT; i++) {
        if (i > 0) Serial.print(F(","));
        
        String key = g[i].name;
        key.toLowerCase();
        key.replace(" ", "_");
        key.replace("-", "");

        Serial.printf("\"%s\":{\"pin\":%d,\"raw\":%u,\"mv\":%.1f,\"rs\":%.2f,\"r0\":%.2f,\"ratio\":%.2f,\"ppm\":%.2f,\"status\":\"%s\"}",
                      key.c_str(), g[i].pin, g[i].rawADC, g[i].voltageMV, g[i].rs_kohm, g[i].r0_kohm, g[i].ratio, g[i].ppm, g[i].status);
    }
    Serial.print(F("},\"room_air\":{"));
    Serial.printf("\"quality\":\"%s\",\"co2_ppm\":%.1f,\"nh3_ppm\":%.2f",
                  _mlMgr.getRoomAirQuality(), _gasMgr.getCO2PPM(), _gasMgr.getNH3PPM());

    Serial.print(F("},\"ml\":{"));
    Serial.printf("\"ganoderma_status\":\"%s\",\"risk_class\":\"%s\",\"risk_score\":%.4f,\"confidence\":%.4f,\"alarm_active\":%s,\"decision_status\":\"%s\",\"reasons\":\"%s\",\"fertilizer_flag\":%s,\"baseline_set\":%s,",
                  _mlMgr.getGanodermaTargetStatus(),
                  GanoMLManager::getRiskClassName(ml.risk_class),
                  ml.risk_score,
                  ml.confidence,
                  ml.alarm_active ? "true" : "false",
                  GanoMLManager::getDecisionStatusName(ml.decision_status),
                  GanoMLManager::getReasonCodesDescription(ml.reason_codes).c_str(),
                  _mlMgr.getFertilizerRecent() ? "true" : "false",
                  base.is_set ? "true" : "false");
    Serial.printf("\"probabilities\":{\"healthy\":%.4f,\"early\":%.4f,\"moderate\":%.4f,\"severe\":%.4f},",
                  ml.class_probabilities[GANOPLUS_HEALTHY],
                  ml.class_probabilities[GANOPLUS_EARLY],
                  ml.class_probabilities[GANOPLUS_MODERATE],
                  ml.class_probabilities[GANOPLUS_SEVERE]);
    Serial.printf("\"features\":{\"voc_index_corrected\":%.4f,\"nh3_ppm\":%.4f,\"co2_ppm\":%.1f,\"aromatic_proxy\":%.4f,\"sulfur_proxy\":%.4f,\"quality_score\":%.2f}",
                  in.features[2], in.features[1], in.features[7], in.features[0], in.features[3], in.features[8]);

    Serial.print(F("},\"pins\":{"));
    for (int p = 0; p < NUM_PROBE_PINS; p++) {
        if (p > 0) Serial.print(F(","));
        uint16_t r;
        float v = _gasMgr.readFilteredMilliVolts(PROBE_PINS[p], r);
        Serial.printf("\"gpio%d\":%.1f", PROBE_PINS[p], v);
    }
    Serial.println(F("}}"));
}

void DisplayFormatter::printPlotter() {
    const GasReading *g = _gasMgr.getAllReadings();
    const DHTReading &d = _dhtMgr.getReading();
    const ganoplus_edge_output_t &ml = _mlMgr.getOutput();

    Serial.printf("TGS2600_Idx:%.2f,MQ3_Alc:%.2f,MQ4_CH4:%.2f,MQ9_CO:%.2f,MQ135_CO2:%.2f,MQ135_NH3:%.2f,RiskPct:%.2f",
                  g[GAS_TGS2600].ppm,
                  g[GAS_MQ3].ppm,
                  g[GAS_MQ4].ppm,
                  g[GAS_MQ9].ppm,
                  _gasMgr.getCO2PPM(),
                  _gasMgr.getNH3PPM(),
                  ml.risk_score * 100.0f);

    if (d.isValid) {
        Serial.printf(",TempC:%.2f,Humidity:%.2f", d.temperatureC, d.humidity);
    }
    Serial.println();
}

void DisplayFormatter::processSerialCommands() {
    while (Serial.available() > 0) {
        char c = (char)Serial.read();
        if (c == '\r' || c == '\n') {
            if (_inputBuffer.length() > 0) {
                _inputBuffer.trim();
                handleCommand(_inputBuffer);
                _inputBuffer = "";
            }
        } else {
            _inputBuffer += c;
        }
    }
}

void DisplayFormatter::handleCommand(const String &cmd) {
    String lower = cmd;
    lower.toLowerCase();

    if (lower == "h" || lower == "help") {
        printHelp();
    } else if (lower == "ml") {
        printMLReport();
    } else if (lower == "ml selftest" || lower == "selftest") {
        _mlMgr.runSelfTest(Serial);
    } else if (lower == "baseline") {
        _mlMgr.captureBaseline(_gasMgr, _dhtMgr);
        Serial.println(F("\n[GANOPLUS] Tree reference baseline stored."));
        printMLReport();
    } else if (lower == "reset baseline") {
        _mlMgr.resetBaseline();
        Serial.println(F("\n[GANOPLUS] Baseline reset to defaults."));
    } else if (lower.startsWith("fert")) {
        bool on = lower.indexOf("on") >= 0;
        _mlMgr.setFertilizerRecent(on);
        Serial.printf("\n[GANOPLUS] Fertilizer compensation: %s\r\n", on ? "ENABLED" : "DISABLED");
    } else if (lower == "auto" || lower == "wizard") {
        runAutoDetectWizard();
    } else if (lower == "scan") {
        scanAllPins();
    } else if (lower == "i2c" || lower == "scan_i2c") {
        Serial.println(F("\n[I2C BUS SCANNER]"));
        Serial.printf("Current Pins -> SDA: GPIO %d, SCL: GPIO %d\r\n", PIN_OLED_SDA, PIN_OLED_SCL);
        Wire.begin(PIN_OLED_SDA, PIN_OLED_SCL, 100000);
        delay(50);
        int devices = 0;
        for (uint8_t addr = 1; addr < 127; addr++) {
            Wire.beginTransmission(addr);
            if (Wire.endTransmission() == 0) {
                Serial.printf("  -> Found I2C Device at 0x%02X\r\n", addr);
                devices++;
            }
        }
        Serial.printf("Total I2C devices found: %d\r\n\n", devices);
    } else if (lower == "xgb" || lower == "benchmark" || lower == "speed") {
        Serial.println(F("\n[BENCHMARK] Menjalankan 1.000 Iterasi Inferensi XGBoost di ESP32-S3..."));
        float dummy_feat[13] = {0.22f, 0.05f, 0.10f, 0.15f, 0.40f, 28.5f, 65.0f, 76.5f, -37.9f, 85.4f, -26.3f, 0.0f, 0.0f};
        
        // Ukur kecepatan eksekusi 35 decision tree XGBoost
        int64_t t1 = esp_timer_get_time();
        XGBoostOutput out_xgb;
        for (int i = 0; i < 1000; i++) {
            dummy_feat[0] = 0.22f + (i * 0.0001f);
            out_xgb = XGBoostGano::predict(dummy_feat);
        }
        int64_t t_xgb = esp_timer_get_time() - t1;

        Serial.printf("  XGBoost Ensemble (35 Trees): Total = %lld us | Latensi = %.3f us/inferensi (%.4f ms)\r\n", 
                      t_xgb, (float)t_xgb / 1000.0f, (float)t_xgb / 1000000.0f);
        Serial.printf("  Hasil Uji Prediksi : Kelas = %d | Risiko = %.1f%% | Prob = [H:%.1f%% E:%.1f%% M:%.1f%% S:%.1f%%]\r\n\n",
                      out_xgb.predicted_class, out_xgb.risk_score * 100.0f,
                      out_xgb.probabilities[0]*100.0f, out_xgb.probabilities[1]*100.0f,
                      out_xgb.probabilities[2]*100.0f, out_xgb.probabilities[3]*100.0f);
    } else if (lower == "probe") {
        printProbe();
    } else if (lower == "pins") {
        printPinMapping();
    } else if (lower == "r0") {
        printR0Baselines();
    } else if (lower.startsWith("mode")) {
        if (lower.indexOf("dash") >= 0 || lower.endsWith("0")) {
            _currentMode = OUTPUT_MODE_DASHBOARD;
            Serial.println(F("Switched to dashboard mode."));
        } else if (lower.indexOf("json") >= 0 || lower.endsWith("1")) {
            _currentMode = OUTPUT_MODE_JSON;
            Serial.println(F("Switched to JSON mode."));
        } else if (lower.indexOf("plot") >= 0 || lower.endsWith("2")) {
            _currentMode = OUTPUT_MODE_PLOTTER;
            Serial.println(F("Switched to plotter mode."));
        } else if (lower.indexOf("probe") >= 0 || lower.endsWith("3")) {
            _currentMode = OUTPUT_MODE_PROBE;
            Serial.println(F("Switched to probe mode."));
        } else {
            Serial.println(F("Valid modes: dashboard, json, plotter, probe."));
        }
    } else {
        Serial.printf("Unknown command: '%s'. Type 'help'.\r\n", cmd.c_str());
    }
}
