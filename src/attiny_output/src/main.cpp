#include <Wire.h>
#include "AnticariumSlaveOutput.h"

void setup()
{
  Wire.begin(i2cAddress);
  Wire.onReceive(onDataReceived);
  pinMode(Led, OUTPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Heat, OUTPUT);
  pinMode(Water, OUTPUT);

  digitalWrite(Led, LOW);
  digitalWrite(Fan, LOW);
  digitalWrite(Heat, LOW);
  digitalWrite(Water, LOW);

  // TCCR0B – Timer/Counter Control Register B
  // Set no timer prescaling for faster PWM
  TCCR0B &= 0b11111000 | 0b1;
}

void loop()
{
}

