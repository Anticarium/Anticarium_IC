#include <Arduino.h>
#include <Wire.h>
#include "DHT.h"

DHT dht(4, DHT11);

void onRequestData();

int16_t temperature = 0;
int16_t humidity = 0;
int16_t moisture = 0;

const uint8_t multiplier = 100; // to avoid floats

void setup()
{
  Wire.begin(1);
  Wire.onRequest(onRequestData);
  dht.begin();
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  temperature = dht.readTemperature() * multiplier;
  humidity = dht.readHumidity() * multiplier;
  uint16_t sensorValue = analogRead(A0);
  moisture = sensorValue * (100.0f / 1023.0f) * 100;
}

void onRequestData()
{
  static uint8_t counter = 0;
  uint8_t dataType[3] = {'t', 'h', 'm'};
  int16_t value = 0;

  switch (counter)
  {
  case 0:
  {
    value = temperature;
  }
  break;
  case 1:
  {
    value = humidity;
  }
  break;
  case 2:
  {
    value = moisture;
  }
  break;
  default:
  {
  }
  break;
  }

  Wire.write(dataType[counter]);
  Wire.write(static_cast<uint8_t*>(static_cast<void*>(&value)), 2);

  ++counter;
  if (counter == 3)
  {
    counter = 0;
  }
}