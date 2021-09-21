#pragma once
#include <Arduino.h>
#include "TinyDHT.h"

class DataReader
{
public:
    DataReader(uint8_t dhtPin, uint8_t dhtType, uint8_t analogPin);
    void setup();
    void read();

    int16_t getTemperature() const;
    int16_t getHumidity() const;
    int16_t getMoisture() const;

private:
    DHT dht;
    int16_t temperature = 0;
    int16_t humidity = 0;
    int16_t moisture = 0;

    const uint8_t ANALOG_PIN;
};