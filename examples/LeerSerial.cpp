#include <Arduino.h>
#include <PDIO.h>

PDIO pdio;

#define LED 6

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  PDIO::DEBUG = true;
}

void loop() {
  while (Serial.available() > 0) {
    String comando = pdio.LeerSerial();

    if (comando == "LED1") {
      pdio.ImprimirSerial("Led encendido", 'c');
      digitalWrite(LED, HIGH);
    } else if (comando == "LED0") {
      pdio.ImprimirSerial("Led apagado", 'y');
      digitalWrite(LED, LOW);
    } else {
      PDIO::ImprimirSerial("Comando no reconocido", 'r');
    }
  }
}
