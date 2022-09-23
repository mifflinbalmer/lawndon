#ifndef FLYSKY_H
#define FLYSKY_H
#include <Arduino.h>

int readChannel(byte channelInput, int minLimit, int maxLimit,
                int defaultValue);
bool readSwitch(byte channelInput, bool defaultValue);

#endif
