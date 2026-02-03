#include "PDIO.h"

bool PDIO::DEBUG = false;
bool PDIO::DETENER = false;

void PDIO::ImprimirSerial(String msj, char color) {
  if (PDIO::DEBUG) {
    String colorCode;
    switch (color) {
      case 'r': colorCode = "\033[31m"; break; // Rojo
      case 'g': colorCode = "\033[32m"; break; // Verde
      case 'b': colorCode = "\033[34m"; break; // Azul
      case 'y': colorCode = "\033[33m"; break; // Amarillo
      case 'c': colorCode = "\033[36m"; break; // Cian
      case 'm': colorCode = "\033[35m"; break; // Magenta
      default: colorCode = "\033[0m"; // Sin color
    }
    Serial.print(colorCode);
    Serial.println(msj);
    Serial.print("\033[0m");
  }
}

void PDIO::BlinkPin(int pin, int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    #ifdef ARDUINO
      delay(delayTime);
    #else
      vTaskDelay(delayTime / portTICK_PERIOD_MS);
    #endif

    digitalWrite(pin, LOW);
    #ifdef ARDUINO
      delay(delayTime);
    #else
      vTaskDelay(delayTime / portTICK_PERIOD_MS);
    #endif
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
      #ifdef ARDUINO
        delay(freq);
      #else
        vTaskDelay(freq / portTICK_PERIOD_MS);
      #endif

      digitalWrite(pin, LOW);
      #ifdef ARDUINO
        delay(freq);
      #else
        vTaskDelay(freq / portTICK_PERIOD_MS);
      #endif
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
      #ifdef ARDUINO
        delay(freq);
      #else
        vTaskDelay(freq / portTICK_PERIOD_MS);
      #endif
      
      digitalWrite(pin, LOW);
      #ifdef ARDUINO
        delay(freq);
      #else
        vTaskDelay(freq / portTICK_PERIOD_MS);
      #endif
    }
  }
}

String PDIO::LeerSerial() {
  String comandoSerial = "";
  if (Serial.available()) {
    comandoSerial = Serial.readStringUntil('\n');
    if (comandoSerial != "") {
      PDIO::ImprimirSerial("Comando recibido en Serial-> " + comandoSerial, 'c');
      return comandoSerial;
    } else {
      PDIO::ImprimirSerial("Comando vacio", 'r');
      return "";
    }
  }
  return "";
}

void PDIO::RespiracionLED(int pinLed, int tiempo) {
  int breath = 25;
  int tiempoRespirando = tiempo * 1000;
  int ciclos = tiempoRespirando / (2 * breath);

  for (int i = 0; i < 255; i++) {
    analogWrite(pinLed, i);
    #ifdef ARDUINO
      delay(breath);
    #else
      vTaskDelay(breath);
    #endif
  }
  for (int j = 255; i > 0; i--) {
    analogWrite(pinLed, j);
    #ifdef ARDUINO
      delay(breath);
    #else
      vTaskDelay(breath);
    #endif
  }
}

void PDIO::TonosBocina(int pin, int frecuencia, int duracionTono, int duracionSilencio) {
  tone(pin, frecuencia, duracion);
  #ifdef Arduino
    delay(duracion);
  #else
    vTaskDelay(duracion / portTICK_PERIOD_MS);
  #endif

  noTone(pin);
  #ifdef Arduino
    delay(duracion);
  #else
    vTaskDelay(duracion / portTICK_PERIOD_MS);
  #endif
}
