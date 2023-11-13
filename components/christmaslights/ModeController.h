#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"
#include "esphome/core/helpers.h"
#include "ModeInterface.h"
#include <vector>

class ModeController: public ModeInterface {
    public:
        using ModeInterface::ModeInterface;
        ModeController(
            esphome::output::FloatOutput *strand1,
            esphome::output::FloatOutput *strand2,
            int waitFactor
        );
        void init();
        void loop() override;
    protected:
        void tick();
    private:
        // std::shared_ptr<ModeInterface> current_;
        std::vector<std::shared_ptr<ModeInterface>> modes_;
};