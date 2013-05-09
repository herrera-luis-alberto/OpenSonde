#include "SerialTransmitter.h"
#include <Wire.h>

void SerialTransmitterDriver::SetUp() {
  // Software reset.
  WriteRegister(IOControl, 0x08);
  // Enable divisor latch.
  WriteRegister(LCR, 0x80);
  // Set baudrato 1200 bps.
  WriteRegister(DLL, 0x41);
  WriteRegister(DLH, 0x03);
  // 8bits, no parity, 1 stop bit.
  WriteRegister(LCR, 0x03);
  // Reset and enable FIFO.
  WriteRegister(FCR, 0x07);
}

void SerialTransmitterDriver::Callback(Print &data_transmitter) {
  // do nothing
}

size_t SerialTransmitterDriver::write(uint8_t c) {
  // busy waiting for data in the transmitting FIFO.
  while(ReadRegister(LSR) & 0x10 == 0){
  }
  WriteRegister(THR, c);
}

void SerialTransmitterDriver::WriteRegister(uint8_t reg, uint8_t data) {
  WriteChar(reg<<3, data);
}

uint8_t SerialTransmitterDriver::ReadRegister(uint8_t reg) {
  return ReadChar(reg<<3 | 0x80);
}
