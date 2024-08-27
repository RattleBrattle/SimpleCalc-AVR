/*
 * Simple Calculator  - AVR.c
 *
 * Created: 8/27/2024 11:29:55 AM
 * Author : Basel Mohamed Mostafa Sayed
 * Description: This program is a simple calculator program that accepts decimal numbers as input not just integer numbers
 * And displays them on a 16x2 LCD screen using the keypad interface.
 */

#define F_CPU 16000000UL

/* UTILS Libraries */
#include "UTILS/STD_TYPES.h"

#include "UTILS/Bit_operation.h"

/* MCAL Layer */
#include "ATmega32_DIO/DIO_PROGRAM.h"

#include <util/delay.h>

/* HAL Layer */
#include "../../../LCD_DRIVER/LCD_DRIVER/LCD_PROGRAM.h"

#include "../../../KEYPAD4x4_DRIVER/KEYPAD4x4_DRIVER/KEYPAD4X4_PROGRAM.h"

#include "MAIN_FUNC.h"

int main(void) {
   // Initializing the LCD and the keypad
   LCD_init();
   KEYPAD_init();

   // Defining variables for the keypad
   u8 operation;
   f32 firstOperand = 0;
   f32 secondOperand = 0;
   f32 sum = 0, diff = 0, mul = 0, div = 0;

   while (1) {
      // Initializing the calculator startup screen
      CALC_init();

      // Calling the function to wait for user input operation and store it in an appropriate variable.
      operation = CALC_getOperation();

      switch (operation) {
      case 'A':
         LCD_clear();
         LCD_displayString((u8 * )
            "Enter First");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the first operand
         firstOperand = CALC_getNumberFromKeypad();

         LCD_clear();
         LCD_displayString((u8 * )
            "Enter Second");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the second operand
         secondOperand = CALC_getNumberFromKeypad();

         // Calculate the Division result
         div = firstOperand / secondOperand;

         // Function to display the result
         CALC_displayResult(div, operation);

         break;
      case 'B':
         LCD_clear();
         LCD_displayString((u8 * )
            "Enter First");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the first operand
         firstOperand = CALC_getNumberFromKeypad();

         LCD_clear();
         LCD_displayString((u8 * )
            "Enter Second");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the second operand
         secondOperand = CALC_getNumberFromKeypad();

         // Calculate the multiplication
         mul = firstOperand * secondOperand;

         // Function to display the result
         CALC_displayResult(mul, operation);

         break;
      case 'C':
         LCD_clear();
         LCD_displayString((u8 * )
            "Enter First");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the first operand
         firstOperand = CALC_getNumberFromKeypad();

         LCD_clear();
         LCD_displayString((u8 * )
            "Enter Second");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the second operand
         secondOperand = CALC_getNumberFromKeypad();

         // Calculate the Subtraction
         diff = firstOperand - secondOperand;

         // Function to display the result
         CALC_displayResult(diff, operation);

         break;
      case 'D':
         LCD_clear();
         LCD_displayString((u8 * )
            "Enter First");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the first operand
         firstOperand = CALC_getNumberFromKeypad();

         LCD_clear();
         LCD_displayString((u8 * )
            "Enter Second");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Number:");
         _delay_ms(300);

         // Capturing the second operand
         secondOperand = CALC_getNumberFromKeypad();

         // Calculate the Addition
         sum = firstOperand + secondOperand;

         // Function to display the result
         CALC_displayResult(sum, operation);

         break;
      default:  /* Error message signaling something is wrong in the code */
         LCD_clear();
         LCD_displayString((u8 * )
            "Error. Please");
         LCD_moveCursor(1, 0);
         LCD_displayString((u8 * )
            "Try again!");
         _delay_ms(2000);
         break;
      }
   }
}