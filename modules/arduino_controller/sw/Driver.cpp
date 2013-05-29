/*
 * This file is part of the Ckelinar Project.
 *
 * Copyright (C) 2013  UNIVERSIDAD DE CHILE.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
