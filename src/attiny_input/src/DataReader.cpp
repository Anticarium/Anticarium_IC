#include "DataReader.h"
#include "Fixtures.h"

DataReader::DataReader(uint8_t dhtPin, uint8_t dhtType, uint8_t analogPin) : dht(dhtPin, dhtType), ANALOG_PIN(analogPin)
{
}

void DataReader::setup()
{
    dht.begin();
    pinMode(ANALOG_PIN, INPUT);
}

void DataReader::read()
{
    int16_t newTemperature = dht.readTemperature();
    if(newTemperature != BAD_TEMP){
        temperature = newTemperature;
    } 
    
    int16_t newHumidity = dht.readHumidity();
    if(newHumidity != BAD_HUM) {
        humidity = newHumidity;
    }
    
    moisture = analogRead(ANALOG_PIN);
}

int16_t DataReader::getTemperature() const
{
    return temperature;
}

int16_t DataReader::getHumidity() const
{
    return humidity;
}

int16_t DataReader::getMoisture() const
{
    return moisture;
}