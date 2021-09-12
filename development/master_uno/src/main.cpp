#include <Arduino.h>
#include <Wire.h>

enum PinType
{
  LED_PIN = 5,
  VENT_PIN,
  HEAT_PIN,
  WATER_PIN,
};

void setup() {
  Wire.begin();
}

uint8_t x = 0;
void loop() {
  Wire.beginTransmission(0);
  Wire.write(static_cast<uint8_t>(5));
  Wire.write(x);
  Wire.endTransmission();

  x+=10;
  delay(500);
}