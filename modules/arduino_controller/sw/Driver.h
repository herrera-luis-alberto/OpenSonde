#ifndef DRIVER_H_
#define DRIVER_H_
/* Driver class */
#include <Arduino.h>

class Driver{
public:
  /// Return the device address of the device.
  virtual uint8_t DeviceAddress()=0;
  /// Called at the begging. You can initialize your device here.
  virtual void SetUp()=0;
  /// this function will be called by the controller to pull data from your
  /// device.
  virtual void Callback()=0;
protected:
  /// Reads one byte from address.
  uint8_t ReadChar(uint8_t address);
  /// Read two bytes from address and adress+1. MSB first.
  uint16_t ReadWord(uint16_t address);
  /// Write a byte.
  void WriteChar(uint8_t address, uint8_t data);
};
#endif  // DRIVER_H_
