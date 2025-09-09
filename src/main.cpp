#include <Arduino.h>
#include <MicroOscSlip.h>
// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
// Les messages sortants sont écrits directement sur la sortie et ne nécessitent pas de réservation d'octets supplémentaires.
MicroOscSlip<128> monOsc(&Serial);

#define MA_BROCHE_BOUTON 39

// #define MA_BROCHE_ANGLE 32

void setup()
{
  pinMode(MA_BROCHE_BOUTON, INPUT);
  Serial.begin(115200);
}

void loop()
{
  // int maLectureAngle;

  // maLectureAngle = analogRead(MA_BROCHE_ANGLE);
  // Serial.println(maLectureAngle);
  // delay(100);

  int maLectureBouton = digitalRead(MA_BROCHE_BOUTON);
  // Serial.println(maLectureBouton);
  // Serial.println();
  monOsc.sendInt("/adresse", MA_BROCHE_BOUTON);
  int maLectureAnalogique = analogRead(32);
  monOsc.sendInt("/angle", maLectureAnalogique);

  delay(1000);
}
