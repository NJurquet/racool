#include "SCD41.h"

SCD41::SCD41()
{
    co2 = 0;
    temperature = 0.0f;
    humidity = 0.0f;
    isDataReady = false;
}

void SCD41::init()
{
    uint16_t error;
    char errorMessage[256];

    Wire.begin();
    scd4x.begin(Wire);

    // stop potentially previously started measurement
    error = scd4x.stopPeriodicMeasurement();
    if (error)
    {
        Serial.print("CO2 : Error trying to execute stopPeriodicMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }

    // Start Measurement
    error = scd4x.startPeriodicMeasurement();
    if (error)
    {
        Serial.print("CO2 : Error trying to execute startPeriodicMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }
    Serial.println("Waiting for first CO2 measurement... (5 sec)");
}

void SCD41::read()
{
    uint16_t error;
    char errorMessage[256];

    error = scd4x.getDataReadyFlag(isDataReady);
    if (error)
    {
        Serial.print("CO2 : Error trying to execute getDataReadyFlag(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
        return;
    }
    if (!isDataReady)
    {
        return;
    }

    error = scd4x.readMeasurement(co2, temperature, humidity);
    if (error)
    {
        Serial.print("CO2 : Error trying to execute readMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }
    else if (co2 == 0)
    {
        Serial.println("Invalid CO2 sample detected, skipping.");
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

double SCD41::getTemperature()
{
    return (double)temperature;
}

double SCD41::getHumidity()
{
    return (double)humidity;
}