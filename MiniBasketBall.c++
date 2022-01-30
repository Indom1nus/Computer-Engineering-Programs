#include <LiquidCrystal.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 10 // input pin Neopixel is attached to
#define NUMPIXELS 8 // number of neopixels in strip
Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
// Creates an LCD object. Parameters: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
Servo myservo;
int lightPin = 8;
int buttonPin = 9;
int buttonReading = 1;
int photocellPin = 0;
int numbasket = 0;
boolean gameOn = false;
long previousMillis = 0;
long gameInterval = 10000; //how long the game lasts for 

//custom characters:
byte BBall[] = {
B01110,
B10101,
B10101,
B10101,
B11111,
B10101,
B10101,
B01110
};


byte player[] = {
B01110,
B01110,
B00100,
B10101,
B01110,
B00100,
B01010,
B10001
};

void setup()
{
myservo.attach(11);
myservo.write(90);
lcd.begin(16, 2); // Specify the LCD's number of columns and rows:
lcd.createChar(0, BBall); // Create a new character: BBall
lcd.createChar(1,player);// Create a new character: Player
lcd.clear(); // Clears the LCD screen:
lcd.setCursor(3,0); //sets the lcd cursor so that the message displays in the first row, in the middle
lcd.print("Mini BBall"); // Print a message to the lcd:
lcd.setCursor(0, 1); //setting cursor to write the ball on the 'first pixel'
lcd.write(byte(1));
lcd.setCursor(15,1); //setting cursor to write the ball on the 'last pixel'
lcd.write(byte(1));
lcd.setCursor(8,1);
lcd.write(byte(0));
delay(2000); //message is diplayed for 2 seconds
lcd.clear();
pinMode(lightPin, OUTPUT);
pinMode(buttonPin,INPUT_PULLUP);
Serial.begin(9600);
strip.begin(); // Initializes the NeoPixel library.
strip.clear(); //Sets all pixels to OFF
}
void loop()
{
unsigned long currentMillis = millis();
numbasket = 0; //this int is assigned to the total score
buttonReading = digitalRead(buttonPin); //this int is assigned to the reading of the button
//if the button is pressed, starts the game
if(buttonReading == LOW){
myservo.write(0);
strip.fill(strip.Color(0,255,0));
strip.show();
digitalWrite(lightPin,HIGH);
gameOn = true;
//if the gametime is less than the max time, 10 seconds
// it will display the neopixels according to the amount of time elapsed
while (currentMillis - previousMillis < gameInterval){
currentMillis = millis();
if((currentMillis-previousMillis)>= 5000 && (currentMillis-previousMillis)<= 7500)
{
  strip.clear();
  strip.fill(strip.Color(0,255,0),2,4);
  strip.show();
}

else if((currentMillis-previousMillis)<5000)
{
  strip.clear();
  strip.fill(strip.Color(0,255,0));
  strip.show();
}
else if((currentMillis-previousMillis)>7500)
{
  strip.clear();
  strip.fill(strip.Color(0,255,0),3,2);
  strip.show();
}
//if the photo resistor is reading low, it will add 2 to the numbasket, unless 75% of the game has elapsed
//in which the score will increase by 3
if(gameOn == true && analogRead(photocellPin)<600){
if((currentMillis-previousMillis) >= 7500)
{
  numbasket = numbasket + 3;
}
else
{
  numbasket = numbasket + 2;
}
strip.fill(strip.Color(0,0,255));
strip.show();
delay(500);

}
//writes the word score, on the middle of first row, and the numbaskets value on the middle of the second row
lcd.setCursor(6, 0);
lcd.print("SCORE");
lcd.setCursor(8, 1);
lcd.print(numbasket);
}
}
previousMillis = currentMillis;
strip.clear();
strip.show();
digitalWrite(lightPin,LOW);
gameOn = false;
myservo.write(90);
}