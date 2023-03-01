#include <Servo.h>
Servo servo;

int mode = 4; //모드 선택 핀 (일반 / 랜덤)
int sw = 5; //스위치 핀

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo.write(150);
  pinMode(mode, INPUT_PULLUP);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(sw) == HIGH)
  {
    if (digitalRead(mode) == LOW) {
      normal(3);
    }
    else{
      ran();
    }
  }
}

void normal(int t)
{
  for (int i = 150; i >= 35; i--) {
    servo.write(i);
    delay(t);
  }
  while (digitalRead(sw) != LOW) {
      
  }
  for (int i = 35; i <= 150; i++) {
    servo.write(i);
    delay(t);
  }
}

void ran()
{
  delay(random(0, 3000));
  normal(random(1, 5));
}
