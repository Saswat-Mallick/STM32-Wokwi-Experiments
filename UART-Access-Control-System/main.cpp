#include <Servo.h>

Servo myServo;
String command = "";

bool isUnlocked = false;

void ERRORBUZZ(){
  tone(PC6, 1000, 500);
  delay(500);
}

void setup() {
  Serial.begin(115200);
  pinMode(D13, OUTPUT);
  pinMode(D12, OUTPUT);
  myServo.attach(D10);
  myServo.write(0);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    
    if (c == '\n') {
      // Process command when Enter is pressed
      if (command == "1234") {
        isUnlocked = true;
        digitalWrite(D13, HIGH);
        Serial.println("Welcome user. Turning on motor.");
      } 
      else if (command == "LOCK") {
        isUnlocked = false;
        myServo.write(0);
        digitalWrite(D13, LOW);
        Serial.println("Thank You for your service. Locking motor.");
      }
      else {
        digitalWrite(D12,HIGH);
        ERRORBUZZ();
        Serial.println("Unknown command");
        delay(1000);
        digitalWrite(D12, LOW);
      }
      command = ""; // reset for next command
    } 
    else {
      command += c; // build the string character by character
    }
  }
  if (isUnlocked) {
  for (int pos = 0; pos <= 180; pos++) {
    if (Serial.available()) break; // exit sweep if command incoming
    myServo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {
    if (Serial.available()) break; // exit sweep if command incoming
    myServo.write(pos);
    delay(15);
  }
}
}