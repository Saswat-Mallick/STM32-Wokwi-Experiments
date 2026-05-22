#define BUZZER_PIN PA8
#define BUTTON_PIN PB0

int frequencies[] = {262, 330, 392, 523}; // C, E, G, C
int numFreqs = 4;
int currentFreq = 0;

bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
#define DEBOUNCE_DELAY 200

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (millis() - lastDebounceTime > DEBOUNCE_DELAY) {
      currentFreq = (currentFreq + 1) % numFreqs;
      lastDebounceTime = millis();
    }
  }

  lastButtonState = currentButtonState;
  tone(BUZZER_PIN, frequencies[currentFreq]);
}