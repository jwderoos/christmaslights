#include "ModeController.h"
#include "ModeInterface.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void ModeController::init() {
    this->next = new BlinkOne(strand1_, strand2_, waitFactor_);
    this->current = new BlinkOne(strand2_, strand1_, waitFactor_);

    this->current->init();
    lastStep_ = millis();
}

void ModeController::step() {
    if (lastStep_ + (waitFactor_ * 100) < millis()) {
        ModeInterface* last = this->current;
        this->current = this->next;
        this->next = last;

        this->current->init();
        lastStep_ = millis();
    }

    current->step();
}

void ModeController::tick() {
    
}