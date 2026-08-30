#include "OLEDDisplay.h"

OLEDDisplay::OLEDDisplay(uint8_t sdaPin, uint8_t sclPin)
    : _sdaPin(sdaPin),
      _sclPin(sclPin),
      _display(OLED_SCREEN_WIDTH, OLED_SCREEN_HEIGHT, &Wire, OLED_RESET_PIN),
      _isInitialized(false),
      _pageIndex(0),
      _lastPageSwitch(0) {
}

bool OLEDDisplay::begin() {
    Serial.printf("\n[OLED] Memindai bus I2C pada SDA: GPIO %d, SCL: GPIO %d (100 kHz)...\r\n", _sdaPin, _sclPin);
    
    // Aktifkan pull-up internal pada jalur I2C
    pinMode(_sdaPin, INPUT_PULLUP);
    pinMode(_sclPin, INPUT_PULLUP);
    delay(10);

    Wire.begin(_sdaPin, _sclPin, 100000); // Mode standar 100 kHz
    Wire.setTimeOut(25); // Batas waktu 25ms agar tidak freeze jika bus terputus
    delay(30);

    // 1. Pindai alamat I2C layar
    uint8_t foundAddr = 0;
    for (uint8_t addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
            Serial.printf("[OLED] Perangkat I2C ditemukan di alamat 0x%02X\r\n", addr);
            if (addr == 0x3C || addr == 0x3D) {
                foundAddr = addr;
            }
        }
    }

    // 2. Jika belum terdeteksi, uji apakah jalur SDA dan SCL tertukar
    if (foundAddr == 0) {
        Serial.println(F("[OLED] Belum merespons di pin (42/41). Menguji pin terbalik (41/42)..."));
        Wire.end();
        pinMode(_sclPin, INPUT_PULLUP);
        pinMode(_sdaPin, INPUT_PULLUP);
        delay(10);
        Wire.begin(_sclPin, _sdaPin, 100000);
        Wire.setTimeOut(25);
        delay(30);
        
        for (uint8_t addr = 1; addr < 127; addr++) {
            Wire.beginTransmission(addr);
            if (Wire.endTransmission() == 0) {
                Serial.printf("[OLED] Perangkat I2C terdeteksi pada pin tertukar di 0x%02X!\r\n", addr);
                if (addr == 0x3C || addr == 0x3D) {
                    foundAddr = addr;
                    uint8_t tmp = _sdaPin; _sdaPin = _sclPin; _sclPin = tmp;
                }
            }
        }
    }

    if (foundAddr != 0) {
        if (_display.begin(SSD1306_SWITCHCAPVCC, foundAddr)) {
            _isInitialized = true;
            _display.clearDisplay();
            _display.setTextColor(SSD1306_WHITE);
            printWelcomeScreen();
            Serial.printf("[OLED] SSD1306 128x64 display ACTIVE on 0x%02X!\r\n\n", foundAddr);
        } else {
            Serial.printf("[OLED] WARNING: Device ACKed at 0x%02X but SSD1306 init failed.\r\n", foundAddr);
        }
    } else {
        Serial.println(F("[OLED] ERROR: No I2C device responded. Check VDD/GND power and SDA/SCK connections.\r\n"));
    }

    return _isInitialized;
}

void OLEDDisplay::printWelcomeScreen() {
    _display.clearDisplay();
    _display.drawRoundRect(0, 0, 128, 64, 4, SSD1306_WHITE);
    
    _display.setTextSize(1);
    _display.setCursor(18, 8);
    _display.print(F("GANOPLUS EDGE"));

    _display.drawLine(16, 19, 112, 19, SSD1306_WHITE);

    _display.setCursor(10, 24);
    _display.print(F("Multi-Modal AI"));
    
    _display.setCursor(10, 36);
    _display.print(F("Gas + Bio-Impedance"));

    _display.drawRect(14, 49, 100, 7, SSD1306_WHITE);
    _display.fillRect(16, 51, 60, 3, SSD1306_WHITE);

    _display.display();
}

void OLEDDisplay::update(const GasSensorManager &gasMgr,
                         const DHTManager &dhtMgr,
                         const GanoMLManager &mlMgr,
                         const ImpedanceProbe &impProbe,
                         uint32_t uptimeSec) {
    if (!_isInitialized) return;

    // Switch between Main Dashboard and Detailed Sensor screen every 4 seconds
    uint32_t now = millis();
    if (now - _lastPageSwitch >= 4000) {
        _lastPageSwitch = now;
        _pageIndex = (_pageIndex + 1) % 2;
    }

    _display.clearDisplay();

    if (_pageIndex == 0) {
        drawDashboardPage(gasMgr, dhtMgr, mlMgr, impProbe, uptimeSec);
    } else {
        drawImpedancePage(impProbe, mlMgr);
    }

    _display.display();
}

void OLEDDisplay::drawDashboardPage(const GasSensorManager &gasMgr,
                                   const DHTManager &dhtMgr,
                                   const GanoMLManager &mlMgr,
                                   const ImpedanceProbe &impProbe,
                                   uint32_t uptimeSec) {
    const ganoplus_edge_output_t &ml = mlMgr.getOutput();
    const DHTReading &dht = dhtMgr.getReading();
    const ImpedanceReading &imp = impProbe.getReading();

    // 1. Header line: Device Name & DHT22
    _display.setTextSize(1);
    _display.setCursor(0, 0);
    _display.print(F("GANO+ "));
    if (dht.isValid) {
        _display.printf("%.0fC %.0f%%", dht.temperatureC, dht.humidity);
    } else {
        _display.print(F("--C --%"));
    }

    _display.setCursor(88, 0);
    uint32_t mins = uptimeSec / 60;
    uint32_t secs = uptimeSec % 60;
    _display.printf("%02u:%02u", mins, secs);
    _display.drawLine(0, 9, 127, 9, SSD1306_WHITE);

    // 2. ML Risk Diagnosis Banner
    const char *stageStr = GanoMLManager::getRiskClassName(ml.risk_class);
    if (ml.risk_class == GANOPLUS_HEALTHY) {
        _display.drawRoundRect(0, 12, 128, 14, 2, SSD1306_WHITE);
        _display.setCursor(4, 15);
        _display.printf("STATUS: HEALTHY %2.0f%%", ml.class_probabilities[GANOPLUS_HEALTHY] * 100.0f);
    } else {
        _display.fillRect(0, 12, 128, 14, SSD1306_WHITE);
        _display.setTextColor(SSD1306_BLACK);
        _display.setCursor(4, 15);
        _display.printf("! %s %2.0f%% !", stageStr, ml.risk_score * 100.0f);
        _display.setTextColor(SSD1306_WHITE);
    }

    // 3. Bio-Impedance Telemetry
    _display.setCursor(0, 29);
    if (imp.is_connected) {
        _display.printf("EIS: Z:%3.0f R:%3.0f X:%3.0f", imp.z_ohm, imp.r_ohm, imp.x_ohm);
    } else {
        _display.print(F("EIS: [AIR / OPEN]"));
    }

    // 4. Gas Telemetry
    _display.setCursor(0, 40);
    _display.printf("CO2:%4.0fppm NH3:%.1f", gasMgr.getCO2PPM(), gasMgr.getNH3PPM());

    // 5. Bottom Risk Gauge Bar (0% to 100%)
    _display.setCursor(0, 52);
    _display.print(F("RISK:"));
    _display.drawRect(32, 53, 94, 8, SSD1306_WHITE);
    
    int fillW = (int)(fminf(1.0f, fmaxf(0.0f, ml.risk_score)) * 90.0f);
    if (fillW > 0) {
        _display.fillRect(34, 55, fillW, 4, SSD1306_WHITE);
    }
}

void OLEDDisplay::drawImpedancePage(const ImpedanceProbe &impProbe,
                                    const GanoMLManager &mlMgr) {
    const ImpedanceReading &imp = impProbe.getReading();
    const ganoplus_edge_output_t &ml = mlMgr.getOutput();

    _display.setTextSize(1);
    _display.setCursor(0, 0);
    _display.print(F("BIO-IMPEDANCE 2kHz"));
    _display.drawLine(0, 9, 127, 9, SSD1306_WHITE);

    _display.setCursor(0, 13);
    _display.printf("Mag |Z| : %6.1f Ohm", imp.z_ohm);

    _display.setCursor(0, 24);
    _display.printf("Res (R) : %6.1f Ohm", imp.r_ohm);

    _display.setCursor(0, 35);
    _display.printf("Rea (X) : %6.1f Ohm", imp.x_ohm);

    _display.setCursor(0, 46);
    _display.printf("Phase   : %6.1f deg", imp.phase_deg);

    _display.drawLine(0, 56, 127, 56, SSD1306_WHITE);
    _display.setCursor(0, 57);
    if (imp.is_connected) {
        _display.printf("Vpp:%3.0fmV | Contact:%2.0f%%", imp.vpp_mv, imp.contact_quality * 100.0f);
    } else {
        _display.print(F("PROBE: DISCONNECTED"));
    }
}
