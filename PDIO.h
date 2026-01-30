#ifndef PDIO_H
  #define PDIO_H

  #ifdef ARDUINO
    #include <Arduino.h>
  #endif

  class PDIO {
    private:
      #define DO 262
      #define RE 294
      #define MI 329
      #define FA 349
      #define SOL 392
      #define LA 440
      #define SI 494
      #define DO2 523
      #define RE2 587
      #define MI2 659
      #define FA2 698
      #define SOL2 784
      #define LA2 880
      #define SI2 988
      #define DO3 1046
      #define RE3 1174
      #define MI3 1319
      #define FA3 1396
      #define SOL3 1568
      #define LA3 1760
      #define SI3 1976
      #define DO4 2093
      #define RE4 2349
      #define MI4 2697
      #define FA4 2969
      #define SOL4 3329
      #define LA4 3520
      #define SI4 3922
      #define DO5 4186
      #define RE5 4559
      #define MI5 4978
      #define FA5 5274
      #define SOL5 5588
      #define LA5 5919
      #define SI5 6294

    public:
      static bool DEBUG;
      static bool DETENER;
      void ImprimirSerial(String msj, char color = 'w'); // Mensaje que se quiere imprimir en la consola / Color de salida del mensaje (vacio = por defecto, c = cian, g = verde, r = rojo, y = amarillo, m = magenta, a = azul)
      void BlinkPin(int pin, int times, int delayTime); // Pin seleccionado, cantidad de veces que parpadeara el pin, tiempo entre parpadeos
      void ManejoEstrobo(int pin, int freq, int delayTime); // Pin seleccionado, frecuencia de parpadeo, tiempo en segundos que durará parpadeando
      void RespiracionLED(int pinLed, int tiempo); // Pin seleccionado, tiempo de efecto de respiracion
      void TonosBocina(int pin, int frecuencia, int duracionTono, int duracionSilencio); // Pin seleccionado, frecuencia de sonido, duracion del tono, duracion del silencio
      String LeerSerial(); // Lee el mensaje que se envió por serial
  };

#endif