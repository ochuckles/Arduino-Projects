//Reads the State of a Pot and displays on screen

int potPin1 = A0;
int potPin2 = A1;

void setup()
{
  //sets the pins for the pots
  pinMode(potPin1, INPUT);  
  pinMode(potPin2, INPUT);
    
  //Allows us to listen to serial communications from the arduino
  Serial.begin(9600); 
}

void loop()
{
  // Print the state of the pots

  String pot1 = String(analogRead(potPin1));
  String pot2 = String(analogRead(potPin2));
  String readout = pot2 + "   " + pot1;   
  
  Serial.println(readout); 
  delay(4);
}
