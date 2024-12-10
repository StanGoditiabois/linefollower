volatile bool toggle = false;

void setup() 
{
  pinMode(23,INPUT); // pin 22 is ook een knop.
  attachInterrupt(23,ISR,RISING);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(toggle);
  delay(10000);
}

void ISR()
{
  toggle = !toggle;
}