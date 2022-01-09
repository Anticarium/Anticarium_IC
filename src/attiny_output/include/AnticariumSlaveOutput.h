#pragma once
#include <stdint.h>
#include <Arduino.h>

enum PinType
{
  Led = 2,
  Fan = 3,
  Heat = 9,
  Water = 10
};

const uint8_t i2cAddress = 0;

void onDataReceived(int byteAmount);
