#include "Alternate.h"
#include <Arduino.h>

void Alternate::init() {
    digitalWrite(pinOne, !DEFAULT);
    digitalWrite(pinTwo, DEFAULT);
    lastStep = millis();
}

void Alternate::tick() {
    digitalWrite(pinOne, !digitalRead(pinOne));
    digitalWrite(pinTwo, !digitalRead(pinTwo));
}