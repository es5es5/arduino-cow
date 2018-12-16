#include <SoftwareSerial.h>
#include <math.h>

#define TEMPERATURE A0 // 온도 센서
#define BLUETOOTH_TX 2 // 사료조 EMPTY
#define BLUETOOTH_RX 3 // 사료조 EMPTY
#define BUTTON_EMPTY 4 // 사료조 EMPTY

// RFID 를 대체할 버튼
#define BUTTON_FORMER 5 // 초기 사조의 BUTTON
#define BUTTON_MIDDLE 6 // 중기 사조의 BUTTON
#define BUTTON_LATTER 7 // 후기 사조의 BUTTON

#define LED_FORMER 8 // 초기 사조의 LED
#define LED_MIDDLE 9 // 중기 사조의 LED
#define LED_LATTER 10 // 후기 사조의 LED

SoftwareSerial BTSerial(BLUETOOTH_TX, BLUETOOTH_RX);

unsigned long previous_time_former = 0;
unsigned long current_time_former = 0;
unsigned long previous_time_middle = 0;
unsigned long current_time_middle = 0;
unsigned long previous_time_latter = 0;
unsigned long current_time_latter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("안녕하세요 ~ ICT 프로젝트 입니다.");
  BTSerial.begin(9600);
  pinMode(BUTTON_EMPTY, INPUT);
  pinMode(BUTTON_FORMER, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT);
  pinMode(BUTTON_LATTER, INPUT);
  pinMode(LED_FORMER, OUTPUT);
  pinMode(LED_MIDDLE, OUTPUT);
  pinMode(LED_LATTER, OUTPUT);
}


void loop() {
  // 블루투스
  // if(BTSerial.available() > 0) {
  //   bluetooth = BTSerial.read();
  //   Serial.println(bluetooth);
    // if (digitalRead(BUTTON_EMPTY) == HIGH) {
    //   Serial.println("블루투스 버튼 ON");
    //   BTSerial.write("aaaaa");
    //   delay(300);
    // }
  // }
  // if(Serial.available()) {
  //   Serial.println("ddd");
  // }
  // 버튼 누르면 해당하는 불이 들어온다.
  Serial.println(BTSerial.available());
  if (digitalRead(BUTTON_FORMER) == HIGH) { // 초기 버튼을 누르면
    if (digitalRead(LED_FORMER) == LOW) { // 초기 LED 가 꺼져있으면
      digitalWrite(LED_FORMER, HIGH); // LED를 켜라
      previous_time_former = millis();
      delay(300);
    } else if (digitalRead(LED_FORMER) == HIGH) { // 초기 LED 가 켜져있으면,
      digitalWrite(LED_FORMER, LOW);
      current_time_former = millis();
      unsigned long former_timer = current_time_former - previous_time_former;
      Serial.print("초기 사료조에서 체류 시간 : ");
      Serial.print(former_timer / 1000);
      Serial.println("초");
      delay(300);
    }
  }
  if (digitalRead(BUTTON_MIDDLE) == HIGH) {
    if (digitalRead(LED_MIDDLE) == LOW) { // 초기 LED 가 꺼져있으면
      digitalWrite(LED_MIDDLE, HIGH); // LED를 켜라
      previous_time_middle = millis();
      delay(300);
    } else if (digitalRead(LED_MIDDLE) == HIGH) { // 초기 LED 가 켜져있으면,
      digitalWrite(LED_MIDDLE, LOW);
      current_time_middle = millis();
      unsigned long middle_timer = current_time_middle - previous_time_middle;
      Serial.print("중기 사료조에서 체류 시간 : ");
      Serial.print(middle_timer / 1000);
      Serial.println("초");
      delay(300);
    }
  }
  if (digitalRead(BUTTON_LATTER) == HIGH) {
    if (digitalRead(LED_LATTER) == LOW) { // 초기 LED 가 꺼져있으면
      digitalWrite(LED_LATTER, HIGH); // LED를 켜라
      previous_time_latter = millis();
      delay(300);
    } else if (digitalRead(LED_LATTER) == HIGH) { // 초기 LED 가 켜져있으면,
      digitalWrite(LED_LATTER, LOW);
      current_time_latter = millis();
      unsigned long latter_timer = current_time_latter - previous_time_latter;
      Serial.print("후기 사료조에서 체류 시간 : ");
      Serial.print(latter_timer / 1000);
      Serial.println("초");
      delay(300);
    }
  }
}
