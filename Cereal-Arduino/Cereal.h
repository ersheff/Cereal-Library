#ifndef Cereal_h
#define Cereal_h

#include "Arduino.h"

class CerealAnalog
{
  public:
    CerealAnalog(char *header, int pin);
    void readWrite();
  private:
    char *_header;
    int _pin;
};

class CerealDigital
{
  public:
    CerealDigital(char *header, int pin);
    void readWrite();
  private:
    char *_header;
    int _pin;
    bool _currentState;
    bool _lastState;
    int _debounceDelay;
    unsigned long _lastTime;
};

#endif