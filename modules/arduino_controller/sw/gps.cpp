
#include "gps.h"
#include <Wire.h>

void GPSDriver::SetUp() {
}

void GPSDriver::Callback(Print &data_transmitter) {
  const uint8_t gps_fields_number = 4;
  const uint8_t bytes_to_transfer = gps_fields_number*sizeof(long);
  long gps_data[gps_fields_number];
  char *buffer = (char *)gps_data;

  Wire.requestFrom(DeviceAddress(), bytes_to_transfer);
  while(Wire.available() < bytes_to_transfer)
    ;

  for (uint8_t i=0; i<bytes_to_transfer; i++) {
    buffer[i] = Wire.read();
  }

  data_transmitter.print("<");
  data_transmitter.print(DeviceAddress(), HEX);
  
  data_transmitter.print(",");
  data_transmitter.print(gps_data[0]/1000, DEC);
  data_transmitter.print(".");
  data_transmitter.print(gps_data[0]%1000, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(gps_data[1]/10000, DEC);
  data_transmitter.print(".");
  data_transmitter.print(abs(gps_data[1])%10000, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(gps_data[2]/10000, DEC);
  data_transmitter.print(".");
  data_transmitter.print(abs(gps_data[2])%10000, DEC);
  data_transmitter.print(", ");
  data_transmitter.print(gps_data[3]/10, DEC);
  data_transmitter.print(".");
  data_transmitter.print(abs(gps_data[3])%10, DEC);

  data_transmitter.println(">");
}

