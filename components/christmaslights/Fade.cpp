#include "Fade.h"
#include <Arduino.h>

#include "esphome/core/log.h"

void Fade::init() {
    setStrand1State(0);
    setStrand2State(1);
    current_ = 0;

    lastStep_ = 0;
}

void Fade::tick() {
    if (current_ >= 1) {
        current_ = 0;
    }

    if (primary_) {
        setStrand1State(current_);
    } else {
        setStrand2State(1 - current_);
    }

    current_ += 0.01;
    primary_ = !primary_;
}