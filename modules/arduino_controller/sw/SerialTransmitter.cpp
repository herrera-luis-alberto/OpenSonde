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

#include "SerialTransmitter.h"
#include <Wire.h>

void SerialTransmitterDriver::SetUp() {
  // Software reset.
  WriteRegister(IOControl, 0x08);
  // Enable divisor latch.
  WriteRegister(LCR, 0x80);
  // Set baudrato 1200 bps.
  WriteRegister(DLL, 0x41);
  WriteRegister(DLH, 0x03);
  // 8bits, no parity, 1 stop bit.
  WriteRegister(LCR, 0x03);
  // Reset and enable FIFO.
  WriteRegister(FCR, 0x07);
}

void SerialTransmitterDriver::Callback(Print &data_transmitter) {
  // do nothing
}

size_t SerialTransmitterDriver::write(uint8_t c) {
  // busy waiting for data in the transmitting FIFO.
  while(ReadRegister(TXLVL) == 0){
  }
  WriteRegister(THR, c);
}

void SerialTransmitterDriver::WriteRegister(uint8_t reg, uint8_t data) {
  WriteChar(reg<<3, data);
}

uint8_t SerialTransmitterDriver::ReadRegister(uint8_t reg) {
  return ReadChar(reg<<3 | 0x80);
}
