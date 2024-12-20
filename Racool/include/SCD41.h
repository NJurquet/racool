#ifndef SCD41_H
#define SCD41_H

#include <Wire.h>
#include <SensirionI2CScd4x.h>

class SCD41
{
public:
    SCD41();

    void init();

    void read();

    uint16_t getCO2();

    double getTemperature();

    double getHumidity();

private:
    SensirionI2CScd4x scd4x;
    uint16_t co2;
    float temperature;
    float humidity;
    bool isDataReady;
};

#endif // SCD41_H