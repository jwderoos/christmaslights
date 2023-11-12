#pragma once

#include "ModeInterface.h"

class Fade: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
    protected:
        float current_;
        bool primary_ = true;
        void tick();
};