#include "Driver.h"

class GPSDriver : public Driver {
public:
  virtual uint8_t DeviceAddress() { return 0x30; };
  virtual void SetUp();
  virtual void Callback(Print &data_transmitter);
private:
};
