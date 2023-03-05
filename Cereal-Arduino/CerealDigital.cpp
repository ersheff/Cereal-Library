#include "Arduino.h"
#include "Cereal.h"

CerealDigital::CerealDigital(char *header, int pin)
{
  pinMode(pin, INPUT_PULLUP);
  _header = header;
  _pin = pin;
  _lastState = !digitalRead(_pin);
  _currentState = !digitalRead(_pin);
  _debounceDelay = 50;
  _lastTime = 0;
}

void CerealDigital::readWrite()
{
  
  // the reading is flipped since we are using INPUT_PULLUP by default
  bool reading = !digitalRead(_pin);
  
  // start debounce -----

  if (reading != _lastState) {
    _lastTime = millis();
  }
  if ((millis() - _lastTime) > _debounceDelay) {
    if (reading != _currentState) {
      _currentState = reading;
    }
  }

  _lastState = reading;

  // end debounce -----

  //
  Serial.write(129); // value start flag
  Serial.write(_currentState);

  // no need for value end flag since it will only be 0/1
    
  //
  Serial.write(130); // header start flag
  for (int i = 0; i < strlen(_header); i++) {
    Serial.write(_header[i]);
  }
  Serial.write(255); // header end flag

}