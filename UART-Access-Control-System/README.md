# UART Access Control System

A UART-based access control system built on STM32 (Nucleo C031C6) using Arduino framework on Wokwi simulator.

## Description
A serial command-driven system where a passcode controls a servo motor.
Correct passcode unlocks and continuously rotates the motor. Wrong input
triggers a buzzer and error LED. LOCK command stops the motor.

## Features
- Passcode protected motor control via UART
- Continuous servo sweep when unlocked
- Buzzer alert on wrong passcode
- LED indicators (unlock status + error flash)
- Clean command parsing with reset

## Commands
| Command | Action |
|---|---|
| `1234` | Unlocks and starts motor |
| `LOCK` | Stops and locks motor |
| Any other input | Buzzer beeps + error LED flashes |

## Hardware (Simulated on Wokwi)
- STM32 Nucleo C031C6
- Servo Motor (D10)
- Buzzer (PC6)
- LED x2 (D13, D12)

## Concepts Covered
- UART initialization and baud rate
- Serial TX and RX
- Command parsing via string building
- Servo PWM control
- Boolean state flag
- Non-blocking UART during servo sweep

## Platform
- Framework: Arduino
- Simulator: Wokwi
- IDE: PlatformIO + VS Code