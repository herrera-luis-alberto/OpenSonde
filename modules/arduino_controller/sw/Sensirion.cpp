
#include "Sensirion.h"
#include <Wire.h>

void SensirionDriver::SetUp() {
}

void SensirionDriver::Callback(Print &data_transmitter) {
  Wire.requestFrom(DeviceAddress(), 4);
  while(Wire.available() < 4)
    ;

  uint8_t msb, lsb;
  
  msb = Wire.read();
  lsb = Wire.read();
  uint16_t temperature = msb<<8 | lsb;
  
  msb = Wire.read();
  lsb = Wire.read();
  uint16_t humidity = msb<<8 | lsb;
  
  data_transmitter.print("<");
  data_transmitter.print(DeviceAddress(), HEX);
  data_transmitter.print(", ");
  data_transmitter.print(temperature, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(humidity, DEC);
  data_transmitter.println(">");
}
