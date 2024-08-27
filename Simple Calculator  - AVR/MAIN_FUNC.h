/*
 * MAIN_FUNC.h
 *
 *  Created on: Aug 25, 2024
 *      Author: Basel Mohamed Mostafa Sayed
 *      Description: This is a header file that contains all the API prototypes for the functions
 *      used in the Main source file application.
 */

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

/* MAIN function prototypes */

// This function initializes the calculator program
void CALC_init(void);

// This function waits for the user to input a number on the keypad
f32 CALC_getNumberFromKeypad(void);

// This function waits for user input on the which operation to perform on the calculator
u8 CALC_getOperation(void);

// Function that simply displays the result on the LCD screen
void CALC_displayResult(f32 copy_u8Result, u8 copy_u8Operation);

#endif /* MAIN_FUNC_H_ */
