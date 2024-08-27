/*
 * MAIN_FUNC.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Basel Mohamed Mostafa Sayed
 *      Description: This folder contains all main.c specific function source code that is used
 *      in the application.
 */
#define F_CPU 16000000UL

/* UTILS Libraries */
#include "UTILS/STD_TYPES.h"
#include "UTILS/Bit_operation.h"

/* MCAL Layer */
#include "ATmega32_DIO/DIO_PROGRAM.h"
#include <util/delay.h>

/* HAL Layer */
#include "../../../LCD_DRIVER/LCD_DRIVER/LCD_PROGRAM.c"
#include "../../../LCD_DRIVER/LCD_DRIVER/LCD_PROGRAM.h"
#include "../../../KEYPAD4x4_DRIVER/KEYPAD4x4_DRIVER/KEYPAD4X4_PROGRAM.h"
#include "../../../KEYPAD4x4_DRIVER/KEYPAD4x4_DRIVER/KEYPAD4X4_PROGRAM.c"
#include "MAIN_FUNC.h"

u8 smileChar[] = {
	0B00000,
	0B00000,
	0B01010,
	0B00000,
	0B10001,
	0B01110,
	0B00000,
	0B00000
};

void CALC_init(void) {
    LCD_clear();
    LCD_moveCursor(0, 0);
    LCD_displayString((u8*)"Simple Calc.");
    LCD_moveCursor(1, 0);
    LCD_displayString((u8*)"Basel Mohamed.");
    LCD_createAndDisplayChar(0, smileChar, 1, 15);
    _delay_ms(2000);
    LCD_clear();
    LCD_moveCursor(0, 0);
    LCD_displayString((u8*)"Enter Operation: ");
}

f32 CALC_getNumberFromKeypad(void) {
	f32 integerPart = 0;
	f32 fractionalPart = 0;
	u8 local_u8KeypadKey;
	u8 isDecimal = 0;
	f32 decimalFactor = 0.1;

	while (1) {
		local_u8KeypadKey = KEYPAD_getKey();
		if (local_u8KeypadKey != KEYPAD_NOT_PRESSED) {
			if (local_u8KeypadKey >= '0' && local_u8KeypadKey <= '9') {
				if (!isDecimal) {
					integerPart = integerPart * 10 + (local_u8KeypadKey - '0');
					LCD_displayChar(local_u8KeypadKey);
					} else {
					fractionalPart += (local_u8KeypadKey - '0') * decimalFactor;
					decimalFactor *= 0.1;
					LCD_displayChar(local_u8KeypadKey);
				}
				} else if (local_u8KeypadKey == '*') {
				if (!isDecimal) {
					isDecimal = 1;
					LCD_displayChar('.');
				}
				} else if (local_u8KeypadKey == '=') {
				break; // Exit input loop when "=" is pressed
			}
		}
	}

	return integerPart + fractionalPart;
}


u8 CALC_getOperation(void) {
	u8 local_u8KeypadKey;
	u8 operation;

	while (1) {
		local_u8KeypadKey = KEYPAD_getKey();

		if (local_u8KeypadKey != KEYPAD_NOT_PRESSED) {
			// Check if the pressed key is a valid operation
			if (local_u8KeypadKey == 'A' || local_u8KeypadKey == 'B' ||
					local_u8KeypadKey == 'C' || local_u8KeypadKey == 'D') {
				operation = local_u8KeypadKey;
				LCD_moveCursor(1, 0); // Move cursor to the next line
				LCD_displayChar(operation); // Display the operation
				_delay_ms(1000);
				break; // Exit the loop after getting a valid operation
			}
		}
	}
	return operation;
}

void CALC_displayResult(f32 copy_u8Result, u8 copy_u8Operation) {
	LCD_clear();  // Clear LCD before displaying the result
	LCD_displayString((u8*)"Result of ");
	switch (copy_u8Operation) {
		case 'A':
		LCD_displayString((u8*)"Div.");
		LCD_moveCursor(1, 0);
		LCD_displayString((u8*)"is: ");
		LCD_displayNumber(copy_u8Result, 3);
		_delay_ms(2000);
		break;
		case 'B':
		LCD_displayString((u8*)"Mul.");
		LCD_moveCursor(1, 0);
		LCD_displayString((u8*)"is: ");
		LCD_displayNumber(copy_u8Result, 3);
		_delay_ms(2000);
		break;
		case 'C':
		LCD_displayString((u8*)"Diff.");
		LCD_moveCursor(1, 0);
		LCD_displayString((u8*)"is: ");
		LCD_displayNumber(copy_u8Result, 3);
		_delay_ms(2000);
		break;
		case 'D':
		LCD_displayString((u8*)"Sum");
		LCD_moveCursor(1, 0);
		LCD_displayString((u8*)"is: ");
		LCD_displayNumber(copy_u8Result, 3);
		_delay_ms(2000);
		break;
		default:
		LCD_clear();
		LCD_displayString((u8*)"Error. Please");
		LCD_moveCursor(1, 0);
		LCD_displayString((u8*)"Try again!");
		_delay_ms(2000);
		break;
	}
}

