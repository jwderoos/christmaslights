#include "ModeInterface.h"
#include <Arduino.h>

#include "esphome/components/output/float_output.h"

ModeInterface::ModeInterface(
            esphome::output::FloatOutput *strand1,
            esphome::output::FloatOutput *strand2,
            int waitFactor
)  {
    strand1_ = strand1;
    strand2_ = strand2;
    waitFactor_ = waitFactor;    
}

void ModeInterface::loop() {
    if (lastStep_ + waitFactor_ < millis()) {
        this->tick();
        lastStep_ = millis();
    }
}

void ModeInterface::setStrand1State(float newState) {
    strand1State_ = newState;
    strand1_->set_level(newState);
    if (strand1State_ == 0) {
        strand1_->turn_off();
    } else {
        setStrand2State(0);
    }
}

void ModeInterface::setStrand2State(float newState) {
    strand2State_ = newState;
    strand2_->set_level(newState);
    if (strand2State_ == 0) {
        strand2_->turn_off();
    } else {
        setStrand1State(0);
    }
}
