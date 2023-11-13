#pragma once

#include "BlinkOne.h"
#include "ModeInterface.h"
#include <vector>

class ModeController: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        void init();
        void loop();
    protected:
        void tick();
    private:
        std::vector<ModeInterface*> modes_;
};