/*
 * Validation.h
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <ctype.h>
#include <string.h>

/// @fn int ValidateInt(char[])
/// @brief Analyze if the parameter is digit or not.
/// @param number
/// @return Returns 0 for true and -1 for false.
int ValidateInt(char number[]);

/// @fn int ValidateFloat(char[])
/// @brief Analyze if the parameter is a digit
/// or not, and if it has a decimal.
/// @param number
/// @return Returns 0 for true and -1 for false.
int ValidateFloat(char number[]);

/// @fn int ValidateChar(char)
/// @brief Analyze if the parameter is alphabetic or not.
/// @param character
/// @return Returns 0 for true and -1 for false.
int ValidateChar(char character);

/// @fn int ValidateString(char[])
/// @brief Analyze if the parameter is alphabetic
/// and/or letter ñ, or not.
/// @param string
/// @return Returns 0 for true and -1 for false.
int ValidateString(char string[]);

#endif /* VALIDATION_H_ */
