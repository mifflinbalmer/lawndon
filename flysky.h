#ifndef FLYSKY_H
#define FLYSKY_H
#include <Arduino.h>
#include <IBusBM.h>

class Flysky {
public:
  String flySkyConfigString = "";

  Flysky();
  virtual void setup();

  virtual void loop();

  virtual int readChannel(byte channelInput, int minLimit, int maxLimit,
                          int defaultValue);
};

extern IBusBM ibus;
extern Flysky flysky;

#endif
