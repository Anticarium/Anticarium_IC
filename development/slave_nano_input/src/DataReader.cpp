#include "DataReader.h"
#include "Fixtures.h"

DataReader::DataReader(uint8_t dhtPin, uint8_t dhtType) : dht(dhtPin, dhtType)
{
}

void DataReader::setup()
{
    dht.begin();
    pinMode(ANALOG_PIN, INPUT);
}

void DataReader::read()
{
    float newTemperature = dht.readTemperature();
    if(!isnan(newTemperature)){
        temperature = newTemperature;
    } 
    
    float newHumidity = dht.readHumidity();
    if(!isnan(newHumidity)) {
        humidity = newHumidity;
    }
    
    uint16_t sensorValue = analogRead(A0);
    moisture = sensorValue * (100.0f / 1023.0f);
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