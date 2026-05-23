#include <Servo.h>
#define BTN D2
#define AutoMode D7
#define ManualMode D8

Servo myServo;

int state = 1;
bool lastBtn = HIGH;

void setup() {
  myServo.attach(9); // PWM pin
  pinMode(BTN, INPUT_PULLUP);
  pinMode(AutoMode,OUTPUT);
  pinMode(ManualMode,OUTPUT);
}

void loop() {
  // PART 1 — button check (runs once on press)
  bool currentBtn = digitalRead(BTN);
  if (lastBtn == HIGH && currentBtn == LOW) {
    delay(50);
    if (digitalRead(BTN) == LOW) {
      state = !state;
    }
  }
  lastBtn = currentBtn;

  // PART 2 — state execution (runs every loop iteration)
  if (state == 0) {
    digitalWrite(AutoMode,HIGH);
    digitalWrite(ManualMode,LOW); 
    myServo.write(0);
    delay(1000);
    myServo.write(180);
    delay(1000);
  } else {
    digitalWrite(AutoMode,LOW);
    digitalWrite(ManualMode,HIGH);
    int potVal = analogRead(A0);
    int angle = map(potVal, 0, 4095, 0, 180);
    myServo.write(angle);
    delay(15);
  }
}