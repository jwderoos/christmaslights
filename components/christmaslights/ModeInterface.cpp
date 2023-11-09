#include "ModeInterface.h"
#include <Arduino.h>

ModeInterface::ModeInterface(int pinOne, int pinTwo, int waitFactor)  {
    this->pinOne = pinOne;
    this->pinTwo = pinTwo;
    this->waitFactor = waitFactor;
}

void ModeInterface::step() {
    if (lastStep + waitFactor < millis()) {
        this->tick();
        lastStep = millis();
    }
}
