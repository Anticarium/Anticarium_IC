#include "AnticariumSlaveInput.h"
#include "Fixtures.h"
#include <Arduino.h>

void setup()
{
  dataReader.setup();
  anticariumSlaveInput.setup();
}

void loop()
{
  dataReader.read();
}
