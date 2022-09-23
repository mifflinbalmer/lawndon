#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>

class Drive {
public:
  int leftDirPin;
  int leftPwmPin;
  int leftBrakePin;

  int rightDirPin;
  int rightPwmPin;
  int rightBrakePin;

  Drive();

  virtual void setup();

  virtual void loop();

  virtual void setDirection(int directionPin, char state);
  virtual void setBrake(int brakePin, char state);
  virtual void setWorkDuty(int pwmPin, int value);
};

#endif