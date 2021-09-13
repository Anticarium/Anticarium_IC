#pragma once
#include <stdint.h>

enum PinType
{
  LED_PIN = 5,
  VENT_PIN,
  HEAT_PIN,
  WATER_PIN,
};

const uint8_t I2C_ADDRESS = 0;

void onDataReceived(int byteAmount);
