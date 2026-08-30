#ifndef DHT_MANAGER_H
#define DHT_MANAGER_H

#include <Arduino.h>
#include <DHT.h>
#include "config.h"

struct DHTReading {
    float       temperatureC;
    float       temperatureF;
    float       humidity;
    float       heatIndexC;
    float       dewPointC;
    bool        isValid;
    const char* errorMsg;
    uint32_t    lastReadTimestamp;
    uint32_t    successCount;
    uint32_t    errorCount;
};

class DHTManager {
public:
    DHTManager(uint8_t pin = PIN_DHT22);

    void begin();
    bool update(bool force = false);

    const DHTReading& getReading() const { return _reading; }
    float getTemperatureC() const { return _reading.temperatureC; }
    float getTemperatureF() const { return _reading.temperatureF; }
    float getHumidity() const { return _reading.humidity; }
    float getHeatIndexC() const { return _reading.heatIndexC; }
    float getDewPointC() const { return _reading.dewPointC; }
    bool isValid() const { return _reading.isValid; }

    static float computeDewPoint(float tempC, float humidity);
    static float computeHeatIndex(float tempC, float humidity);

private:
    uint8_t    _pin;
    DHT        _dht;
    DHTReading _reading;
    uint32_t   _lastAttemptTime;

    bool readSensorDirect(float &outTemp, float &outHum, const char* &outErr);
};

#endif // DHT_MANAGER_H
