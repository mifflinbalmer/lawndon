#include "flysky.h"
#include <Arduino.h>

IBusBM ibus;
Flysky flysky;

Flysky::Flysky() {}

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
int Flysky::readChannel(byte channelInput, int minLimit, int maxLimit,
                        int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);

  if (ch < 100) {
    return defaultValue;
  }

  return map(ch, 1000, 2000, minLimit, maxLimit);
};

void Flysky::setup() {}

void Flysky::loop() {
  for (byte i = 0; i < 5; i++) {
    int value = readChannel(i, -100, 100, 0);
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(" | ");
  }

  Serial.println();

  delay(10);
}
