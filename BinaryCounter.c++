int pinArray[] = {2, 3, 4, 5, 6, 7, 8, 9};
int count = 0;
int result = 0;
int timer = 30;
void setup()
{
 	Serial.begin(9600);
	for (count=0;count<8;count++) 
	{
	pinMode(pinArray[count], OUTPUT);
	}
}
void loop() 
{

 int x = 132;
for(int i = 7; i>=0; i--)
{
	double result = pow(2,i);
  	if(x - result >=0)
    {
      digitalWrite(pinArray[i],HIGH);
      x = x-result;
    }
}

}
 
  