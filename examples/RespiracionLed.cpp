#include <Arduino.h>
#include <PDIO.h>

PDIO pdio;

#define LED 6

void setup() {
  pinMode(LED, OUTPUT);

  pdio.RespiracionLED(LED, 10);
}

void loop() {}
