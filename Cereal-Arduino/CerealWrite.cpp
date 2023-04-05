#include "Arduino.h"
#include "Cereal.h"

CerealWrite::CerealWrite(char *header)
{
  _header = header;
}

void CerealWrite::write(int val)
{
  _val = val;
  //
  Serial.write(128); // value start flag
  Serial.write(_val&7);
  Serial.write(_val>>3);
  Serial.write(255); // value end flag
  
  //
  Serial.write(130); // header start flag
  for (int i = 0; i < strlen(_header); i++) {
    Serial.write(_header[i]);
  }
  Serial.write(255); // header end flag

}