#include <Arduino.h>
#include "Modes/ModeInterface.h"
#include "Modes/ModeController.h"

#define GPIO0 0
#define TX_PIN 1 //gpio2
#define GPIO2 2
#define RX_PIN 3 //gpio4

#define LEFT GPIO0
#define RIGHT RX_PIN

ModeInterface* module;
 
void setup() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  module = new ModeController(LEFT, RIGHT, 1);

  module->init();
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, HIGH);
}

void loop() {
  module->step();
  delay(1);
}
