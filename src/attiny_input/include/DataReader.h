#pragma once
#include <Arduino.h>

class DataReader
{
public:
    DataReader();
    void setup();
    void read();

    int16_t getTemperature() const;
    int16_t getHumidity() const;
    int16_t getMoisture() const;

private:
    int16_t temperature = 0;
    int16_t humidity = 0;
    int16_t moisture = 0;

    const uint8_t ANALOG_PIN = 2;
};