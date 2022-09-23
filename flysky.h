#ifndef FLYSKY_H
#define FLYSKY_H
#include <Arduino.h>
#include <IBusBM.h>

class Flysky {
public:
  IBusBM ibus;

  Flysky();

  static void readSerial();

  virtual int readChannel(byte channelInput, int minLimit, int maxLimit,
                          int defaultValue);
  virtual bool readSwitch(byte channelInput, bool defaultValue);

};

#endif
