# Simple Calculator - AVR

## Author: Basel Mohamed Mostafa Sayed

### Overview

This project is a simple calculator program written in C for AVR microcontrollers, specifically for the ATmega32. The calculator allows users to perform basic arithmetic operations (addition, subtraction, multiplication, and division) on floating-point numbers using a 4x4 keypad as input and displays the results on a 16x2 LCD screen.

--> This Project uses my very own DIO, Keypad 4x4 and LCD interfaces I built for the ATmega32.
--> This is my first AVR project after using and making many projects with the Arduino UNO, and loving every second of it, I decided to look into learning Embedded Systems using AVR controllers for starters.

### Table of Contents

- [Features](#features)
- [Hardware Components](#hardware-components)
- [Software Components](#software-components)
- [Circuit Diagram](#circuit-diagram)
- [How It Works](#how-it-works)
- [Functions Overview](#functions-overview)
- [License](#license)

### Features

- Supports floating-point arithmetic.
- User-friendly interface with clear prompts on a 16x2 LCD screen.
- Simple and intuitive 4x4 keypad interface.
- Real-time input display on the LCD.
- Custom characters can be displayed on the LCD.

### Hardware Components

- ATmega32 Microcontroller
- 16x2 LCD Display
- 4x4 Keypad
- 10kΩ Potentiometer (for contrast adjustment of the LCD)
- Resistors, Capacitors, and Connecting Wires
- Breadboard and Power Supply

### Software Components

- **AVR-GCC Compiler**: Used to compile the C code.
- **AVRDUDE**: Used to upload the compiled code to the ATmega32 microcontroller.
- **Microchip Studio (optional)**: IDE used for writing and debugging the code.

### Circuit Diagram

![Schematic & Wiring connection](URL-of-your-image)


### How It Works
1) Initialization: The LCD and keypad are initialized.
2) User Input: The user is prompted to enter an operation (Addition, Subtraction, Multiplication, or Division).
3) Operand Entry: The user enters the first and second operands via the keypad.
4) Calculation: The microcontroller performs the selected operation.
5) Result Display: The result is displayed on the LCD screen.
--> Where each section is put into a function of It's own.

### Functions Overview
- void CALC_init(void): Initializes the calculator startup screen.
- f32 CALC_getNumberFromKeypad(void): Waits for the user to input a number on the keypad and returns the floating-point number.
- u8 CALC_getOperation(void): Waits for the user to input an operation (A: Division, B: Multiplication, C: Subtraction, D: Addition).
- void CALC_displayResult(f32 copy_u8Result, u8 copy_u8Operation): Displays the result of the calculation on the LCD.

### License
This project is licensed under the GNU License - see the LICENSE file for details.
