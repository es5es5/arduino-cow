#define PLACE_FORMER 2 // 초기 사조
#define PLACE_MIDDLE 3 // 중기 사조
#define PLACE_LATTER 4 // 후기 사조

// RFID 를 대체할 버튼
#define BUTTON_FORMER 5 // 초기 사조의 BUTTON
#define BUTTON_MIDDLE 6 // 중기 사조의 BUTTON
#define BUTTON_LATTER 7 // 후기 사조의 BUTTON

#define LED_FORMER 8 // 초기 사조의 LED
#define LED_MIDDLE 9 // 중기 사조의 LED
#define LED_LATTER 10 // 후기 사조의 LED

void setup() {
  Serial.begin(9600);
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
  if (digitalRead(BUTTON_FORMER) == HIGH) { // 초기 버튼을 누르면
    Serial.println("FORMER 버튼 누름");
    if (digitalRead(LED_FORMER) == LOW) { // 초기 LED 가 꺼져있으면
      digitalWrite(LED_FORMER, HIGH); // LED를 켜라
      delay(1000);
      Serial.println("FORMER LED 켜짐");
    } else if (digitalRead(LED_FORMER) == HIGH) { // 초기 LED 가 켜져있으면,
      digitalWrite(LED_FORMER, LOW);
      Serial.println("FORMER LED 꺼짐");
      delay(1000);
    }
  }
  if (digitalRead(BUTTON_MIDDLE) == HIGH) {
    if (digitalRead(LED_MIDDLE) == LOW) { // 초기 LED 가 꺼져있으면
      digitalWrite(LED_MIDDLE, HIGH); // LED를 켜라
      delay(1000);
    } else if (digitalRead(LED_MIDDLE) == HIGH) { // 초기 LED 가 켜져있으면,
      digitalWrite(LED_MIDDLE, LOW);
      delay(1000);
    }
  }
  if (digitalRead(BUTTON_LATTER) == HIGH) {
    if (digitalRead(LED_LATTER) == LOW) { // 초기 LED 가 꺼져있으면
      digitalWrite(LED_LATTER, HIGH); // LED를 켜라
      delay(1000);
    } else if (digitalRead(LED_LATTER) == HIGH) { // 초기 LED 가 켜져있으면,
      digitalWrite(LED_LATTER, LOW);
      delay(1000);
    }
  }
}
