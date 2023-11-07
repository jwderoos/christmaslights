#include "ModeInterface.h"
#include "AlternateTwinkle.h"
#include "Twinkle.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void AlternateTwinkle::init() {
    this->next = new Twinkle(pinOne, pinTwo, waitFactor);
    this->current = new Twinkle(pinTwo, pinOne, waitFactor);

    this->current->init();
    lastStep = millis();
}

void AlternateTwinkle::step() {
    if (lastStep + (waitFactor * 2) < millis()) {
        ModeInterface* last = this->current;
        this->current = this->next;
        this->next = last;

        this->current->init();
        lastStep = millis();
    }

    current->step();
}

void AlternateTwinkle::tick() {
}