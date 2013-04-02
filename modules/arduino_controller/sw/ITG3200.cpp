
#include "ITG3200.h"
#include <Wire.h>

void ITG3200Driver::SetUp() {
  WriteChar(DLPF, FS_SEL<<3 | DLPF_CFG);
}

void ITG3200Driver::Callback() {
  uint16_t output_X;
  uint16_t output_Y;
  uint16_t output_Z;
  
  output_X = ReadWord(GYRO_XOUT_H);
  output_Y = ReadWord(GYRO_YOUT_H);
  output_Z = ReadWord(GYRO_ZOUT_H);

  Serial.print("<");
  Serial.print(output_X, DEC);
  Serial.print(", ");
  Serial.print(output_Y, DEC);
  Serial.print(", ");
  Serial.print(output_Z, DEC);
  Serial.println(">");
}
