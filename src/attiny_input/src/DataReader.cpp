#include "DataReader.h"
#include "Fixtures.h"

DataReader::DataReader(uint8_t dhtPin, uint8_t dhtType, uint8_t analogPin)
    : dht(dhtPin, dhtType),
      analogPin(analogPin)
{
}

void DataReader::setup()
{
    dht.begin();
    pinMode(analogPin, INPUT);
}

void DataReader::read()
{
    auto newTemperature = dht.readTemperature();
    if (!isnan(newTemperature))
    {
        temperature = newTemperature;
    }

    auto newHumidity = dht.readHumidity();
    if (!isnan(newHumidity))
    {
        humidity = newHumidity;
    }

    moisture = analogRead(analogPin);
}

float DataReader::getTemperature() const
{
    return temperature;
}

float DataReader::getHumidity() const
{
    return humidity;
}

float DataReader::getMoisture() const
{
    return moisture;
}