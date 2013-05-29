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

class ITG3200Driver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x69; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
private:
  // Configurations
  const unsigned char FS_SEL = 3;
  const unsigned char DLPF_CFG = 3;
  // Register addresses
  const unsigned char DLPF =  0x16;
  const unsigned char GYRO_XOUT_H = 0x1D;
  const unsigned char GYRO_YOUT_H = 0x1F;
  const unsigned char GYRO_ZOUT_H = 0x21;


};
