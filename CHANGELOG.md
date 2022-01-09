# Anticarium_IC

## 1.0.1
- MODIFY: Increased PWM frequency from 61Hz to 3.91KHz for output MCU
- MODIFY: Send 4 byte float values to i2c from input MCU
- MODIFY: Switch to DHT22 from DHT11 for input MCU
- MODIFY: Use DHT.h instead of TinyDHT.h for DHT readings for input MCU

## 1.0.0
- MODIFY: README.md updated with instructions for `attiny_input`
- ADD: `src/attiny_input` working ATTiny85 code
- ADD: `src/attiny_output` working ATTiny24a code

## 0.0.1
- ADD: `development/master_uno` for sending and receiving test I2C messages
- ADD: `development/slave_nano_input` ATMega328P code prototype for later conversion to ATTiny25 code
- ADD: `development/slave_nano_output` ATMega328P code prototype for later conversion to ATTiny24a code
- ADD: README about `development` folder. Includes circuit drawing
- ADD: Project README, describing communication of MCUs in this project
- ADD: VERSION file