#include <Wire.h>
#include "Sensirion.h"

#define SLAVE_ADDRESS 0x29
#define TEMP_REG 0x00
#define HUMI_REG 0x02
#define REG_SIZE 0x04

#define sensirionDataPin 6
#define sensirionClockPin 7

Sensirion sensirion = Sensirion( sensirionDataPin, sensirionClockPin);

uint8_t Registers[REG_SIZE];

void requestEvent();

void setup() {
  Serial.begin(19200);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);
  Serial.println("Init");
}

void loop() {
  Serial.print(":");

  uint16_t temperature;
  uint16_t humidity;
  uint8_t *p_temperature = (uint8_t *)&temperature;
  uint8_t *p_humidity = (uint8_t *)&humidity;

  sensirion.measTemp(&temperature);
  sensirion.measHumi(&humidity);

  Registers[TEMP_REG+1] = *p_temperature;
  Registers[TEMP_REG] = *(p_temperature+1);
  Registers[HUMI_REG+1] = *p_humidity;
  Registers[HUMI_REG] = *(p_humidity+1);

  Serial.print(temperature);
  Serial.print(" ");
  Serial.println(humidity);
  delay(4000);
}

void requestEvent() {
       Wire.write(Registers, REG_SIZE);
}
