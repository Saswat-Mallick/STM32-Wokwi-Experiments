#define BTN   D2
#define LED1  D3
#define LED2  D4
#define LED3  D5

int state = 0;
bool lastBtn = HIGH;

void allOff() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void setup() {
  pinMode(BTN,  INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  allOff();
}

void loop() {
  bool currentBtn = digitalRead(BTN);

  if (lastBtn == HIGH && currentBtn == LOW) {
    delay(50);
    if (digitalRead(BTN) == LOW) {
      state = (state + 1) % 4;   // Cycle 0→1→2→3→0
      allOff();
      switch (state) {
        case 0: break;                         // All OFF
        case 1: digitalWrite(LED1, HIGH); break; // Only RED
        case 2: digitalWrite(LED2, HIGH); break; // Only GREEN
        case 3: digitalWrite(LED3, HIGH);
                digitalWrite(LED2, HIGH);
                digitalWrite(LED1, HIGH); break; // Only YELLOW
      }
    }
  }

  lastBtn = currentBtn;
}