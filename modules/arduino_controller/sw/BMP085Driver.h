#include "Driver.h"

class BMP085Driver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x77; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
private:
  
  /// Oversampling Setting.
  const unsigned char OSS = 0;

  /// Calibration values.
  int ac1;
  int ac2; 
  int ac3; 
  unsigned int ac4;
  unsigned int ac5;
  unsigned int ac6;
  int b1; 
  int b2;
  int mb;
  int mc;
  int md;

  // b5 is calculated in bmp085GetTemperature(...), this variable is also used in bmp085GetPressure(...)
  // so ...Temperature(...) must be called before ...Pressure(...).
  long b5; 
  
  /// Read the uncompensated temperature value.
  unsigned int bmp085ReadUT();
  /// Read the uncompensated pressure value.
  unsigned long bmp085ReadUP();
  /** Calculate temperature given ut.
   * Value returned will be in units of 0.1 deg C. */
  short bmp085GetTemperature(unsigned int ut);
  /** Calculate pressure given up
   * calibration values must be known
   * b5 is also required so bmp085GetTemperature(...) must be called first.
   * Value returned will be pressure in units of Pa.*/
  long bmp085GetPressure(unsigned long up);
};
