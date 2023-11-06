#include "ModeController.h"
#include "ModeInterface.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void ModeController::init() {
    this->next = new BlinkOne(pinOne, pinTwo, waitFactor);
    this->current = new BlinkOne(pinTwo, pinOne, waitFactor);

    digitalWrite(pinOne, LOW);
    digitalWrite(pinTwo, LOW);
    lastStep = millis();
}

void ModeController::step() {
    
    if (lastStep + waitFactor * 100 < millis()) {
        ModeInterface* last = this->current;
        this->current = this->next;
        this->next = last;

        this->current->init();
        lastStep = millis();
    }

    current->step();
}

void ModeController::tick() {
    
}