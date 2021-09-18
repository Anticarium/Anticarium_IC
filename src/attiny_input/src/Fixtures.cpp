#include "Fixtures.h"

AnticariumSlaveInput anticariumSlaveInput;
DataReader dataReader;

void onRequestData()
{
    anticariumSlaveInput.sendData(dataReader);
}