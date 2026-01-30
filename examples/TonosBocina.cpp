#include <Arduino.h>
#include <PDIO.h>

PDIO pdio;

#define BOCINA 6

void setup() {
  pinMode(BOCINA, OUTPUT);
}

void loop() {
  // Se tienen registradas los tonos con escalas, por ejemplo DO (DO, DO2, DO3, DO4 y DO5)
  pdio.TonosBocina(BOCINA, DO, 500, 100);
  pdio.TonosBocina(BOCINA, RE, 500, 100);
  pdio.TonosBocina(BOCINA, MI, 500, 100);
  pdio.TonosBocina(BOCINA, FA, 500, 100);
  pdio.TonosBocina(BOCINA, SOL, 500, 100);
  pdio.TonosBocina(BOCINA, LA, 500, 100);
  pdio.TonosBocina(BOCINA, SI, 500, 100);
}
