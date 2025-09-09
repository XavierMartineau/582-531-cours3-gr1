#include <Arduino.h>
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
  Serial.println(maLectureBouton);
  Serial.println();
  delay(1000);
}
