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

#include "BMP085Driver.h"
#include "ITG3200.h"
#include "Sensirion.h"
#include "SerialTransmitter.h"
#include "gps.h"
#include <Wire.h>
#include <avr/wdt.h>

BMP085Driver bmp085;
ITG3200Driver gyroscope;
SensirionDriver sensirion;
SerialTransmitterDriver transmitter;
GPSDriver gps;

/** SetUp itinialize all peripheral drivers. */
void setup()
{
  wdt_disable();
  wdt_enable (WDTO_2S);
  Wire.begin();
  transmitter.SetUp();
  transmitter.println("INIT");
  bmp085.SetUp();
  sensirion.SetUp();
  gps.SetUp();
}

/** Loop call the callback function of the drivers. */
void loop()
{
  wdt_reset();
  bmp085.Poll(transmitter);
  sensirion.Poll(transmitter);
  gps.Poll(transmitter);
  wdt_reset();
  delay(1000);
}
