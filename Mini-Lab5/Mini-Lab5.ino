#include <SoftwareSerial.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

#define trigPin 10
#define echoPin 13
#define distance_tag "Distance: "

SoftwareSerial BTserial (3, 4);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  //Bluetooth
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  //Bluetooth
  String setName = String("AT+NAME=BT_Tao\r\n"); //sets bluetooth name as BT_Tao
  BTserial.begin(9600);
  BTserial.print(setName);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) * 0.0344;

  Serial.println(distance);
  //Send 'distance' measurements to BLE module
  BTserial.print("Distance: ");
  BTserial.print(distance);
  BTserial.print("\r\n");
  delay(1000);
}
