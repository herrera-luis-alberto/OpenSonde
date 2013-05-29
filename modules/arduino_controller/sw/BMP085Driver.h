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

class BMP085Driver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x77; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
private:
  
  /// Oversampling Setting.
  const unsigned char OSS = 0;

  /// Calibration values.
  int ac1;
  int ac2; 
  int ac3; 
  unsigned int ac4;
  unsigned int ac5;
  unsigned int ac6;
  int b1; 
  int b2;
  int mb;
  int mc;
  int md;

  // b5 is calculated in bmp085GetTemperature(...), this variable is also used in bmp085GetPressure(...)
  // so ...Temperature(...) must be called before ...Pressure(...).
  long b5; 
  
  /// Read the uncompensated temperature value.
  unsigned int bmp085ReadUT();
  /// Read the uncompensated pressure value.
  unsigned long bmp085ReadUP();
  /** Calculate temperature given ut.
   * Value returned will be in units of 0.1 deg C. */
  short bmp085GetTemperature(unsigned int ut);
  /** Calculate pressure given up
   * calibration values must be known
   * b5 is also required so bmp085GetTemperature(...) must be called first.
   * Value returned will be pressure in units of Pa.*/
  long bmp085GetPressure(unsigned long up);
};
