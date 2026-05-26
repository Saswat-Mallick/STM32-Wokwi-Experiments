# Interrupts (EXTI)

## Overview
A button-controlled LED toggle using External Interrupts (EXTI) instead of polling.
The CPU doesn't waste cycles checking the button — it gets notified instantly when pressed.

## Concepts Covered
- External Interrupts (EXTI)
- ISR (Interrupt Service Routine)
- `volatile` keyword
- Flag pattern — ISR sets flag, loop handles work
- Interrupt-based debouncing using `millis()`
- `attachInterrupt()` and `digitalPinToInterrupt()`
- `FALLING` edge detection with `INPUT_PULLUP`

## Circuit
| Component | Pin |
|---|---|
| Button | D2 |
| LED | D13 |

## How It Works
1. Button press triggers a FALLING edge interrupt on pin D2
2. CPU jumps to `buttonISR()` immediately
3. ISR checks if 200ms has passed since last valid press (debounce)
4. If valid — sets `interruptFlag = true`
5. `loop()` detects the flag, toggles LED, prints state to Serial

## Board
ST Nucleo C031C6 (Arduino Framework via PlatformIO)