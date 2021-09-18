#include "AnticariumSlaveInput.h"
#include "Fixtures.h"

AnticariumSlaveInput::AnticariumSlaveInput()
{
}

void AnticariumSlaveInput::setup()
{
    TinyWireS.begin(I2C_ADDRESS);
    TinyWireS.onRequest(onRequestData);
}

void AnticariumSlaveInput::sendData(const DataReader &dataReader)
{
    int16_t value = 0;

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

    uint8_t * dividedData = static_cast<uint8_t *>(static_cast<void *>(&value));

    TinyWireS.send(DATA_TYPE[dataTypeIterator]);
    TinyWireS.send(dividedData[0]);
    TinyWireS.send(dividedData[1]);

    ++dataTypeIterator;
    if (dataTypeIterator == 3)
    {
        dataTypeIterator = 0;
    }
}