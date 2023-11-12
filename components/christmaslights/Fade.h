#pragma once

#include "ModeInterface.h"

class Fade: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
        Fade(
            esphome::output::FloatOutput *strand1,
            esphome::output::FloatOutput *strand2,
            int waitFactor,
            float fadeStep
        ) :ModeInterface(strand1, strand2, waitFactor) {
            fadeStep_ = fadeStep;
        }
    protected:
        float fadeStep_;
        float current_;
        bool primary_ = true;
        void tick();
};