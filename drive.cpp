#include "drive.h"
#include "flysky.h"
#include <Arduino.h>

Drive drive;

Drive::Drive(){
  flySkyConfigString = "123flyme321";
};

void Drive::setup() {
  Serial.begin(CONSOLE_BAUDRATE);
  Serial.println(F("SETUP"));

  pinMode(leftDirPin, OUTPUT);
  pinMode(leftPwmPin, OUTPUT);
  pinMode(leftBrakePin, OUTPUT);

  pinMode(rightDirPin, OUTPUT);
  pinMode(rightPwmPin, OUTPUT);
  pinMode(rightBrakePin, OUTPUT);

  Flysky::setup();

  Serial.println(F("Sending Flysky Config"));
  Serial1.begin(FLYSKY_BAUDRATE);
  Serial1.println(flySkyConfigString);
}

void Drive::setDirection(int directionPin, char state) {
  digitalWrite(directionPin, state);
};

void Drive::setBrake(int brakePin, char state) {
  digitalWrite(brakePin, state);
};

void Drive::setWorkDuty(int pwmPin, int value) {
  analogWrite(pwmPin, value);
}