#include <SoftwareSerial.h>
SoftwareSerial mySerial (4, 5);
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float a = mySerial.read();
  Serial.println(a);
  delay(3500);
}
