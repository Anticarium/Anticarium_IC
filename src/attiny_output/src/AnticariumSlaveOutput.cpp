#include <Wire.h>
#include <Arduino.h>
#include "AnticariumSlaveOutput.h"

void onDataReceived(int byteAmount)
{
  uint8_t buffer[2] = {};

  for (uint8_t i = 0; i < sizeof(buffer); i++)
  {
    buffer[i] = Wire.read();
  }

  const auto pinType = buffer[0];
  const auto value = buffer[1];

  if (pinType == Led || pinType == Fan_Pwm)
  {
    analogWrite(pinType, value);
  }
  else if (pinType == Water || pinType == Heat || pinType == Fan_IO)
  {
    digitalWrite(pinType, value);
  }
}