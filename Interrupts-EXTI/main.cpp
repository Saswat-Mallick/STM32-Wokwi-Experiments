volatile bool ledState = false;
volatile bool interruptFlag = false;
volatile unsigned long lastInterruptTime = 0;

const int buttonPin = 2;
const int ledPin = 13;

void buttonISR() {
  unsigned long now = millis();
  if (now - lastInterruptTime > 200) {  // 200ms debounce window
    interruptFlag = true;
    lastInterruptTime = now;
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}

void loop() {
  if (interruptFlag) {
    interruptFlag = false;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    Serial.println(ledState ? "LED ON" : "LED OFF");
  }
}