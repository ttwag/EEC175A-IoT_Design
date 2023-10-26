
//Include the DHT library file: Tools -> Manage Libraries (or) Sketch -> Include Library -> Add .zip / Manage libraries
#include <DHT.h>
#include <arduino.h>
#define DHTPIN 2
#define DHTTYPE DHT11
int motorPin = 9;

//First check the ambient temperature
//Then set temperature threshold variable accordingly to test for functionality of your circuit 
// (For this lab, the user sets the temperature threshold value via the Serial Monitor)
// Fan is ON when Temperature is below temp_threshold
// Fan is OFF when Temperature is above temp_threshold

float temp_threshold = 25.00;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(DHTPIN, INPUT);
  pinMode(motorPin, OUTPUT);
  
  Serial.println("Please set the teperature threshold: ");
  while (Serial.available() == 0){
  } 
  temp_threshold = Serial.parseFloat();
  //Serial.setTimeout(20000);
}

void loop() {
  //delay is recommended between sensor reads
  delay(2000);
  float temp = dht.readTemperature();
  //Check Serial Monitor console to observe temperature values
  Serial.println(temp);

  //delay is recommended between sensor reads
  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    digitalWrite(motorPin, LOW);
    return;
  }
  else {
    if (temp <= temp_threshold) {
      Serial.print("Temperature is lower than ");
      Serial.println(temp_threshold);
      //Check Serial Monitor console to observe temperature values
      digitalWrite(motorPin, HIGH);
    }
    else {
      Serial.print("Temperature is higher than ");
      Serial.println(temp_threshold);
      //Check Serial Monitor console to observe temperature values
      digitalWrite(motorPin, LOW);
    }
  }
}
