#include <Arduino.h>
#include "Modes/ModeInterface.h"
#include "Modes/ModeController.h"
#include "Modes/Alternate.h"
#include "Modes/Twinkle.h"
#include "Modes/AlternateTwinkle.h"

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

ModeInterface* module;
 
void setup() {
  pinMode(LED_STRAND_1, OUTPUT);
  pinMode(LED_STRAND_2, OUTPUT);

  digitalWrite(LED_STRAND_1, DEFAULT);
  digitalWrite(LED_STRAND_2, !DEFAULT);

  // module = new ModeController(LED_STRAND_1, LED_STRAND_2, 250);
  // module = new Alternate(LED_STRAND_1, LED_STRAND_2, 5); //steady on
  // module = new Alternate(LED_STRAND_1, LED_STRAND_2, 400);
  // module = new AlternateTwinkle(LED_STRAND_1, LED_STRAND_2, 800);
  // module->init();
}

void loop() {
  // digitalWrite(LED_STRAND_1, !digitalRead(LEFT));
  // digitalWrite(LED_STRAND_2, !digitalRead(RIGHT));
  // delay(499);
  
  module->step();
  delay(1);
}
