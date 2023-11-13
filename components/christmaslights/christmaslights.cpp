#include "christmaslights.h"

#include "esphome/core/log.h"
#include "ModeController.h"

static const char *const TAG = "christmasLigths";

namespace esphome {
  namespace christmas_lights {
    void ChristmasLights::setup() {
      module_ = std::make_shared<ModeController>(strand1_, strand2_, 300);
      module_->init();

      ESP_LOGI(TAG, "Started ModeController");
    }

    void ChristmasLights::set_enabled(bool enabled) { 
      enabled_ = enabled; 
      if (enabled_) {
        high_freq_.start();
      } else {
        high_freq_.stop();
      }
      strand1_->turn_off();
      strand2_->turn_off();
    }

    void ChristmasLights::loop() 
    {
      if (enabled_) {
        module_->loop();
      }
    }

    void ChristmasLights::dump_config(){
      ESP_LOGCONFIG("strand1", "FloatOutput");
      ESP_LOGCONFIG("strand2", "FloatOutput");
    }
  } 
} 