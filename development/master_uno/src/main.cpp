#include <Arduino.h>
#include <Wire.h>

enum PinType
{
  LED_PIN = 2,
  VENT_PIN = 3,
  HEAT_PIN = 9,
  WATER_PIN = 10
};

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

uint8_t x = 0;
void loop() {
  static bool flag = false;
  Wire.beginTransmission(0);
  Wire.write(static_cast<uint8_t>(PinType::VENT_PIN));
  Wire.write(x);
  Wire.endTransmission();
  delay(100);
  Wire.beginTransmission(0);
  Wire.write(static_cast<uint8_t>(PinType::LED_PIN));
  Wire.write(x);
  Wire.endTransmission();
  delay(100);
  Wire.beginTransmission(0);
  Wire.write(static_cast<uint8_t>(PinType::HEAT_PIN));
  Wire.write(flag);
  Wire.endTransmission();
  delay(100);
  Wire.beginTransmission(0);
  Wire.write(static_cast<uint8_t>(PinType::WATER_PIN));
  Wire.write(flag);
  Wire.endTransmission();
  flag = !flag;
  x+=10;

  delay(1000);

  Wire.requestFrom(1, 3);    // request 6 bytes from slave device #8

  uint8_t buffer[3] = {};
  for(uint8_t i = 0; i<3; i++) {
    buffer[i] = Wire.read(); // receive a byte as character
  }

  uint8_t dataType = buffer[0];

  int16_t value = 0;
  value = buffer[1] << 8;
  value |= buffer[2];

  Serial.print("DataType: ");
  Serial.println(static_cast<char>(dataType));
  Serial.print("Value: ");
  Serial.println(value);
  Serial.println();

  delay(1000);
}