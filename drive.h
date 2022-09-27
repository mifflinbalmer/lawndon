#ifndef DRIVE_H
#define DRIVE_H
#include "flysky.h"
#include <Arduino.h>

// pin defs
#define leftDirPin 12
#define leftPwmPin 3
#define leftBrakePin 9

#define rightDirPin 13
#define rightPwmPin 11
#define rightBrakePin 8

// baudrates
#define CONSOLE_BAUDRATE 19200
#define FLYSKY_BAUDRATE 115200

// serial ports
#define Console Serial
#define Flyskyport Serial1

class Drive : public Flysky {
public:
  Drive();

  virtual void setup(void);

  virtual void setDirection(int directionPin, char state);
  virtual void setBrake(int brakePin, char state);
  virtual void setWorkDuty(int pwmPin, int value);
};

extern Drive drive;

#endif