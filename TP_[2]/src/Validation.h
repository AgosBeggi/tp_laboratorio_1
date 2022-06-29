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

/// @fn int isInt(char[])
/// @brief Analyze if the parameter is digit or not.
/// @param number
/// @return Returns 0 for true and -1 for false.
int isInt(char number[]);

/// @fn int isFloat(char[])
/// @brief Analyze if the parameter is a digit
/// or not, and if it has a decimal.
/// @param number
/// @return Returns 0 for true and -1 for false.
int isFloat(char number[]);

/// @fn int isChar(char)
/// @brief Analyze if the parameter is alphabetic or not.
/// @param character
/// @return Returns 0 for true and -1 for false.
int isChar(char character);

/// @fn int isString(char[])
/// @brief Analyze if the parameter is alphabetic
/// and/or letter �, or not.
/// @param string
/// @return Returns 0 for true and -1 for false.
int isString(char string[]);

/// \fn int isStringAlnum(char[])
/// \brief Analyze if the parameter is alphanumeric
/// and/or letter �, or not.
/// \param chains
/// \return Returns 0 for true and -1 for false.
int isStringAlnum(char chains[]);

int isStringAlnumCode(char chains[]);

#endif /* VALIDATION_H_ */
