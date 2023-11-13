#pragma once

#include "BlinkOne.h"
#include "ModeInterface.h"

class AlternateTwinkle: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        AlternateTwinkle(
            esphome::output::FloatOutput *strand1,
            esphome::output::FloatOutput *strand2,
            int waitFactor
        );
        void init();
        void loop();
    protected:
        void tick();
    private:
        ModeInterface* current;
        ModeInterface* next;
};