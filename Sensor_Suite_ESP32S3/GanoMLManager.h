#ifndef GANO_ML_MANAGER_H
#define GANO_ML_MANAGER_H

#include <Arduino.h>
#include "config.h"
#include "ganoplus_edge_model.h"
#include "XGBoostGano.h"
#include "GasSensors.h"
#include "DHTManager.h"

struct GanoTreeBaseline {
    float voc_index_corrected;
    float nh3_ppm;
    float x_2khz_ohm;
    float r_2khz_ohm;
    bool  is_set;
};

class GanoMLManager {
public:
    GanoMLManager();

    void begin();
    void update(const GasSensorManager &gasMgr, const DHTManager &dhtMgr, uint32_t uptimeSec);

    const ganoplus_edge_input_t& getInput() const { return _currentInput; }
    const ganoplus_edge_output_t& getOutput() const { return _currentOutput; }
    const XGBoostOutput& getXGBoostOutput() const { return _xgbOutput; }
    const GanoTreeBaseline& getBaseline() const { return _baseline; }

    void captureBaseline(const GasSensorManager &gasMgr, const DHTManager &dhtMgr);
    void resetBaseline();

    void setFertilizerRecent(bool recent) { _fertilizerRecent = recent; }
    bool getFertilizerRecent() const { return _fertilizerRecent; }

    void setImpedanceProbe(float r_ohm, float x_ohm, float contact_quality = 0.85f);
    void clearImpedanceProbe();

    bool runSelfTest(Stream &out = Serial);

    const char* getRoomAirQuality() const;
    const char* getRoomAirQualityColor() const;
    const char* getGanodermaTargetStatus() const;
    const char* getGanodermaTargetColor() const;

    static const char* getRiskClassName(ganoplus_risk_class_t riskClass);
    static const char* getRiskClassColor(ganoplus_risk_class_t riskClass);
    static const char* getDecisionStatusName(ganoplus_decision_status_t status);
    static String getReasonCodesDescription(uint32_t reasonCodes);

private:
    ganoplus_edge_input_t  _currentInput;
    ganoplus_edge_output_t _currentOutput;
    XGBoostOutput          _xgbOutput;
    GanoTreeBaseline       _baseline;
    bool                   _fertilizerRecent;
    bool                   _hasCustomImpedance;
    float                  _customR2k;
    float                  _customX2k;
    float                  _customContactQuality;
    const char*            _roomAirQuality;
    const char*            _ganodermaTargetStatus;
};

#endif // GANO_ML_MANAGER_H
