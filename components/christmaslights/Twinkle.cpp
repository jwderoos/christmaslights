#include "Twinkle.h"
#include "ModeInterface.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void Twinkle::init() {
    this->next = new BlinkOne(strand1_, strand2_, waitFactor_ / 8);
    this->current = new BlinkOne(strand2_, strand1_, waitFactor_ / 4);

    this->current->init();
    lastStep_ = millis();
}

void Twinkle::loop() {
    
    if (lastStep_ + waitFactor_ < millis()) {
        ModeInterface* last = this->current;
        this->current = this->next;
        this->next = last;

        this->current->init();
        lastStep_ = millis();
    }

    current->loop();
}

void Twinkle::tick() {
    
}