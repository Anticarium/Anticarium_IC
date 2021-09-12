#include "AnticariumSlaveOutput.h"
#include <Arduino.h>
#include <Wire.h>

void onDataReceived(int byteAmount)
{
  uint8_t buffer[2] = {};

  for (uint8_t i = 0; i < 2; i++)
  {
    buffer[i] = Wire.read();
  }

  uint8_t pinType = buffer[0];
  uint8_t value = buffer[1];

  if (pinType == PinType::LED_PIN || pinType == PinType::VENT_PIN)
  {
    analogWrite(pinType, value);
  }
  else if (pinType == PinType::WATER_PIN || pinType == PinType::HEAT_PIN)
  {
    digitalWrite(pinType, value);
  }
}