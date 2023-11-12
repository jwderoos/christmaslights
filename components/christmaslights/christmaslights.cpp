#include "christmaslights.h"

#include "esphome/core/log.h"

#include "ModeController.h"
#include "Alternate.h"
#include "Twinkle.h"
#include "AlternateTwinkle.h"

namespace esphome {
      namespace christmas_lights {
            void ChristmasLights::setup() {
                  module_ = new BlinkOne(strand1_, strand2_, 250);

                  // module = new ModeController(strand1_, strand2_, 250);
                  // module = new Alternate(strand1_, strand2_, 5); //steady on
                  // module = new Alternate(strand1_, strand2_, 400);
                  // module_ = new AlternateTwinkle(strand1_, strand2_, 800);
                  // module_->init();
                  module_->step();
            }

            void ChristmasLights::loop() {
                  module_->step();
            }

            void ChristmasLights::dump_config(){
                  ESP_LOGCONFIG("strand1", "FloatOutput");
                  ESP_LOGCONFIG("strand2", "FloatOutput");
            }

      } 
} 