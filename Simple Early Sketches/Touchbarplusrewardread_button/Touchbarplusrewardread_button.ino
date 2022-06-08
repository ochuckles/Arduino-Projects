/*  Code for the arduino to be used with Unity systems, report it's activation of the pump, and to be utilized with a pushbutton outside of Unity.
 *  Originally created by Yoni Browning. Updated by Ian O'Leary.
 */

// Constant variables
const int buttonPin = 2;
const int ledPin = 13;
const int pumpPin = 8;
const int speakPin = 11;

char rewards[20];

int lf = 10;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int lastButtonState = 0;     // previous state of the button
int buttonState = 0;

void setup() {
  // sets up the pins as output or input

pinMode(buttonPin,INPUT);

pinMode(ledPin, OUTPUT);
pinMode(pumpPin,OUTPUT);
pinMode(speakPin,OUTPUT);

//Instantiate serial port
Serial.begin(115200);

}

void loop() {
  // Read button state
  buttonState = digitalRead(buttonPin);



    // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  
    if (lastButtonState == LOW && buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(pumpPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    digitalWrite(pumpPin, LOW);
    }else (buttonState == LOW);{
    digitalWrite(ledPin, LOW);
    digitalWrite(pumpPin, LOW);
  } 
    if (buttonState == HIGH){
    digitalWrite(ledPin,HIGH);
    Serial.println("1");

  }else {
    digitalWrite(ledPin,LOW);
    Serial.println("0");

  }
  
  Serial.readBytesUntil(lf, rewards, 1);
    if(strcmp(rewards,"r")==0){
       digitalWrite(pumpPin, HIGH);   
       digitalWrite(speakPin, HIGH);    
   }
    else{
      digitalWrite(pumpPin,LOW);
      digitalWrite(speakPin,LOW);
      }
  
  //write  current state to serial
  delay(0.001);

}
