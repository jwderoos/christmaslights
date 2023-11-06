#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

#define GPIO0 0
#define TX_PIN 1 //gpio2
#define GPIO2 2
#define RX_PIN 3 //gpio4

#define LEFT GPIO0
#define RIGHT RX_PIN

void setup() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  // digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, HIGH);
}

void loop() {
  digitalWrite(LEFT, !digitalRead(LEFT));
  digitalWrite(RIGHT, !digitalRead(RIGHT));
  // put your main code here, to run repeatedly:
  delay(1000);
}
