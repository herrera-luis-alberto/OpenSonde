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
