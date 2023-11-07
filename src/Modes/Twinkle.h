#pragma once

#include "BlinkOne.h"
#include "ModeInterface.h"

class Twinkle: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
        void step();
    protected:
        void tick();
    private:
        ModeInterface* current;
        ModeInterface* next;
};