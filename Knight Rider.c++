int pinArray [] = {3,5,6,9,10,11}; //I used these numbers since fading is only created through pins that have PWM.
int count = 0;
int buttonPushCounter = 1;
int buttonState = 0;
int lastButtonState =0;
const int buttonPin = 2;
int lastbuttonState = 0;
void setup()
{
  pinMode(buttonPin,INPUT); //declares the button as an input.
  Serial.begin(9600);
  for(count = 0; count < 6; count++) // this loop initializes the lights as outputs by using a for loop. It declares each element of the array as an output.
  {
    pinMode(pinArray[count],OUTPUT);
  }
 
}

void loop()
{
  int sensorValue = analogRead(A0); // reads the potentiometer's value.
  int speed = sensorValue /15; // used for the speed of the circuit. It is divided by 15 to accurately show if the potentiometer is on a slow or high setting.
  int j = 0; // int controls brightness
  buttonState = digitalRead(buttonPin);
  delay(500); // delays to give enough time to release your finger.
  
  if (buttonState != lastButtonState) // if the button is at a different value from what it was before(starts at 0).
  {
	if (buttonState == HIGH)
    {
		buttonPushCounter++; // increases the counter if the button is pressed.
    }
  }
  lastbuttonState = buttonState; // lastbuttonState is now what the button's current value is. This allows the initial if statement to be dynamic as the value of the button changes from 1 to 0.
  
  if(buttonPushCounter % 2 == 0) // by starting the pushcounter at 1, if the button is pressed again(pushCounter = 2), the loop runs, if it is pressed again, the circuit turns off.
  {
  for(count = 0; count<5; count++) // start of nested for loop. Once the inner loop that controls the brightness finishes, it moves on to the proceeding light.
  {
    for(int i = 0; i<=515;i+=speed) // this loop controls the fade. It iterates 515 times allowing the light's brightness to float up to the max value of 255 and float back down to 0. It is 515 to adjust for any delay.
    {
     	 sensorValue = analogRead(A0);
    	 speed = sensorValue/15; // reads speed again to change the speed during the circuit.
      	if( i > 255) // if the light has reached its max brightness, it starts to go back down. J will now go down, while i goes up to finish the loop.
        {
          j-=speed;
        }
      	else
     	 {
      	  j+=speed;
     	 }
    	analogWrite(pinArray[count],j);
      	Serial.println(speed);
    	}
    }
 j = 0;
  for(count = 5; count >0; count --) // same logic but now it starts from the top light going down.
  {
    for(int i = 0; i<=515;i+=speed)
    {
     	 sensorValue = analogRead(A0);
    	  speed = sensorValue /15;
      	if( i > 255)
        {
          j-=speed;
        }
      	else
     	 {
      	  j+=speed;
     	 }
    	analogWrite(pinArray[count],j);
      	Serial.println(buttonPushCounter);
    	}
    }
      buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) // buttonChecker logic is located at the end of the loop as well to check if the button has been pressed again to turn the light off. 
  {
	if (buttonState == HIGH) 
    {
		buttonPushCounter++;
      	delay(1000);
    }
  }
  lastbuttonState = buttonState;
  }
}




