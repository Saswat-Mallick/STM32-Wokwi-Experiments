# I2C OLED Display

Interfacing an SSD1306 OLED display with STM32 Nucleo C031C6 via I2C.

## Wiring
| OLED | Nucleo |
|------|--------|
| VCC  | 3.3V   |
| GND  | GND    |
| SDA  | PB7    |
| SCL  | PB6    |

## Libraries
- Adafruit SSD1306
- Adafruit GFX Library

## Concepts
- I2C protocol (SDA/SCL, addressing, ACK/NACK)
- SSD1306 address 0x3C
- Frame buffer — display.display() pushes to screen
- Partial rendering using setCursor(x, y)