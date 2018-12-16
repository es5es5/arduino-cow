int iPinLed = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("Contact your card!");
  pinMode(iPinLed, OUTPUT);
  digitalWrite(iPinLed, HIGH); delay(1000);
  digitalWrite(iPinLed, LOW);
}

void loop() {
  if (Serial.available()) {
    String s = Serial.readString();
    Serial.println(s);

    if(s=="5C4DD503") {
      digitalWrite(iPinLed, HIGH);
      Serial.println("Correct RFID Card. Unlocked !!");
      delay(1000);
    } else {
      digitalWrite(iPinLed, LOW);
      Serial.println("Please a correct RFID Card !!");
    }
  }
  digitalWrite(iPinLed, LOW);
}