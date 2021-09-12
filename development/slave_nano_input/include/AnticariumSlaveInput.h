#pragma once
#include "DataReader.h"
#include <Wire.h>

class AnticariumSlaveInput
{
public:
    AnticariumSlaveInput();
    void sendData(const DataReader & dataReader);
    void setup();
private:
    const uint8_t MULTIPLIER = 100;
    const uint8_t I2C_ADDRESS = 1;
    const uint8_t DATA_TYPE[3] = {'t', 'h', 'm'};

    uint8_t dataTypeIterator = 0;
};