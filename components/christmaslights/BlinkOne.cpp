#include "BlinkOne.h"
#include <Arduino.h>

void BlinkOne::init() {
    strand1_->turn_off();
    strand2_->turn_off();
    lastStep_ = millis();
}

void BlinkOne::tick() {
    if (strand1State_) {
        setStrand1State(1);
    }else {
        setStrand1State(0);
    }
}