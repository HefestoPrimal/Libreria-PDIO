#include <Arduino.h>
#include <PDIO.h>

PDIO pdio;

#define LED 6

int tiempos[] = {100, 250, 500, 750, 1000, 2000};

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(tiempos); i++) {
    PDIO::BlinkPin(LED, 5, tiempos[i]);
  }
}
