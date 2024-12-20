#include <Arduino.h>
#include "SCD41.h"
#include "LM35.h"

SCD41 co2Sensor;
LM35 tempSensor1(6, 4096); //LM35 sur ADC de l'esp32

void setup()
{
  Serial.begin(115200);

  co2Sensor.init();
  tempSensor1.init();
}

void loop()
{
  co2Sensor.read();
  tempSensor1.read();
}
