#include "Arduino.h"
#include "Cereal.h"

CerealAnalog::CerealAnalog(char *header, int pin)
{
  _header = header;
  _pin = pin;
}

void CerealAnalog::readWrite()
{
  int reading = analogRead(_pin);

  //
  Serial.write(128); // value start flag
  Serial.write(reading&7);
  Serial.write(reading>>3);
  Serial.write(255); // value end flag
  
  //
  Serial.write(130); // header start flag
  for (int i = 0; i < strlen(_header); i++) {
    Serial.write(_header[i]);
  }
  Serial.write(255); // header end flag

}