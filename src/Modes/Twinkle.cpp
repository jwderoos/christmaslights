#include "Twinkle.h"
#include "ModeInterface.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void Twinkle::init() {
    this->next = new BlinkOne(pinOne, pinTwo, waitFactor / 8);
    this->current = new BlinkOne(pinTwo, pinOne, waitFactor / 4);

    this->current->init();
    lastStep = millis();
}

void Twinkle::step() {
    
    if (lastStep + waitFactor < millis()) {
        ModeInterface* last = this->current;
        this->current = this->next;
        this->next = last;

        this->current->init();
        lastStep = millis();
    }

    current->step();
}

void Twinkle::tick() {
    
}