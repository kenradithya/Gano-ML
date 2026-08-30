#ifndef GAS_SENSORS_H
#define GAS_SENSORS_H

#include <Arduino.h>
#include "config.h"

enum GasSensorType {
    GAS_TGS2600 = 0,
    GAS_MQ3     = 1,
    GAS_MQ4     = 2,
    GAS_MQ9     = 3,
    GAS_MQ135   = 4,
    GAS_COUNT   = 5
};

struct GasReading {
    GasSensorType type;
    const char*   name;
    const char*   targetGas;
    const char*   unit;
    uint8_t       pin;
    uint16_t      rawADC;
    float         voltageMV;
    float         rs_kohm;
    float         r0_kohm;
    float         ratio;
    float         ppm;
    const char*   status;
    bool          isWarmingUp;
};

class GasSensorManager {
public:
    GasSensorManager();

    void begin();
    void update(float ambientTempC = 20.0f, float ambientHumidity = 50.0f);
    void calibrate(uint16_t samples = CALIBRATION_SAMPLES);
    
    const GasReading& getReading(GasSensorType type) const;
    const GasReading* getAllReadings() const;
    
    float getNH3PPM() const;
    float getCO2PPM() const;
    float getTGS2600AirIndex() const;
    float getMQ3Alcohol() const;

    bool isCalibrated() const { return _calibrated; }
    void setWarmingUp(bool warming) { _warmingUp = warming; }
    bool isWarmingUp() const { return _warmingUp; }

    void setR0(GasSensorType type, float r0_kohm);
    void setSensorPin(GasSensorType type, uint8_t pin);
    float readFilteredMilliVolts(uint8_t pin, uint16_t &outRawADC, uint16_t oversamples = ADC_OVERSAMPLES);

    static float calculateNH3(float ratio);
    static float calculateCO2(float ratio);

private:
    GasReading _readings[GAS_COUNT];
    float      _loadResistors[GAS_COUNT];
    float      _cleanAirRatios[GAS_COUNT];
    float      _emaVoltages[GAS_COUNT];
    bool       _emaInit;
    bool       _calibrated;
    bool       _warmingUp;

    float calculateRs(float voltageMV, float rl_kohm);
    float calculatePPM(GasSensorType type, float ratio);
    const char* evaluateStatus(GasSensorType type, float ratio, float ppm);
};

#endif
