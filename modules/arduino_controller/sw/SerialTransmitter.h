#include "Driver.h"

class SerialTransmitterDriver : public Driver, public Print {
public:
  virtual uint8_t DeviceAddress() { return 0x4D; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
  virtual size_t write(uint8_t);
private:
  // Writes the register for channel A.
  void WriteRegister(uint8_t reg, uint8_t data);
  uint8_t ReadRegister(uint8_t reg);
  // Configurations
  // Register addresses
  const unsigned char THR = 0x00;
  const unsigned char FCR = 0x02;
  const unsigned char LCR = 0x03;
  const unsigned char IOControl = 0x0E;
  const unsigned char LSR = 0x05;
  const unsigned char TXLVL = 0x08;

  const unsigned char DLL = 0x00;
  const unsigned char DLH = 0x01;
};
