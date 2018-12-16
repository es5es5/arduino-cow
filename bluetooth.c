#include <SoftwareSerial.h>
int iPinTx = 2;
int iPinRx = 3;
int iPinLed = 5;

SoftwareSerial BTSerial(iPinTx, iPinRx);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Output: Hello!");

  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()) {
    char cLetter= BTSerial.read();
    Serial.write(cLetter);
    Serial.write("\n");
    if (cLetter == 'a') { analogWrite(iPinLed, 150); Serial.println("LED On !");}
    if (cLetter == 'b') { analogWrite(iPinLed, 0); Serial.println("LED Off !");}
  }

  if(Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
