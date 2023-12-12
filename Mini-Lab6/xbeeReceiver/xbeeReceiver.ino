#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}
void loop() {
  String c = "XBee not available.";
  String a;
  if (Serial.available()) {
    a = Serial.readString();
    Serial.print(a);
    
  }
  else {
    Serial.println(c);
  }
  lcd.print(a);
  delay(500);
  lcd.clear();
  delay(2000);
}
