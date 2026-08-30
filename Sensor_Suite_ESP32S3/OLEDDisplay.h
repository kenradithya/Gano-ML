#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "GasSensors.h"
#include "DHTManager.h"
#include "GanoMLManager.h"
#include "ImpedanceProbe.h"

class OLEDDisplay {
public:
    OLEDDisplay(uint8_t sdaPin = PIN_OLED_SDA, uint8_t sclPin = PIN_OLED_SCL);

    bool begin();
    void update(const GasSensorManager &gasMgr,
                const DHTManager &dhtMgr,
                const GanoMLManager &mlMgr,
                const ImpedanceProbe &impProbe,
                uint32_t uptimeSec);

    bool isInitialized() const { return _isInitialized; }
    void printWelcomeScreen();

private:
    uint8_t          _sdaPin;
    uint8_t          _sclPin;
    Adafruit_SSD1306 _display;
    bool             _isInitialized;
    uint8_t          _pageIndex;
    uint32_t         _lastPageSwitch;

    void drawDashboardPage(const GasSensorManager &gasMgr,
                           const DHTManager &dhtMgr,
                           const GanoMLManager &mlMgr,
                           const ImpedanceProbe &impProbe,
                           uint32_t uptimeSec);

    void drawImpedancePage(const ImpedanceProbe &impProbe,
                           const GanoMLManager &mlMgr);

    void drawGasDetailsPage(const GasSensorManager &gasMgr,
                            const DHTManager &dhtMgr);
};

#endif // OLED_DISPLAY_H
