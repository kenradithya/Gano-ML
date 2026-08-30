#ifndef IMPEDANCE_PROBE_H
#define IMPEDANCE_PROBE_H

#include <Arduino.h>
#include "config.h"

struct ImpedanceReading {
    float z_ohm;            // Total magnitude |Z| (Ohm)
    float r_ohm;            // Real part: Bio-Resistance R (Ohm)
    float x_ohm;            // Imaginary part: Bio-Reactance X (Ohm, negative capacitive)
    float phase_deg;        // Phase shift angle theta (degrees)
    float vpp_mv;           // Peak-to-peak amplitude received from LM358 (mV)
    float v_dc_mv;          // DC offset bias level (mV)
    float contact_quality;  // 0.00 to 1.00 electrode connection quality score
    bool  is_connected;     // True if probe tip is actively conducting through tissue
    bool  is_valid;         // True if values are physically valid for ML inference
    const char* status;     // Human-readable status string
};

class ImpedanceProbe {
public:
    ImpedanceProbe(uint8_t txPin = PIN_IMPEDANCE_TX, uint8_t rxPin = PIN_IMPEDANCE_RX);

    void begin();
    void update();

    const ImpedanceReading& getReading() const { return _reading; }
    bool isValid() const { return _reading.is_valid; }
    bool isConnected() const { return _reading.is_connected; }
    float getResistance() const { return _reading.r_ohm; }
    float getReactance() const { return _reading.x_ohm; }
    float getPhaseDeg() const { return _reading.phase_deg; }
    float getContactQuality() const { return _reading.contact_quality; }

private:
    uint8_t          _txPin;
    uint8_t          _rxPin;
    ImpedanceReading _reading;
    float            _emaR;
    float            _emaX;
    float            _emaVpp;
    bool             _emaInit;

    void sampleWaveform(float &outVpp, float &outVdc, float &outPhaseDeg, float &outQuality);
};

#endif // IMPEDANCE_PROBE_H
