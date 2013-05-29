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

#ifndef GPSREADER_H
#define GPSREADER_H

#include <Arduino.h>

enum GPSDataFileds
{
  UTCTime = 0,
  Latitude,
  NSIndicator,
  Longitude,
  EWIndicator,
  PositionFixIndicator,
  SatellitesUsed,
  HDOP,
  MSLAltitude,
  MSLAltitudeUnits,
  GeoidSeparation,
  GeoidSeparationUnits,
  AgeOfDiffCorr,
  DiffReffStationID,
  NoDataFields
};

#define MaxDataLenght 16

enum GPSState
{
  WaitForStart,
  ReadHeader,
  ReadData,
  DataOK
};

class Stream;

class GPSReader
{
public:
  GPSReader();

  void fetchPositionData(Stream &port);
  char *getRawData(uint8_t field);
  
protected:
  GPSState state;
  char incommingDataBuffers[NoDataFields][MaxDataLenght];
  
  uint8_t currentFieldReading;
  uint8_t currentFieldReadingPos;

  void evaluateStateMachine(Stream &port);
};

#endif
