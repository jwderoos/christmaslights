
#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"

#include "ModeInterface.h"

// #define TEST_MODE true

// #define GPIO0 0 // gpio0 
// #define TX_PIN 1 //gpio1 // programmer led (BLUE)
// #define GPIO2 2 // gpio2 // internal led 
// #define RX_PIN 3 //gpio3 // programmer led (green)

// #if TEST_MODE 
//   #define LED_STRAND_1 TX_PIN
//   #define LED_STRAND_2 RX_PIN
//   #define DEFAULT HIGH
// #else
//   #define LED_STRAND_1 GPIO0
//   #define LED_STRAND_2 RX_PIN
//   #define DEFAULT LOW
// #endif


namespace esphome {
  namespace christmas_lights {
    class ChristmasLights :  public Component {
      private:
        ModeInterface *module_;
        bool enabled_;
        output::FloatOutput *strand1_;
        output::FloatOutput *strand2_;
      public:
        void setup() override;
        void loop() override;
        void set_enabled(bool enabled) { 
          enabled_ = enabled; 
          strand1_->turn_off();
          strand2_->turn_off();
        }
        void set_strand1(output::FloatOutput *strand1) { strand1_ = strand1; }
        void set_strand2(output::FloatOutput *strand2) { strand2_ = strand2; }
        void dump_config() override;
    };


  }  // namespace empty_component
}  // namespace esphome

