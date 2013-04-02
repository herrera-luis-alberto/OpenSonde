#include "BMP085Driver.h"
#include "ITG3200.h"
#include <Wire.h>

BMP085Driver bmp085;
ITG3200Driver gyroscope;

/** SetUp itinialize all peripheral drivers. */
void setup()
{
  Serial.begin(9600);
  Serial.println("INIT");
  Wire.begin();
  gyroscope.SetUp();
}

/** Loop call the callback function of the drivers. */
void loop()
{
  gyroscope.Callback();
  delay(1000);
}
