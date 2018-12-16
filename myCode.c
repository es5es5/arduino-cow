#define PLACE-A 2 // 초기
#define PLACE-B 3 // 중기
#define PLACE-C 4 // 후기

// RFID 를 대체할 버튼
#define BUTTON-A 5
#define BUTTON-B 6
#define BUTTON-C 7

#define LED-A 8 // LED
#define LED-B 9
#define LED-C 10

boolean buttonA = false;
boolean buttonB = false;
boolean buttonC = false;

void setup() {
  pinMode(LED-A, OUTPUT);
  pinMode(LED-A, OUTPUT);
  pinMode(LED-A, OUTPUT);
  pinMode(BUTTON-A, INPUT);
  pinMode(BUTTON-B, INPUT);
  pinMode(BUTTON-C, INPUT);
  pinMode(LED-A, OUTPUT);
  pinMode(LED-B, OUTPUT);
  pinMode(LED-C, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON-A) == HIGH) {
    digitalWrite(LED-A, HIGH);
    delay(500);
    digitalWrite(LED-A, LOW);
  } else if (digitalRead(BUTTON-B) == HIGH){
    digitalWrite(LED-B, HIGH);
    delay(500);
    digitalWrite(LED-B, LOW);
  } else if (digitalRead(BUTTON-C) == HIGH) {
    digitalWrite(LED-C, HIGH);
    delay(500);
    digitalWrite(LED-C, LOW);
  }
}
