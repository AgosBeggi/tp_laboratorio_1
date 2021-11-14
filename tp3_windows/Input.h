/*
 * Input.h
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validation.h"

/// \fn int Get_A_Number_Int(char[], int*)
/// \brief Request and display a message to request a number, in
/// addition to saving it in a memory address with a pointer.
/// \param message
/// \param pNumber
/// \return Returns a boolean value, 1 for true and 0 for false.
int Get_A_Number_Int(char message[], int* pNumber);

/// \fn int Get_A_Number_Float(char[], float*)
/// \brief Request and display a message to request a number, in
/// addition to saving it in a memory address with a pointer.
/// \param message
/// \param pNumber
/// \return Returns a boolean value, 1 for true and 0 for false.
int Get_A_Number_Float(char message[], float* pNumber);

/// \fn int InputString(char[], int, char[])
/// \brief Ask for a string of characters, its size and a message.
/// Saves an entered character string.
/// \param cadena
/// \param tamanio
/// \param mensaje
/// \return Returns a boolean value, 1 for true and 0 for false.
int Get_String(char cadena[], int tamanio, char mensaje[]);

#endif /* INPUT_H_ */
