#include "SCD41.h"

SCD41::SCD41()
{
}

void SCD41::init()
{
    Wire.begin();
    scd4x.begin(Wire);
    // stop potentially previously started measurement
    scd4x.stopPeriodicMeasurement();
    // Start Measurement
    scd4x.startPeriodicMeasurement();
    Serial.println("Waiting for first measurement... (5 sec)");
}

void SCD41::read()
{
    uint16_t error;
    char errorMessage[256];

    error = scd4x.readMeasurement(co2, temperature, humidity);
    if (error)
    {
        Serial.print("Error trying to execute readMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }
    else if (co2 == 0)
    {
        Serial.println("Invalid sample detected, skipping.");
    }
    else
    {
        Serial.print("Co2:");
        Serial.print(co2);
        Serial.print("\t");
        Serial.print("Temperature:");
        Serial.print(temperature);
        Serial.print("\t");
        Serial.print("Humidity:");
        Serial.println(humidity);
    }
}

uint16_t SCD41::getCO2()
{
    return co2;
}

float SCD41::getTemperature()
{
    return temperature;
}

float SCD41::getHumidity()
{
    return humidity;
}