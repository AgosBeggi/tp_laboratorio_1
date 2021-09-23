/*
 * Salidas.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */


#ifndef SALIDAS_H_
#define SALIDAS_H_

#include <stdio.h>
#include <stdlib.h>
/// \fn void MostrarResultado(char[], float, float, float)
/// \brief Pide un mensaje, y los elementos a mostrar en el mismo y lo imprime.
/// \param mensaje
/// \param num1
/// \param num2
/// \param respuesta
void MostrarResultado(char mensaje[], float num1, float num2, float respuesta);

/// \fn void MostrarFactoreo(char[], float, int)
/// \brief Pide un mensaje, y los elementos a mostrar en el mismo y lo imprime.
/// \param mensaje
/// \param numero
/// \param respuesta
void MostrarFactoreo(char mensaje[], float numero, int respuesta);

/// \fn void MensajeError(char[])
/// \brief Pide un mensaje y lo imprime.
/// \param mensaje
void MensajeError(char mensaje[]);

#endif /* SALIDAS_H_ */
