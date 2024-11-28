#include <Arduino.h>
#include "SCD41.h"

SCD41 co2Sensor;

void setup()
{
  Serial.begin(115200);

  co2Sensor.init();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
