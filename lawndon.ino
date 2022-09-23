#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

#include "flysky.h"
#include <IBusBM.h>

static IBusBM ibus;

void setup() {
  // Start serial monitor
  Serial.begin(115200);

  // Attach iBus object to serial port
  ibus.begin(Serial1);
}

void loop() {
  Flysky::readSerial(){};
}
