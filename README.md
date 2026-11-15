# Multi-Sensor Environmental Monitoring System Using LPC2129

## Project Overview

Developed a multi-sensor environmental monitoring system using the LPC2129 ARM7 microcontroller to monitor temperature, light intensity, soil moisture, and water presence.

The system processes sensor readings and classifies environmental conditions into SAFE, WARNING, and DANGER states. It provides visual alerts through LEDs, displays status on an LCD, and transmits sensor information to a PC using UART communication.

## Hardware Components

- LPC2129 ARM7 Microcontroller
- LM35 Temperature Sensor
- LDR Sensor
- Soil Moisture Sensor
- Water Sensor
- 16x2 LCD Display
- Green, Yellow and Red LEDs

## Pin Connections

### Sensors
- LM35 OUT – P0.27 (AD0.0)
- LDR OUT – P0.28 (AD0.1)
- Soil Moisture AO – P0.29 (AD0.2)
- Water Sensor DO – P0.14

### LEDs
- Green LED – P0.17
- Yellow LED – P0.18
- Red LED – P0.19

### LCD
- RS – P1.17
- RW – P1.18
- EN – P1.19
- D4 – P1.20
- D5 – P1.21
- D6 – P1.22
- D7 – P1.23

## Working Principle

1. LM35 measures ambient temperature through ADC channel 0.
2. LDR monitors surrounding light intensity through ADC channel 1.
3. Soil moisture sensor measures moisture levels through ADC channel 2.
4. Water sensor detects water presence through a digital GPIO input.
5. LPC2129 processes the sensor readings and determines the system status.
6. LCD displays temperature and safety status.
7. LEDs indicate SAFE, WARNING, and DANGER conditions.
8. UART transmits sensor readings and system status at 9600 baud.

## Safety Classification

| Condition | Description | LED |
|---|---|---|
| SAFE | All sensor readings within configured limits | Green |
| WARNING | Temperature between 35°C and 40°C only | Yellow |
| DANGER | Any other abnormal condition | Red |

## Software and Tools

- Embedded C
- Keil µVision
- LPC2129 ARM7
- ADC
- GPIO
- UART
- LCD 4-bit interface

## Repository Contents

- `main.c` – Main application logic
- `header.h` – Function declarations
- `adc_driver.c` – ADC driver
- `driver.c` – Peripheral driver
- `delay.c` – Delay functions
- `lcd_4bit_driver.c` – LCD driver
- `uart_driver.c` – UART driver
- `Startup.s` – Startup assembly
- Keil project files
- Generated HEX firmware file

## Author

Praveen Kannan
