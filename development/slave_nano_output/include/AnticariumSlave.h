#pragma once

enum PinType
{
  LED_PIN = 5,
  VENT_PIN,
  HEAT_PIN,
  WATER_PIN,
};

void onDataReceived(int byteAmount);
