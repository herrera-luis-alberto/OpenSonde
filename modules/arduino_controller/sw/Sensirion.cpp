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

#include "Sensirion.h"
#include <Wire.h>

void SensirionDriver::SetUp() {
}

void SensirionDriver::Poll(Print &data_transmitter) {
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
