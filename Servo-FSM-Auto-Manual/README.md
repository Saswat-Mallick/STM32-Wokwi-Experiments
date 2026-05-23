# Servo FSM — Auto/Manual Mode

A servo motor control experiment using FSM (Finite State Machine) with two modes, 
built on ST Nucleo C031C6 using Arduino framework on Wokwi.

## Modes
| Mode | LED | Behaviour |
|---|---|---|
| Auto (Sweep) | D7 ON | Servo sweeps 0° → 180° → 0° continuously |
| Manual (Pot) | D8 ON | Servo angle controlled by potentiometer |

## Components
- ST Nucleo C031C6
- SG90 Servo Motor
- Potentiometer
- 2x LEDs
- Push Button

## Wiring
| Component | Pin |
|---|---|
| Servo PWM | D9 |
| Potentiometer | A0 |
| Button | D2 |
| Auto Mode LED | D7 |
| Manual Mode LED | D8 |

## Concepts Covered
- PWM signal controlling servo angle
- ADC reading from potentiometer
- `map()` function for range conversion
- FSM state toggling with debounced button
- LED indicators for state feedback