#include <math.h>

int B=4250;
int iPinln = A0;

void setup(){
  Serial.begin(9600);
}

void loop() {
  float fTm;
  int iInput = analogRead(iPinln);

  float fR = (float)(1023-iInput)*10000/iInput;
  fTm = 1/(log(fR/10000)/B + 1/298.15) - 273.15;

  Serial.print("current Temperature: ");
  Serial.print(fTm);
  Serial.println("C");

  delay(1000);
}