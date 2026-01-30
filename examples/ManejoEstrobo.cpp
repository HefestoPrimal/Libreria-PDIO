#include <Arduino.h>
#include <PDIO.h>

PDIO pdio;

#define LED 6

int tiempos[] = {100, 250, 500, 750, 1000, 2000};

void setup() {
  pinMode(LED, OUTPUT);
  PDIO::DETENER = false;
}

void loop() {
  for (int i = 0; i < sizeof(tiempos); i++) {
    PDIO::ManejoEstrobo(LED, tiempos[i], 5);
  }
}
