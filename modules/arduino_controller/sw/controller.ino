#include "BMP085Driver.h"
#include <Wire.h>

BMP085Driver bmp085;

/** SetUp itinialize all peripheral drivers. */
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  bmp085.SetUp();
}

/** Loop call the callback function of the drivers. */
void loop()
{
  bmp085.Callback();
  delay(1000);
}
