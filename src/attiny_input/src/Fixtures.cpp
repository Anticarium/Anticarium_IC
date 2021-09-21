#include "Fixtures.h"

AnticariumSlaveInput anticariumSlaveInput;
DataReader dataReader(4, 11, 3);

void onRequestData()
{
    anticariumSlaveInput.sendData(dataReader);
}

void read()
{
    static unsigned long previousTime = millis();
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= 1000)
    {
        dataReader.read();
        previousTime = currentTime;
    }
}