# FSM LED Experiment

## Overview
A finite state machine (FSM) implemented in C on ST Nucleo C031C6, 
controlling 3 LEDs through button presses using the Arduino framework on Wokwi.

## Hardware
- ST Nucleo C031C6
- 3 LEDs (Red, Green, Yellow)
- 1 Push Button

## Pin Configuration
| Component | Pin |
|---|---|
| Red LED | D3 |
| Green LED | D4 |
| Yellow LED | D5 |
| Push Button | D2 |

## FSM States
| State | Output |
|---|---|
| State 0 | All LEDs OFF |
| State 1 | Red LED ON |
| State 2 | Green LED ON |
| State 3 | All LEDs ON |

## Concepts Covered
- GPIO OUTPUT and INPUT_PULLUP
- Edge detection
- Debouncing
- FSM state transitions in C

## Tools Used
- Wokwi Simulator
- Arduino Framework
- PlatformIO + VS Code
