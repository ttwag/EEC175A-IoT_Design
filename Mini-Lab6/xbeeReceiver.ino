//Constants
const int ledPin = 13; //Led to Arduino pin 3 (PWM)

//Variables
char incomingByte ; //Variable to store the incoming byte
char msg[1];    //Message - array from 0 to 2 (3 values - PWM - e.g. 240)
byte index;     //Index of array

void setup() {
  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
  pinMode(ledPin, OUTPUT);
}

void loop() {

  while (Serial.available() > 0) {
    //Read the incoming byte
    incomingByte = Serial.read();
    Serial.print("incoming ");
    Serial.println(incomingByte);
    //Start the message when the '<' symbol is received
    if (incomingByte == '1')
    {
      digitalWrite(ledPin, HIGH);
    }
    if (incomingByte == '0')
    {
      digitalWrite(ledPin, LOW);
    }
    //End the message when the '>' symbol is received
    else if (incomingByte == '>')
    {
      break; // Done reading - exit from while loop!
    }
  }
  delay(1000);
}
