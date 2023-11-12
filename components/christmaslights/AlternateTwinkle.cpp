#include "ModeInterface.h"
#include "AlternateTwinkle.h"
#include "Twinkle.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void AlternateTwinkle::init() {
    this->next = new Twinkle(strand1_, strand2_, waitFactor_);
    this->current = new Twinkle(strand2_, strand1_, waitFactor_);

    this->current->init();
    lastStep_ = millis();
}

void AlternateTwinkle::loop() {
    if (lastStep_ + (waitFactor_ * 2) < millis()) {
        ModeInterface* last = this->current;
        this->current = this->next;
        this->next = last;

        this->current->init();
        lastStep_ = millis();
    }

    current->loop();
}

void AlternateTwinkle::tick() {
}