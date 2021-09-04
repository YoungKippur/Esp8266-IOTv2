#include "FastLED.h"

#define LED_DT 12

#define COLOR_ORDER GRB
#define LED_TYPE WS2812
#define NUM_LEDS 1

uint8_t max_bright = 255;

struct CRGB leds[NUM_LEDS];

void setup() {
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(max_bright);
}

void loop () {
  rainbow();
}

void rainbow() {
  uint8_t thisSpeed = 10;
  uint8_t deltaHue = 10;
  uint8_t thisHue = beat8(thisSpeed, 255);
  fill_rainbow(leds, NUM_LEDS, thisHue, deltaHue);
  FastLED.show();
}
