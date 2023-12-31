#pragma once

#include "esphome/components/output/float_output.h"

class ModeInterface {
    protected:
        esphome::output::FloatOutput *strand1_;
        esphome::output::FloatOutput *strand2_;
        float strand1State_ = 0;
        float strand2State_ = 0;
        int waitFactor_;
        unsigned long lastStep_;
        void setStrand1State(float newState);
        void setStrand2State(float newState);
    public:
        ModeInterface(
            esphome::output::FloatOutput *strand1,
            esphome::output::FloatOutput *strand2,
            int waitFactor
        );
        virtual void init() = 0;
        virtual void loop();
    protected:
        virtual void tick() = 0;
};