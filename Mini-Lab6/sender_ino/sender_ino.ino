#include <SoftwareSerial.h>
#include "Arduino.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#define trigPin 10
#define echoPin 13


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);          
  digitalWrite(trigPin, LOW);     

  //Calculate the distance
  duration = pulseIn(echoPin, HIGH);  // Calculates the time-width of the echo signal from sensor
  distance = (duration / 2) * 0.0344;
  // Serial.println(distance);
  // mySerial.write(distance);


	//Send the message:
  Serial.print("1\n");
	//Serial.print('<'); 	//Starting symbol
 	// Serial.print(String(distance));
	//Serial.println('>');//Ending symbol
  delay(1000);
}
