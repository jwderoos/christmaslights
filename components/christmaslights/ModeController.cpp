#include "ModeController.h"

#include "esphome/core/log.h"
#include <Arduino.h>
#include "BlinkOne.h"
#include "Alternate.h"
#include "Fade.h"
#include "Twinkle.h"
#include "AlternateTwinkle.h"
#include "FadeInOut.h"

ModeController::ModeController(
    esphome::output::FloatOutput *strand1,
    esphome::output::FloatOutput *strand2,
    int waitFactor
): ModeInterface(strand1, strand2, waitFactor) {
    modes_.push_back(std::make_shared<BlinkOne>(strand1_, strand2_, waitFactor_));
    modes_.push_back(std::make_shared<Alternate>(strand1_, strand2_, 1000));
    modes_.push_back(std::make_shared<FadeInOut>(strand1_, strand2_, 5));
    modes_.push_back(std::make_shared<BlinkOne>(strand2_, strand1_, waitFactor_));
    modes_.push_back(std::make_shared<AlternateTwinkle>(strand1_, strand2_, 800));
    modes_.push_back(std::make_shared<Alternate>(strand1_, strand2_, 5)); // permanent on

    lastStep_ = millis();
}

void ModeController::init() {
}

void ModeController::loop() {
    if (lastStep_ + (waitFactor_ * 500) < millis()) {
        modes_.push_back(modes_.front());
        modes_.erase(modes_.begin());

        lastStep_ = millis();
    }

    modes_.front()->loop();
}

void ModeController::tick() {
}
