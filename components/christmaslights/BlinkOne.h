#pragma once

#include "ModeInterface.h"

class BlinkOne: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
    protected:
        void tick();
};