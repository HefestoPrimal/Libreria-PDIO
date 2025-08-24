# PDIO

Funciones utilitarias de debug en Serial con colores, manejar un pin de salida para parpadear determinadas veces a cierta frecuencia y hacer que un pin de salida parpadee a una frecuencia especifica por un tiempo definido o indefinido. para proyectos Arduino/ESP32.

## Uso

```cpp
#include <PDIO.h>

#define LED 13

void setup() {
  Serial.begin(9600);
  PDIO::DEBUG = true;
  PDIO Pdio;
  Pdio.ImprimirSerial("Hola mundo!", 'g');
  // El primer parámetro es el mensaje a mostrar
  // El segundo parámetro es el color en el que se va a mostrar (Opcional)
  // el color es 'r' para rojo, 'g' para verde, 'b' para azul, 'c' para cyan, 'm' para magenta, 'y' para amarillo, 'w' para blanco y en caso de no poner nada se imprimirá el valor por defecto

  Pdio.BlinkPin(LED, 3, 250);
  // El primer parámetro es el pin de salida
  // El segundo parámetro es la cantidad de veces que va a parpadear
  // El tercer parámetro es la frecuencia en milisegundos

  Pdio.ManejoEstrobo(LED, 500, 5);
  // El primer parámetro es el pin de salida
  // El segundo parámetro es la frecuencia en milisegundos
  // El tercer parámetro es el tiempo en segundos que va a estar parpadeando
}

