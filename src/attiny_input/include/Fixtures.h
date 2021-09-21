#pragma once
#include "DataReader.h"
#include "AnticariumSlaveInput.h"

extern AnticariumSlaveInput anticariumSlaveInput;
extern DataReader dataReader;

void onRequestData();
void read();