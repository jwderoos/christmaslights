#include "christmaslights.h"

#include "esphome/core/log.h"

#include "../../src/Modes/ModeController.h"
#include "../../src/Modes/Alternate.h"
#include "../../src/Modes/Twinkle.h"
#include "../../src/Modes/AlternateTwinkle.h"

namespace esphome {
      namespace christmas_lights {
            void ChristmasLights::setup() {
                  pinMode(LED_STRAND_1, OUTPUT);
                  pinMode(LED_STRAND_2, OUTPUT);
            
                  digitalWrite(LED_STRAND_1, DEFAULT);
                  digitalWrite(LED_STRAND_2, !DEFAULT);
            
                  // module = new ModeController(LED_STRAND_1, LED_STRAND_2, 250);
                  // module = new Alternate(LED_STRAND_1, LED_STRAND_2, 5); //steady on
                  // module = new Alternate(LED_STRAND_1, LED_STRAND_2, 400);
                  module = new AlternateTwinkle(LED_STRAND_1, LED_STRAND_2, 800);
                  module->init();
            }

            void ChristmasLights::loop() {
                  // digitalWrite(LED_STRAND_1, !digitalRead(LEFT));
                  // digitalWrite(LED_STRAND_2, !digitalRead(RIGHT));
                  // delay(499);
                  
                  module->step();
                  delay(1);
            }


            void ChristmasLights::dump_config(){
            //     ESP_LOGCONFIG(TAG, "Empty custom light");
            }

      } 
} 