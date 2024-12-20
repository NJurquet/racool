#ifndef LM35_H
#define LM35_H
#include <Arduino.h>

class LM35 {
public:
    LM35(uint8_t pin, int resolution = 4096);

    void init();
    void read();

private:
    uint8_t pin;            // Broche analogique connectée au LM35
    static constexpr float vRef = 3300.0; // Référence de tension en millivolts (fixée à 3300 mV)
    int resolution;         // Résolution ADC
};

#endif // LM35_H
