#include "flysky.h"
#include <Arduino.h>


Flysky::readSerial() {
  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"
  for (byte i = 0; i < 5; i++) {
    int value = Flysky::readChannel(i, -100, 100, 0);
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(" | ");
  }

  // Print channel 6 (switch) boolean value
  Serial.print("Ch6: ");
  Serial.print(Flysky::readSwitch(5, false));
  Serial.println();

  delay(10);
}

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
Flysky::readChannel(int channelInput, int minLimit, int maxLimit,
                    int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);

  if (ch < 100) {
    return defaultValue;
  }

  return map(ch, 1000, 2000, minLimit, maxLimit);
};

// Read the channel and return a boolean value
Flysky::readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);

  return (ch > 50);
};
