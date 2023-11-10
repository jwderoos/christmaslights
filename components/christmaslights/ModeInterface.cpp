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

void ModeInterface::step() {
    if (lastStep_ + waitFactor_ < millis()) {
        this->tick();
        lastStep_ = millis();
    }
}
