#include <Arduino.h>
#include <MicroOscSlip.h>
#include <FastLED.h>

#define MA_BROCHE_BOUTON 39
#define MA_BROCHE_ANGLE 32

// Le nombre 128 entre les < > ci-dessous est le nombre maximal d'octets réservés pour les messages entrants.
MicroOscSlip<128> monOsc(&Serial);

// Déclaration d'un tableau de LEDs
CRGB pixels[NUM_LEDS];

void setup()
{
  // Initialisation des LEDs
  FastLED.addLeds<WS2812, LED_PIN, GRB>(pixels, NUM_LEDS);

  pinMode(MA_BROCHE_BOUTON, INPUT);
  Serial.begin(115200);
}

void loop()
{
  // Lecture de l'angle
  int maLectureAngle = analogRead(MA_BROCHE_ANGLE);
  monOsc.sendInt("/angle", maLectureAngle);

  // Lecture du bouton
  int maLectureBouton = digitalRead(MA_BROCHE_BOUTON);
  monOsc.sendInt("/Bouton", maLectureBouton);

  // Animation simple : couleur verte qui change avec le temps
  int green = millis() % 256;
  {
    int pixels = CRGB(0, green, 0); // On met toutes les LEDs au vert variable
  }

  FastLED.show();

  delay(100); // Petite pause pour limiter la fréquence
}
