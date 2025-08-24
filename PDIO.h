#ifndef PDIO_H
  #define PDIO_H

  #ifdef ARDUINO
    #include <Arduino.h>
  #endif

  class PDIO {
    public:
      static bool DEBUG;
      static bool DETENER;
      void ImprimirSerial(String msj, char color = 'w');
      void BlinkPin(int pin, int times, int delayTime);
      void ManejoEstrobo(int pin, int freq, int delayTime);
      String LeerSerial();
  };

#endif