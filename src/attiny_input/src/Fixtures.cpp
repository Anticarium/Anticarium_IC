#include "Fixtures.h"

AnticariumSlaveInput anticariumSlaveInput;
DataReader dataReader(DHT22, DHTPin, AnalogPin);

void onRequestData()
{
    anticariumSlaveInput.sendData(dataReader);
}

void read()
{
    static auto previousTime = millis();
    const auto currentTime = millis();
    if (currentTime - previousTime >= ReadTimeout)
    {
        dataReader.read();
        previousTime = currentTime;
    }
}