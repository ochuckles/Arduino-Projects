/* 
 *  Simple Photovoltaic Resistor and LED
 */

int sensePin = 0;
int ledPin = 13;
 
void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT); //isnt necessary

  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int val = analogRead(sensePin);

 if (val < 60) digitalWrite(ledPin, HIGH);
 else digitalWrite(ledPin, LOW);
}
