#include "AnticariumSlaveInput.h"
#include "Fixtures.h"
#include <Wire.h>

AnticariumSlaveInput::AnticariumSlaveInput()
{
}

void AnticariumSlaveInput::setup(uint8_t i2cAddress)
{
    Wire.begin(i2cAddress);
    Wire.onRequest(onRequestData);
}

void AnticariumSlaveInput::sendData(const DataReader &dataReader)
{
    float value = 0;

    switch (dataTypeIterator)
    {
    case 0:
    {
        value = dataReader.getTemperature();
    }
    break;
    case 1:
    {
        value = dataReader.getHumidity();
    }
    break;
    case 2:
    {
        value = dataReader.getMoisture();
    }
    break;
    default:
    {
    }
    break;
    }

    Wire.write(dataType[dataTypeIterator]);
    Wire.write(reinterpret_cast<uint8_t *>(&value), sizeof(float));

    ++dataTypeIterator;
    if (dataTypeIterator == sizeof(dataType))
    {
        dataTypeIterator = 0;
    }
}