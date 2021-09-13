#pragma once
#include <Arduino.h>
#include "DHT.h"

class DataReader
{
public:
    DataReader(uint8_t dhtPin, uint8_t dhtType);
    void setup();
    void read();

    float getTemperature() const;
    float getHumidity() const;
    float getMoisture() const;

private:
    DHT dht;
    float temperature = 0;
    float humidity = 0;
    float moisture = 0;

    const uint8_t ANALOG_PIN = A0;
};