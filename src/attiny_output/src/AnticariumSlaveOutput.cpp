#include "AnticariumSlaveOutput.h"
#include <Wire.h>

void onDataReceived(int byteAmount)
{
  uint8_t buffer[2] = {};

  for (uint8_t i = 0; i < sizeof(buffer); i++)
  {
    buffer[i] = Wire.read();
  }

  auto pinType = buffer[0];
  auto value = buffer[1];

  if (pinType == Led || pinType == Fan)
  {
    analogWrite(pinType, value);
  }
  else if (pinType == Water || pinType == Heat)
  {
    digitalWrite(pinType, value);
  }
}