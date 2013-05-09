#include "BMP085Driver.h"
#include "ITG3200.h"
#include "Sensirion.h"
#include "SerialTransmitter.h"
#include <Wire.h>

BMP085Driver bmp085;
ITG3200Driver gyroscope;
SensirionDriver sensirion;
SerialTransmitterDriver transmitter;

/** SetUp itinialize all peripheral drivers. */
void setup()
{
  Wire.begin();
  transmitter.SetUp();
  transmitter.println("INIT");
  bmp085.SetUp();
  //gyroscope.SetUp();
  sensirion.SetUp();

}

/** Loop call the callback function of the drivers. */
void loop()
{
  bmp085.Callback(transmitter);
  sensirion.Callback(transmitter);
  delay(1000);
}
