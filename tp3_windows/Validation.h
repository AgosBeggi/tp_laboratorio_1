/*
 * Validation.h
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// \fn int Its_A_Number_Int(char[])
/// \brief It receives as a parameter a string of characters, the
/// go through and make sure that each character entered corresponds
/// to a number.
/// \param string
/// \return Returns a boolean value, 1 for true and 0 for false.
int Its_A_Number_Int(char string[]);

/// \fn float Its_A_Number_Float(char[])
/// \brief It receives as a parameter a string of characters, the
/// go through and make sure that each character entered corresponds
/// to a number.
/// \param string
/// \return Returns a boolean value, 1 for true and 0 for false.
int Its_A_Number_Float(char string[]);

/// \fn int Is_It_Char(char[])
/// \brief It receives as a parameter a string of characters, the
///checks and makes sure that each character entered is not a number.
/// \param string
/// \return Returns a boolean value, 1 for true and 0 for false.
int Is_It_Char(char string[]);

#endif /* VALIDATION_H_ */
