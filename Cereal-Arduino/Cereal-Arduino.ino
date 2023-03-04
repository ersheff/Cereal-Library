// include the Cereal library
#include "Cereal.h"

// create a CerealAnalog object for each analog input you will be using
CerealAnalog analogSensor("pot", 0);

// create a CerealDigital object for each digital input you will be using
CerealDigital digitalSwitch("button", 2);

// for both, the format is: name("header", pin)
// the name is how you will reference the object in your loop when calling its readWrite() function
// the header will be prepended to the pin reading when it appears in your other software
// in most cases, your name and header will probably be the same, but they don't have to be

void setup() {
  // make sure that the baud rate matches in your other software
  Serial.begin(115200);
}

void loop() {

  // call the readWrite function from each of your CerealAnalog
  // and CerealDigital obects to read the pin and write to serial
  analogSensor.readWrite();
  digitalSwitch.readWrite();
  
  delay(10);

}