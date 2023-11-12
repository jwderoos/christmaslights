#pragma once

#include "ModeInterface.h"
#include "Fade.h"
#include "esphome/components/output/float_output.h"

class FadeInOut: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
    protected:
        Fade *fadeIn_;
        Fade *fadeOut_;
        float current_;
        bool in_ = true;
        void tick();
};