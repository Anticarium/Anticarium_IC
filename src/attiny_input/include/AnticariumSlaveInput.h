#pragma once
#include "DataReader.h"

class AnticariumSlaveInput
{
public:
    AnticariumSlaveInput();
    void sendData(const DataReader &dataReader);
    void setup(uint8_t i2cAddress);

private:
    const uint8_t dataType[3] = {'t', 'h', 'm'};

    uint8_t dataTypeIterator = 0;
};