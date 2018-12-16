#define PLACE_FORMER 2 // 초기
#define PLACE_MIDDLE 3 // 중기
#define PLACE_LATTER 4 // 후기

// RFID 를 대체할 버튼
#define BUTTON_FORMER 5
#define BUTTON_MIDDLE 6
#define BUTTON_LATTER 7

#define LED_FORMER 8 // LED
#define LED_MIDDLE 9
#define LED_LATTER 10

// 장소 현재 상태
boolean former_status = false;
boolean middle_status = false;
boolean latter_status = false;


void setup() {
  pinMode(PLACE_FORMER, OUTPUT);
  pinMode(PLACE_MIDDLE, OUTPUT);
  pinMode(PLACE_LATTER, OUTPUT);
  pinMode(BUTTON_FORMER, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT);
  pinMode(BUTTON_LATTER, INPUT);
  pinMode(LED_FORMER, OUTPUT);
  pinMode(LED_MIDDLE, OUTPUT);
  pinMode(LED_LATTER, OUTPUT);
}


void loop() {
  // 버튼 누르면 해당하는 불이 들어온다.
  if (digitalRead(BUTTON_FORMER) == HIGH || digitalRead(BUTTON_FORMER) == LOW) {
    former_status = !former_status;
    if (former_status == true) {
      digitalWrite(LED_FORMER, HIGH);
    } else if (former == false) {
      digitalWrite(LED_FORMER, LOW);
      delay(500);
    }
  } else if (digitalRead(BUTTON_MIDDLE) == HIGH) {
    digitalWrite(LED_MIDDLE, HIGH);
    delay(500);
    digitalWrite(LED_MIDDLE, LOW);
  } else if (digitalRead(BUTTON_LATTER) == HIGH) {
    digitalWrite(LED_LATTER, HIGH);
    delay(500);
    digitalWrite(LED_LATTER, LOW);
  }
}
