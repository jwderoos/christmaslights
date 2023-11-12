#include "BlinkOne.h"
#include <Arduino.h>

#include "esphome/core/log.h"

void BlinkOne::init() {
    setStrand1State(0);
    setStrand2State(0);
    lastStep_ = 0;
}

void BlinkOne::tick() {
    ESP_LOGE("bla", "");
    if (strand1State_) {
        setStrand1State(1);
    }else {
        setStrand1State(0);
    }
}