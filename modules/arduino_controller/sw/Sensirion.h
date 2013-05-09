#include "Driver.h"

class SensirionDriver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x29; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
private:
};
