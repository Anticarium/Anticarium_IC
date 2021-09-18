#include <Wire.h>
#include "AnticariumSlaveOutput.h"

void setup()
{
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(onDataReceived);
  pinMode(PinType::LED_PIN, OUTPUT);
  pinMode(PinType::VENT_PIN, OUTPUT);
  pinMode(PinType::HEAT_PIN, OUTPUT);
  pinMode(PinType::WATER_PIN, OUTPUT);

  digitalWrite(PinType::LED_PIN, LOW);
  digitalWrite(PinType::VENT_PIN, LOW);
  digitalWrite(PinType::HEAT_PIN, LOW);
  digitalWrite(PinType::WATER_PIN, LOW);
}

void loop()
{
}

