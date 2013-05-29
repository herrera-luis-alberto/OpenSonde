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

#include "gps.h"
#include <Wire.h>

void GPSDriver::SetUp() {
}

void GPSDriver::Poll(Print &data_transmitter) {
  const uint8_t gps_fields_number = 4;
  const uint8_t bytes_to_transfer = gps_fields_number*sizeof(long);
  long gps_data[gps_fields_number];
  char *buffer = (char *)gps_data;

  Wire.requestFrom(DeviceAddress(), bytes_to_transfer);
  while(Wire.available() < bytes_to_transfer)
    ;

  for (uint8_t i=0; i<bytes_to_transfer; i++) {
    buffer[i] = Wire.read();
  }

  data_transmitter.print("<");
  data_transmitter.print(DeviceAddress(), HEX);
  
  data_transmitter.print(",");
  data_transmitter.print(gps_data[0]/1000, DEC);
  data_transmitter.print(".");
  data_transmitter.print(gps_data[0]%1000, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(gps_data[1]/10000, DEC);
  data_transmitter.print(".");
  data_transmitter.print(abs(gps_data[1])%10000, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(gps_data[2]/10000, DEC);
  data_transmitter.print(".");
  data_transmitter.print(abs(gps_data[2])%10000, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(gps_data[3]/10, DEC);
  data_transmitter.print(".");
  data_transmitter.print(abs(gps_data[3])%10, DEC);

  data_transmitter.println(">");
}

