#pragma once

#include "ModeInterface.h"
#include "Fade.h"
#include "esphome/components/output/float_output.h"

class FadeInOut: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        FadeInOut(
            esphome::output::FloatOutput *strand1,
            esphome::output::FloatOutput *strand2,
            int waitFactor
        );
        void init();
    protected:
        Fade *fadeIn_;
        Fade *fadeOut_;
        float current_;
        bool in_ = true;
        void tick();
};