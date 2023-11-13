#include "ModeController.h"
#include "ModeInterface.h"
#include <Arduino.h>
#include <list>

#include "BlinkOne.h"

void ModeController::init() {
    modes_ = {};
    modes_.push_back(new BlinkOne(strand1_, strand2_, waitFactor_));
    // modes_.push_back(new BlinkOne(strand2_, strand1_, waitFactor_));

    modes_.front()->init();

    lastStep_ = millis();
}

void ModeController::loop() {
    if (lastStep_ + (waitFactor_ * 100) < millis()) {
        // modes_.push_back(modes_.front());
        // modes_.erase(modes_.begin());

        modes_.front()->init();
        lastStep_ = millis();
    }

    modes_.front()->loop();
}

void ModeController::tick() {
    
}