
#pragma once

#include "esphome/core/component.h"

// #include <Arduino.h>
#include "Modes/ModeInterface.h"

#define TEST_MODE true

#define GPIO0 0 // gpio0 
#define TX_PIN 1 //gpio1 // programmer led (BLUE)
#define GPIO2 2 // gpio2 // internal led 
#define RX_PIN 3 //gpio3 // programmer led (green)

#if TEST_MODE 
  #define LED_STRAND_1 TX_PIN
  #define LED_STRAND_2 RX_PIN
  #define DEFAULT HIGH
#else
  #define LED_STRAND_1 GPIO0
  #define LED_STRAND_2 RX_PIN
  #define DEFAULT LOW
#endif


namespace jwdr {
namespace christmas_lights {

class ChristmasLights : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace empty_component
}  // namespace esphome

