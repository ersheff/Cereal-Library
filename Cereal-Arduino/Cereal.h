#ifndef Cereal_h
#define Cereal_h

#include "Arduino.h"

class CerealAnalog
{
  public:
    CerealAnalog(char *header, int pin);
    int readWrite();
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

class CerealWrite
{
  public:
    CerealWrite(char *header);
    void write(int val);
  private:
    char *_header;
    int _val;
};

#endif