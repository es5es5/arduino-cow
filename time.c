unsigned long time;

void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.print("Time: ");
  time = millis();

  Serial.println(time);    // 프로그램 시작후 지난 시간 출력
  delay(1000);             // 너무 많은 데이터를 보내지 않기 위해 1초 기다림
}
