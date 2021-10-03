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
/// \brief Recibe como parámetro una cadena de caracteres, la
/// recorre y se fija que cada caracter ingresado corresponda
/// a un numero.
/// \param string
/// \return Retorna un valor booleano, 0 para false y 1 para true.
int Its_A_Number_Int(char string[]);

/// \fn int Its_A_Number_Float(char[])
/// \brief Recibe como parámetro una cadena de caracteres, la
/// recorre y se fija que cada caracter ingresado corresponda
/// a un numero.
/// \param string
/// \return Retorna un valor booleano, 0 para false y 1 para true.
int Its_A_Number_Float(char string[]);

#endif /* VALIDATION_H_ */
