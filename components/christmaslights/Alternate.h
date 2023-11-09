#pragma once

#include "ModeInterface.h"

class Alternate: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
    protected:
        void tick();
};