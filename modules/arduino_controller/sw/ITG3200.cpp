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

#include "ITG3200.h"
#include <Wire.h>

void ITG3200Driver::SetUp() {
  WriteChar(DLPF, FS_SEL<<3 | DLPF_CFG);
}

void ITG3200Driver::Callback(Print &data_transmitter) {
  uint16_t output_X;
  uint16_t output_Y;
  uint16_t output_Z;
  
  output_X = ReadWord(GYRO_XOUT_H);
  output_Y = ReadWord(GYRO_YOUT_H);
  output_Z = ReadWord(GYRO_ZOUT_H);

  Serial.print("<");
  Serial.print(output_X, DEC);
  Serial.print(", ");
  Serial.print(output_Y, DEC);
  Serial.print(", ");
  Serial.print(output_Z, DEC);
  Serial.println(">");
}
