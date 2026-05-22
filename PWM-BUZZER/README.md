# PWM Buzzer

Control a buzzer's tone frequency using PWM on STM32 Nucleo C031C6 (Wokwi simulation).

## Concepts Covered
- `tone(pin, frequency)` to generate PWM signal
- Array of frequencies to cycle through tones
- `millis()` for non-blocking time tracking
- Time-based debouncing (tuned to 200ms)

## Hardware
- ST Nucleo C031C6 (simulated on Wokwi)
- Buzzer on PA8
- Button on PB0 with INPUT_PULLUP

## Behavior
- Each button press cycles through 4 frequencies: C, E, G, C (262, 330, 392, 523 Hz)
- Debounce delay tuned to 200ms to prevent false triggers

## Key Learning
Debounce delay is not fixed — it depends on button characteristics and must be tuned experimentally.