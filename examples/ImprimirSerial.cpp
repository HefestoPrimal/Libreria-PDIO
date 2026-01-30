#include <Arduino.h>
#include <PDIO.h>

PDIO pdio;

char colores[] = {'', 'r', 'g', 'b', 'y', 'c', 'm', 'a'};

void setup() {
  Serial.begin(115200);
  PDIO::DEBUG = true;

  for (int i = 0; i < sizeof(colores); i++) {
    PDIO::ImprimirSerial("Color: " + String(colores[i]), colores[i]);
  }
}

void loop() {}
