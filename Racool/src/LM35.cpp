#include "LM35.h"

// Constructeur
LM35::LM35(uint8_t pin, int resolution)
    : pin(pin), resolution(resolution) {}

// Méthode d'initialisation
void LM35::init() {
    analogSetAttenuation(ADC_11db); // Configurer l'atténuation pour une plage complète
}

// Lire la température en Celsius
void LM35::read() {
    int adcVal = analogRead(pin);
    float milliVolt = adcVal * (vRef / resolution); // Convertir en millivolts
    float temperature = milliVolt / 10.0; // LM35 produit 10 mV par degré Celsius
    Serial.print("Température : ");
    Serial.println(temperature);
}


