#include <Arduino.h>
#define MA_BROCHE_BOUTON 39

void setup()
{
  pinMode(MA_BROCHE_BOUTON, INPUT);
  Serial.begin(115200);
}

void loop()
{
  int maLectureBouton = digitalRead(MA_BROCHE_BOUTON);
  maLectureBouton = analogRead(MA_BROCHE_BOUTON);
  Serial.println(MA_BROCHE_BOUTON);
}
