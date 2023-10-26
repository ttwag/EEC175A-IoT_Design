const int sensorPin = 0; //Analog pin A0
const int motorPin = 9; //Digital pin 9

int lightLevel, high = 0, low = 1023;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communciation with a baud rate of 9600 bits per second
}

void loop() {
  lightLevel = analogRead(sensorPin);  //Read the light level [0, 1023] from pin A0
  Serial.println(lightLevel); //Print the value of lightLevel to the serial monitor
  lightLevel = map(lightLevel,high, low, 0, 255);
  autoTune();
  analogWrite(motorPin, lightLevel); //PWM the motorPin with lightLevel that's 0 (always off) to 255 (always on)
}

//Adjusting low and high based on previous record. If suddenly you shine some light with higher intensity, you will make 255 even if analog is not 1023
void autoTune() { 
  if (lightLevel < low) {
    low = lightLevel;
  }
  if (lightLevel > high) {
    high = lightLevel;
  }
  lightLevel = map(lightLevel, low, high, 0, 255); // maps lightLevel to 0 to 255 according to low and high
  lightLevel = constrain(lightLevel, 0, 255); //Constrain lightLevel to be within [0, 255]
}
