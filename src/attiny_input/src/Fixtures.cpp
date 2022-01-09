#include "Fixtures.h"

AnticariumSlaveInput anticariumSlaveInput;
DataReader dataReader(DHT22, DHTPin, AnalogPin);

void onRequestData()
{
    anticariumSlaveInput.sendData(dataReader);
}

void read()
{
    auto previousTime = millis();
    auto currentTime = millis();
    if (currentTime - previousTime >= ReadTimeout)
    {
        dataReader.read();
        previousTime = currentTime;
    }
}