#include "Driver.h"
#include <Wire.h>


uint8_t Driver::ReadChar(uint8_t address) {
  uint8_t device_adress = DeviceAddress();

  Wire.beginTransmission(device_adress);
  Wire.write(address);
  Wire.endTransmission();

  Wire.requestFrom(device_adress, 1);
  while(Wire.available() < 1)
    ;

  return Wire.read();
}

uint16_t Driver::ReadWord(uint16_t address) {
  uint8_t device_adress = DeviceAddress();
  
  Wire.beginTransmission(device_adress);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(device_adress, 2);
  while(Wire.available() < 2)
    ;

  uint8_t msb, lsb;
  msb = Wire.read();
  lsb = Wire.read();

  return msb<<8 | lsb;
}

void Driver::WriteChar(uint8_t address, uint8_t data) {
  uint8_t device_adress = DeviceAddress();
  Wire.beginTransmission(device_adress);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}
