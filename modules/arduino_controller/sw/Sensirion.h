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

class SensirionDriver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x29; };
  virtual void SetUp();
  virtual void Poll(Print &data_transmitter);
private:
};
