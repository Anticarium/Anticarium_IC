#include "Fixtures.h"

AnticariumSlaveInput anticariumSlaveInput;
DataReader dataReader;

void onRequestData()
{
    dataReader.read();
    anticariumSlaveInput.sendData(dataReader);
}