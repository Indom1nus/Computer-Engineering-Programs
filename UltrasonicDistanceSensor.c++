int distanceThreshold = 0;
int cm = 0;
int inches = 0;
void setup()
{
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
}
void loop()
{
distanceThreshold = 320; // set threshold distance to activate LEDs
cm = 0.01723 * readUltrasonicDistance(8, 7); // measure the ping time in cm
inches = (cm / 2.54); // convert to inches by dividing by 2.54
Serial.print(cm);
Serial.print("cm, ");
Serial.print(inches);
Serial.println("in");
if (cm > distanceThreshold)
{
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
}
if (cm <= distanceThreshold && cm > distanceThreshold - 100)
{
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
}
if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 200)
{
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
}
if (cm <= distanceThreshold - 200 && cm > distanceThreshold - 280)
{
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
}

if (cm <= distanceThreshold - 280)
{
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
}
delay(100); // Wait for 100 millisecond(s)
}
long readUltrasonicDistance(int triggerPin, int echoPin)
{
pinMode(triggerPin, OUTPUT); // Clear the trigger
digitalWrite(triggerPin, LOW);
delayMicroseconds(2); // Sets the trigger pin to HIGH state for 10 microseconds
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT); // Reads the echo pin, and returns the sound wave travel time in microseconds
return pulseIn(echoPin, HIGH);
}