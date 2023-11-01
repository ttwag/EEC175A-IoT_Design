#include <LiquidCrystal.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#define trigPin 10
#define echoPin 13
//Initialize an LiquidCrystal object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //What these numbers are? 
//12 - Arduino Output Pin 12 connects to LCD Pin RS
//11 - Arduino Pin 11 connects to LCD Pin E (enable)
//5 - Arduino Pin 5 connects to LCD Pin D4
//4 - Arduino Pin 4 connects to LCD Pin D5
//3 - Arduino Pin 3 connects to LCD Pin D6
//2 - Arduino Pin 2 connects to LCD Pin D7

void setup() {
  lcd.begin(16, 2); // Initializes the LCD screen. 16 corrsponds to cols and 2 to rows
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.setCursor(8, 1); // Set the location for displayed text on LCD
}

void loop() {
  // Reset
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
  Serial.println(distance);

  if (distance >= 30 || distance <= 2) {
    lcd.print("Out of range");
    delay(500);
  }
  else {
    lcd.print(distance);
    lcd.print(" cm");
    delay(500);
  }
  delay(500);
  lcd.clear();
}
