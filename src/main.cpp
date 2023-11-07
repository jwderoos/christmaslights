#include <Arduino.h>
#include "Modes/ModeInterface.h"
#include "Modes/ModeController.h"
#include "Modes/Alternate.h"
#include "Modes/Twinkle.h"
#include "Modes/AlternateTwinkle.h"

#define TEST_MODE true

#define GPIO0 0 // led strand 1
#define TX_PIN 1 //gpio2 // internal led
#define GPIO2 2 // 
#define RX_PIN 3 //gpio4 // external led //led strand 2

#if TEST_MODE 
  #define LEFT TX_PIN
  #define RIGHT RX_PIN
  #define DEFAULT HIGH
#else
  #define LEFT GPIO0
  #define RIGHT RX_PIN
  #define DEFAULT LOW
#endif

ModeInterface* module;
 
void setup() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  digitalWrite(LEFT, DEFAULT);
  digitalWrite(RIGHT, !DEFAULT);

  // module = new ModeController(LEFT, RIGHT, 250);
  // module = new Alternate(LEFT, RIGHT, 5); //steady on
  // module = new Alternate(LEFT, RIGHT, 400);
  module = new AlternateTwinkle(LEFT, RIGHT, 800);
  module->init();
}

void loop() {
  // digitalWrite(LEFT, !digitalRead(LEFT));
  // digitalWrite(RIGHT, !digitalRead(RIGHT));
  // delay(499);
  
  module->step();
  delay(1);
}
