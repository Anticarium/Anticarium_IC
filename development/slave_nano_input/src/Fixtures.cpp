#include "Fixtures.h"

AnticariumSlaveInput anticariumSlaveInput;
DataReader dataReader(4, 11);

void onRequestData()
{
    anticariumSlaveInput.sendData(dataReader);
}