#pragma once
#include <stdint.h>
#include <Arduino.h>

enum PinType
{
  LED_PIN = 2,
  VENT_PIN = 3,
  HEAT_PIN = 9,
  WATER_PIN = 10
};

const uint8_t I2C_ADDRESS = 0;

void onDataReceived(int byteAmount);
