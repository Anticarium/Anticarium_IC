#include "AnticariumSlaveInput.h"
#include "Fixtures.h"

void setup()
{
  dataReader.setup();
  anticariumSlaveInput.setup();
}

void loop()
{
  dataReader.read();
}
