#include "AnticariumSlaveInput.h"
#include "Fixtures.h"

void setup()
{
  dataReader.setup();
  anticariumSlaveInput.setup();
  dataReader.read();
}

void loop()
{
  read();
}
