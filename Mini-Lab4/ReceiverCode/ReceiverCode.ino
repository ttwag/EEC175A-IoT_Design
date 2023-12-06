#include <string.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char mystr[10]; //Initialized variable to store recieved data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() {
  //Serial.readBytes(mystr,5); //Read the serial data and store in var
  //Serial.println(mystr); //Print data on Serial Monitor
  String a = "Not Received";
  
  if (Serial.available() > 0) {
    a = Serial.readString();
  }
  Serial.println(a);

  lcd.print(a);
  delay(500);
  lcd.clear();
  delay(2000);
}
