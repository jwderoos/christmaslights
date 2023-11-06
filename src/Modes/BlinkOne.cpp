#include "BlinkOne.h"
#include <Arduino.h>

void BlinkOne::init() {
    digitalWrite(pinOne, LOW);
    digitalWrite(pinTwo, LOW);
    lastStep = millis();
}

void BlinkOne::tick() {
    digitalWrite(pinOne, !digitalRead(pinOne));
}