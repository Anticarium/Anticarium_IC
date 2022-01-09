#include "AnticariumSlaveInput.h"
#include "Fixtures.h"

void setup()
{
  dataReader.setup();
  anticariumSlaveInput.setup(I2CAddress);
  dataReader.read();
}

void loop()
{
  read();
}
