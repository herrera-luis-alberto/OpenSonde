#include "Driver.h"

class ITG3200Driver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x69; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
private:
  // Configurations
  const unsigned char FS_SEL = 3;
  const unsigned char DLPF_CFG = 3;
  // Register addresses
  const unsigned char DLPF =  0x16;
  const unsigned char GYRO_XOUT_H = 0x1D;
  const unsigned char GYRO_YOUT_H = 0x1F;
  const unsigned char GYRO_ZOUT_H = 0x21;


};
