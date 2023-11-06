#include "ModeInterface.h"
#include <Arduino.h>

ModeInterface::ModeInterface(int pinOne, int pinTwo, int waitFactor)  {
    this->pinOne = pinOne;
    this->pinTwo = pinTwo;
    this->waitFactor = waitFactor;

    digitalWrite(this->pinOne, LOW);
    digitalWrite(this->pinTwo, LOW);
}

void ModeInterface::step() {
    if (lastStep + waitFactor < millis()) {
        this->tick();
        lastStep = millis();
    }
}
