#include "AnticariumSlaveInput.h"
#include "Fixtures.h"

AnticariumSlaveInput::AnticariumSlaveInput()
{
}

void AnticariumSlaveInput::setup()
{
    Wire.begin(I2C_ADDRESS);
    Wire.onRequest(onRequestData);
}

void AnticariumSlaveInput::sendData(const DataReader &dataReader)
{
    int16_t value = 0;

    switch (dataTypeIterator)
    {
    case 0:
    {
        value = dataReader.getTemperature() * MULTIPLIER;
    }
    break;
    case 1:
    {
        value = dataReader.getHumidity() * MULTIPLIER;
    }
    break;
    case 2:
    {
        value = dataReader.getMoisture() * MULTIPLIER;
    }
    break;
    default:
    {
    }
    break;
    }

    Wire.write(DATA_TYPE[dataTypeIterator]);
    Wire.write(static_cast<uint8_t *>(static_cast<void *>(&value)), 2);

    ++dataTypeIterator;
    if (dataTypeIterator == 3)
    {
        dataTypeIterator = 0;
    }
}