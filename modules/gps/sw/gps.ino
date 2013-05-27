#include "GPSReader.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x30
#define REG_SIZE 4

long Registers[REG_SIZE];
GPSReader reader;

void requestEvent();

void setup() {
  for (uint8_t i = 0; i < REG_SIZE; i++) {
    Registers[i] = 2*i;
  }
  Serial.begin(19200);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);
  Serial.println("Init");
}

void loop() {
  char parsing_buffer[32];
  Serial.println("> ");
  reader.fetchPositionData(Serial);
  Registers[0] = atol(reader.getRawData(UTCTime));
  if (reader.getRawData(NSIndicator)[0] == 'S') {
    strcpy(parsing_buffer, "-");
  } else {
    strcpy(parsing_buffer, "");
  }
  strcat(parsing_buffer, reader.getRawData(Latitude));
  Registers[1] = atol(parsing_buffer);
  if (reader.getRawData(EWIndicator)[0] == 'W') {
    strcpy(parsing_buffer, "-");
  } else {
    strcpy(parsing_buffer, "");
  }
  strcat(parsing_buffer, reader.getRawData(Longitude));
  Registers[2] = atol(parsing_buffer);
  Registers[3] = atol(reader.getRawData(MSLAltitude));

  Serial.println(Registers[0]);
  Serial.println(Registers[1]);
  Serial.println(Registers[2]);
  Serial.println(Registers[3]);
  Serial.println("OK");
}

void requestEvent() {
  Wire.write((uint8_t*)Registers, REG_SIZE*sizeof(long));
}
