#include "Arduino.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#define trigPin 10
#define echoPin 13

char mystr[8] = "abcde123"; //String data
String mystring;

void setup() {
  // Begin the Serial at 9600 Baud
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Need 10 µs pulse according to sensor's data sheet
  // Send the pulse through trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);          
  digitalWrite(trigPin, LOW);     

  //Calculate the distance
  duration = pulseIn(echoPin, HIGH);  // Calculates the time-width of the echo signal from sensor
  //(high level time)*(velocity/2)
  // 0.0344 because duration is in µs and speed of sound is 344 m/s. We need 0.0344 cm/µs to match unit
  distance = (duration / 2) * 0.0344;
  
  Serial.println(String(distance)); //Print the float as a string to the port.
  delay(3000);
}
