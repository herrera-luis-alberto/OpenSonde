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

#ifndef DRIVER_H_
#define DRIVER_H_
/* Driver class */
#include <Arduino.h>

class Driver{
public:
  /// Return the device address of the device.
  virtual uint8_t DeviceAddress()=0;
  /// Called at the begging. You can initialize your device here.
  virtual void SetUp()=0;
  /// this function will be called by the controller to pull data from your
  /// device.
  virtual void Callback(Print &data_transmitter)=0;
protected:
  /// Reads one byte from address.
  uint8_t ReadChar(uint8_t address);
  /// Read two bytes from address and adress+1. MSB first.
  uint16_t ReadWord(uint16_t address);
  /// Write a byte.
  void WriteChar(uint8_t address, uint8_t data);
};
#endif  // DRIVER_H_
