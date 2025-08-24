#include "PDIO.h"

bool PDIO::DEBUG = false;
bool PDIO::DETENER = false;

void PDIO::ImprimirSerial(String msj, char color = 'w') {
  if (PDIO::DEBUG) {
    String colorCode;
    switch (color) {
      case 'r': colorCode = "\033[31m"; break; // Rojo
      case 'g': colorCode = "\033[32m"; break; // Verde
      case 'b': colorCode = "\033[34m"; break; // Azul
      case 'y': colorCode = "\033[33m"; break; // Amarillo
      case 'c': colorCode = "\033[36m"; break; // Cian
      case 'm': colorCode = "\033[35m"; break; // Magenta
      case 'w': colorCode = "\033[37m"; break; // Blanco
      default: colorCode = "\033[0m"; // Sin color
    }
    Serial.print(color);
    Serial.println(msj);
    Serial.print("\033[0m");
  }
}

void PDIO::BlinkPin(int pin, int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    vTaskDelay(delayTime / portTICK_PERIOD_MS);
    digitalWrite(pin, LOW);
    vTaskDelay(delayTime / portTICK_PERIOD_MS);
  }
}

void PDIO::ManejoEstrobo(int pin, int freq, int delayTime) {
  if (delayTime == 0) {
    while (PDIO::DETENER) {
      if (PDIO::DETENER) {
        PDIO::ImprimirSerial("Manejo Estrobo por Tiempo Indefinido detenido.", 'y');
        break;
      }

      digitalWrite(pin, HIGH);
      vTaskDelay(freq / portTICK_PERIOD_MS);
      digitalWrite(pin, LOW);
      vTaskDelay(freq / portTICK_PERIOD_MS);
    }

  } else {
    int tiempo = delayTime * 1000;
    int ciclos = tiempo / (2 * freq);

    for (int i = 0; i < ciclos; i++) {
      if (PDIO::DETENER) {
        PDIO::ImprimirSerial("Manejo Estrobo por Tiempo Finito detenido.", 'y');
        break;
      }
      digitalWrite(pin, HIGH);
      vTaskDelay(freq / portTICK_PERIOD_MS);
      digitalWrite(pin, LOW);
      vTaskDelay(freq / portTICK_PERIOD_MS);
    }
  }
}
