#define LED 8
#define BUTTON 7

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    }
}