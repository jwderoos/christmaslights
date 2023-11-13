#include "Alternate.h"
#include <Arduino.h>

void Alternate::init() {
    setStrand1State(1);
    lastStep_ = millis();
}

void Alternate::tick() {
    // if (strand1State_) {
        setStrand2State(1);
        delay(waitFactor_);
        setStrand1State(1);
    // } else {
        // setStrand1State(1);
    // }
}