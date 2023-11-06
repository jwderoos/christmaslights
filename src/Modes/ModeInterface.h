#pragma once

class ModeInterface {
    protected:
        int pinOne, pinTwo, waitFactor;
        unsigned long lastStep;
    public:
        ModeInterface(int pinOne, int pinTwo, int waitFactor);
        virtual void init() = 0;
        virtual void step();
    protected:
        virtual void tick() = 0;
};