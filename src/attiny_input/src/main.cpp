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
  TinyWireS_stop_check();
}
