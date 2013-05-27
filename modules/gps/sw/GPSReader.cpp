#include "GPSReader.h"

const char *expectedHeader = "GPGGA,";
const uint8_t expectedHeaderSize = 6;

GPSReader::GPSReader() {
  state = WaitForStart;
}

void GPSReader::fetchPositionData(Stream &port) {
  currentFieldReading = 0;
  currentFieldReadingPos = 0;
  state = WaitForStart;
  
  while ( state != DataOK )
    evaluateStateMachine(port);
}

char *GPSReader::getRawData( uint8_t field ) {
  return incommingDataBuffers[field];
}


void GPSReader::evaluateStateMachine(Stream &port) {
  char inChar;
  switch ( state ) {
    case WaitForStart:
      while(Serial.available() == 0) {}
      inChar = port.read();
      if ( inChar == '$' )
        state = ReadHeader;
      break;
    case ReadHeader:
      for (uint8_t i=0; i<expectedHeaderSize; i++) {
        while(Serial.available() == 0) {}
        inChar = port.read();
        if ( inChar != expectedHeader[i] ) {
          state = WaitForStart;
          return;
        }
      }
      state = ReadData;
      break;
    case ReadData:
      while(Serial.available() == 0) {}
      inChar = port.read();
      if ( inChar == '.' ) {
        return;
      }
      if ( inChar == '*' ) {
        incommingDataBuffers[currentFieldReading][currentFieldReadingPos] = '\0';
        state = DataOK;
        return;
      }
      if ( inChar == ',' ) {
        incommingDataBuffers[currentFieldReading][currentFieldReadingPos] = '\0';
        currentFieldReading++;
        currentFieldReadingPos = 0;
        return;
      }
      incommingDataBuffers[currentFieldReading][currentFieldReadingPos++] = inChar;
      break;
    case DataOK:
      break;
  }
}
