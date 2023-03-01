#include <Servo.h>
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo.write(150);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(5) == HIGH)
  {
    if (digitalRead(4) == LOW) {
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
  while (digitalRead(5) != LOW) {
      
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
