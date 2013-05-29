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

#include "GPSReader.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x30
#define REG_SIZE 4

long Registers[REG_SIZE];
GPSReader reader;

void requestEvent();

void setup() {
  for (uint8_t i = 0; i < REG_SIZE; i++) {
    Registers[i] = 2*i;
  }
  Serial.begin(19200);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);
  Serial.println("Init");
}

void loop() {
  char parsing_buffer[32];
  Serial.println("> ");
  reader.fetchPositionData(Serial);
  Registers[0] = atol(reader.getRawData(UTCTime));
  if (reader.getRawData(NSIndicator)[0] == 'S') {
    strcpy(parsing_buffer, "-");
  } else {
    strcpy(parsing_buffer, "");
  }
  strcat(parsing_buffer, reader.getRawData(Latitude));
  Registers[1] = atol(parsing_buffer);
  if (reader.getRawData(EWIndicator)[0] == 'W') {
    strcpy(parsing_buffer, "-");
  } else {
    strcpy(parsing_buffer, "");
  }
  strcat(parsing_buffer, reader.getRawData(Longitude));
  Registers[2] = atol(parsing_buffer);
  Registers[3] = atol(reader.getRawData(MSLAltitude));

  Serial.println(Registers[0]);
  Serial.println(Registers[1]);
  Serial.println(Registers[2]);
  Serial.println(Registers[3]);
  Serial.println("OK");
}

void requestEvent() {
  Wire.write((uint8_t*)Registers, REG_SIZE*sizeof(long));
}
