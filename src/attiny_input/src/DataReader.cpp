#include "DataReader.h"
#include "Fixtures.h"
#include "DHT.h"

DataReader::DataReader()
{
}

void DataReader::setup()
{
    DHT_Setup();
    pinMode(ANALOG_PIN, INPUT);
}

void DataReader::read()
{
    uint8_t dhtData[4] = {};
    DHT_Status_t dhtStatus = DHT_ReadRaw(dhtData);

    if (dhtStatus == DHT_Status_t::DHT_Ok)
    {
        int16_t *convertedData = nullptr;

        convertedData = static_cast<int16_t *>(static_cast<void *>(&dhtData));
        temperature = *convertedData;

        convertedData = static_cast<int16_t *>(static_cast<void *>(&dhtData + 2));
        humidity = *convertedData;
    }

    // returns analog value ranging 0 - 1023
    moisture = analogRead(A0);
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