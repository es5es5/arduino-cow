int iPin1 = 7;
int iPin2 = 8;
int iPin3 = 9;

void setup() {
  pinMode(iPin1, OUTPUT);
  pinMode(iPin2, OUTPUT);
  pinMode(iPin3, OUTPUT);
}

void loop() {
  digitalWrite(iPin1, HIGH); digitalWrite(iPin2, LOW); digitalWrite(iPin3, LOW);
  delay(2500);
  digitalWrite(iPin1, LOW); digitalWrite(iPin2, HIGH); digitalWrite(iPin3, LOW);
  delay(500);
  digitalWrite(iPin1, LOW); digitalWrite(iPin2, LOW); digitalWrite(iPin3, HIGH);
  delay(5500);    
}