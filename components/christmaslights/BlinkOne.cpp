#include "BlinkOne.h"
#include <Arduino.h>

void BlinkOne::init() {
    digitalWrite(pinOne, DEFAULT);
    digitalWrite(pinTwo, DEFAULT);
    lastStep = millis();
}

void BlinkOne::tick() {
    digitalWrite(pinOne, !digitalRead(pinOne));
}