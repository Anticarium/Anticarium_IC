#pragma once
#include <stdint.h>

enum PinType
{
  Led = 2,
  Fan_Pwm = 3,
  Fan_IO = 8,
  Heat = 9,
  Water = 10
};

const uint8_t i2cAddress = 0;

void onDataReceived(int byteAmount);
