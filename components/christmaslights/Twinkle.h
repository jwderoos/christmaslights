#pragma once

#include "BlinkOne.h"
#include "ModeInterface.h"

class Twinkle: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
        void loop();
    protected:
        void tick();
    private:
        ModeInterface* current;
        ModeInterface* next;
};