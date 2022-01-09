#pragma once
#include "DataReader.h"
#include "AnticariumSlaveInput.h"

enum Constants
{
    ReadTimeout = 1000,
    DHTPin = 4,
    AnalogPin = 3,
    I2CAddress = 1,
};

extern AnticariumSlaveInput anticariumSlaveInput;
extern DataReader dataReader;

void onRequestData();
void read();