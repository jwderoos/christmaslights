#include "christmaslights.h"

#include "esphome/core/log.h"

#include "ModeController.h"
#include "Alternate.h"
#include "Twinkle.h"
#include "AlternateTwinkle.h"
#include "FadeInOut.h"
#include "Fade.h"

namespace esphome {
      namespace christmas_lights {
            void ChristmasLights::setup() {
                  // module_ = new FadeInOut(strand1_, strand2_, 5);
                  module_ = new Fade(strand1_, strand2_, 5, 0.0001);
                  // module_ = new Alternate(strand1_, strand2_, 1000); //steady on
                  // module_ = new BlinkOne(strand1_, strand2_, 250);
                  // module_ = new ModeController(strand1_, strand2_, 250);
                  // module_ = new Alternate(strand1_, strand2_, 400);
                  // module_ = new AlternateTwinkle(strand1_, strand2_, 800);
                  // module_->init();
            }

            void ChristmasLights::loop() 
            {
                  if (enabled_) {
                        module_->loop();
                  }
            }

            void ChristmasLights::dump_config(){
                  ESP_LOGCONFIG("enabled", "bool");
                  ESP_LOGCONFIG("strand1", "FloatOutput");
                  ESP_LOGCONFIG("strand2", "FloatOutput");
            }

      } 
} 