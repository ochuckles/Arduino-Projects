//Reads the State of a Pot and displays on screen

int potPin = 5;
int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;
int ledPin5 = 6;
int ledPin6 = 7;

void setup()
{
  //sets the button pin as an input
  pinMode(potPin, INPUT);  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
    
  //Allows us to listen to serial communications from the arduino
  Serial.begin(9600); 
}

void loop()
{
  // print the button state to a serial terminal
  int val = analogRead(potPin);

  if (val > 0) digitalWrite(ledPin1, HIGH);
    else digitalWrite(ledPin1, LOW);
  if (val > 467) digitalWrite(ledPin2, HIGH);
    else digitalWrite(ledPin2, LOW);
  if (val > 560) digitalWrite(ledPin3, HIGH);
    else digitalWrite(ledPin3, LOW);
  if (val > 660) digitalWrite(ledPin4, HIGH);
    else digitalWrite(ledPin4, LOW);
  if (val > 788) digitalWrite(ledPin5, HIGH);
    else digitalWrite(ledPin5, LOW);
  if (val > 1000) digitalWrite(ledPin6, HIGH);
    else digitalWrite(ledPin6, LOW);
    
  Serial.println(analogRead(potPin)); 
  delay(100);
  //wait one second, then print again.
}
