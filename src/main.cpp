#include <Arduino.h>
#define MA_BROCHE_BOUTON 39

void setup()
{
  pinMode(MA_BROCHE_BOUTON, INPUT);
}

void loop()
{
  int maLectureBouton = digitalRead(MA_BROCHE_BOUTON);
}
