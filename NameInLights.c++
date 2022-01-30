int redPin = 11;
int greenPin = 9;
int bluePin = 10;


#include <Adafruit_NeoPixel.h>
#define LED_PIN 2 // input pin Neopixel is attached to
#define NUMPIXELS 44 // number of neopixels in strip
Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
strip.begin(); // Initializes the NeoPixel library.
}
void loop() {
strip.clear();  
strip.fill(strip.Color(0,255,255));
strip.show();
setColor(255, 0, 0); 
delay(4000);
  
thing(0,255,0,255,0,255,255,255,0);
thing(0,0,255,255,255,0,255,0,255);
  
}

void setColor(int red, int green, int blue)
{
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}

void thing(int ledrgb1,int ledrgb2,int ledrgb3,int initial1rgb1,int initial1rgb2,int initial1rgb3,int initial2rgb1,int initial2rgb2,int initial2rgb3)
{
  strip.clear();
  strip.fill(strip.Color(initial1rgb1,initial1rgb2,initial1rgb3),0,20);
  setColor(ledrgb1,ledrgb2,ledrgb3);
  strip.fill(strip.Color(initial2rgb1,initial2rgb2,initial2rgb3),21,23);
  strip.show();
  delay(4000);

}



           