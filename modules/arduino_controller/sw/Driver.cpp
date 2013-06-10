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

void Driver::ReadBuffer(uint8_t address, uint8_t *buffer, uint8_t size) {
  uint8_t device_adress = DeviceAddress();

  Wire.beginTransmission(device_adress);
  Wire.write(address);
  Wire.endTransmission();

  Wire.requestFrom(device_adress, size);
  while(Wire.available() < size)
    ;

  for (uint8_t i = 0; i < size; i++) {
    buffer[i] = Wire.read();
  }
}

uint8_t Driver::ReadChar(uint8_t address) {
  uint8_t result;
  ReadBuffer(address, &result, 1);
  return result;
}

uint16_t Driver::ReadWord(uint8_t address) {
  uint8_t buffer[2];
  ReadBuffer(address, buffer, 2);
  return buffer[0]<<8 | buffer[1];
}

void Driver::WriteChar(uint8_t address, uint8_t data) {
  uint8_t device_adress = DeviceAddress();
  Wire.beginTransmission(device_adress);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}
