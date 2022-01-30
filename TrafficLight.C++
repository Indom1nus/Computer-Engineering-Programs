#include <Servo.h>
int pinArray1[] = {2,3,4};
int pinArray2[] = {5,6,7};
int turn = 1;
int count = 0;
int timer = 0;
int buttonState = 0;
const int buttonPin = 8;
int vals = 0;
Servo servo_10;
Servo servo_11;
void setup()
{
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
  for(int i = 0; i<3; i++)
  {
    pinMode(pinArray1[i],OUTPUT);
  } for(int j = 0; j<3; j++)
  {
    pinMode(pinArray2[j],OUTPUT);
  }
  servo_10.attach(10);
  servo_11.attach(11);
}

void loop()
{
  if(vals == 0)
  {
  	interr1();
  	interr2();
  }
  vals++;
  int value = analogRead(A0);
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    
    digitalWrite(pinArray1[2],HIGH);
    digitalWrite(pinArray2[2],HIGH);
    play();
    delay(3000);
    digitalWrite(pinArray1[2],LOW);
    digitalWrite(pinArray2[2],LOW);
    delay(3000);
  }
  else if(buttonState == LOW)
  {
  if(count>=3)
  {
    digitalWrite(pinArray2[2],LOW);
    digitalWrite(pinArray1[2],LOW);
  }
  if(turn == 1)
  {
   value = analogRead(A0); 
  for(int i = 0; i<3;i++)
  {
    value = analogRead(A0);
    if(i == 0)
    {
      inter1();
      if(value == 0)
      {
        timer = 7000;
      }
      else
      {
        timer = (value+1)*3;
      }
    }
    else if(i == 1)
    {
      if(value == 0)
      {
        timer = 2000;
      }
      else
      {
        timer = (value+1)*3;
      }
    }
    else if(i == 2)
    {
      interr1();
      if(value == 0)
      {
      timer = 1000;
      }
      else
      {
        timer = (value+1)*3;
      }
    }
    Serial.println(timer);
    digitalWrite(pinArray2[2],HIGH);
    digitalWrite(pinArray1[i],HIGH);
    delay(timer);
    digitalWrite(pinArray1[i],LOW);
    delay(500);
    turn = 2;
    count++;
  }
  }
  else if(turn == 2)
  {
    value = analogRead(A0);
   	for(int j = 0; j<3; j++)
    {
      value = analogRead(A0);
      if(j == 0)
      {
        inter2();
        if(value == 0)
        {
          timer = 7000;
        }
        else
        {
          timer = (value+1)*3;
        }
      }
     else if(j == 1)
     {
       if(value == 0)
       {
         timer = 2000;
       }
       else 
       {
         timer =(value+1)*3;
       }
     }
     else if(j == 2)
        {
          interr2();
          if(value == 0)
          {
            timer = 1000;
          }
       	  else
          {
            timer = (value+1)*3;
          }
        }
    Serial.println(timer);
    digitalWrite(pinArray1[2],HIGH);
    digitalWrite(pinArray2[j],HIGH);
    delay(timer);
    digitalWrite(pinArray2[j],LOW);
    delay(500);
    turn = 1;
    count++;
    }
  }
  }
  
}
void play()
{
  tone(9,200,500);
  delay(500);
  tone(9,250,500);
  delay(500);
  tone(9,300,500);
  delay(500);
  noTone(9);
  delay(500);
}
void inter1()
{
  for(int i = 0;i<= 90;i++)
  {
    servo_10.write(i);
    delay(15);
    digitalWrite(pinArray2[2],HIGH);
  }
}

void interr1()
{
  for(int i = 90;i>=0;i--)
  {
    servo_10.write(i);
    delay(15);
  }
}

void inter2()
{
  for(int i = 0; i<= 90;i++)
  {
    servo_11.write(i);
    delay(15);
    digitalWrite(pinArray1[2],HIGH);
  }
}

void interr2()
{
  for(int i = 90;i>=0;i--)
  {
    servo_11.write(i);
    delay(15);
  }
}









