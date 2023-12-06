#include <SoftwareSerial.h>
#include "Arduino.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#define trigPin 10
#define echoPin 13

SoftwareSerial mySerial (4, 5); //Tx, Rx
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
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
  Serial.println(distance);
  mySerial.write(distance);
  delay(3500);
}
