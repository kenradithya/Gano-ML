#ifndef DISPLAY_FORMATTER_H
#define DISPLAY_FORMATTER_H

#include <Arduino.h>
#include <Wire.h>
#include "config.h"
#include "GasSensors.h"
#include "DHTManager.h"
#include "GanoMLManager.h"
#include "ImpedanceProbe.h"

class DisplayFormatter {
public:
    DisplayFormatter(GasSensorManager &gasMgr, DHTManager &dhtMgr, GanoMLManager &mlMgr, ImpedanceProbe &impProbe);

    void begin();
    void printOutput(OutputMode mode, uint32_t uptimeSeconds);
    void printWelcomeHeader();
    void printHelp();
    void printPinMapping();
    void printR0Baselines();
    void printProbe();
    void printMLReport();
    void scanAllPins();
    void runAutoDetectWizard();
    
    void processSerialCommands();

    OutputMode getMode() const { return _currentMode; }
    void setMode(OutputMode mode) { _currentMode = mode; }

private:
    GasSensorManager &_gasMgr;
    DHTManager       &_dhtMgr;
    GanoMLManager    &_mlMgr;
    ImpedanceProbe   &_impProbe;
    OutputMode       _currentMode;
    String           _inputBuffer;

    void printDashboard(uint32_t uptimeSeconds);
    void printJson(uint32_t uptimeSeconds);
    void printPlotter();
    
    void handleCommand(const String &cmd);
};

#endif // DISPLAY_FORMATTER_H
