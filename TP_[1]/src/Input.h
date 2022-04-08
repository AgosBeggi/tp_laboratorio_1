/*
 * Input.h
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validation.h"

#define SIZE 51

/// @fn int GetInt(char[], int*)
/// @brief Prints a message, saves a string data type,
/// if the integer validation is ok, converts to int
/// and passes the value of the number to the memory
/// address of the pointer.
/// @param message
/// @param number
/// @return Returns 0 for true and -1 for false.
int GetInt(char message[], int* number);

/// @fn int GetFloat(char[], float*)
/// @brief Prints a message, saves a string data type,
/// if the float validation is ok, converts to float
/// and passes the value of the number to the memory
/// address of the pointer.
/// @param message
/// @param number
/// @return Returns 0 for true and -1 for false.
int GetFloat(char message[], float* number);

/// @fn int GetChar(char[], char*)
/// @brief Print a message, save a char data type,
/// if character validation is ok, copy the value to
/// the pointer's memory address.
/// @param message
/// @param character
/// @return Returns 0 for true and -1 for false.
int GetChar(char message[], char* character);

/// @fn int GetString(char[], char[])
/// @brief Print a message, save a string data type,
/// if string validation is ok, copy the value to
/// the pointer's memory address.
/// @param message
/// @param string
/// @return Returns 0 for true and -1 for false.
int GetString(char message[], char string[]);

#endif /* INPUT_H_ */
