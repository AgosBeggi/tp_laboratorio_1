/*
 * OperacionesMatematicas.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

#include <stdio.h>
#include <stdlib.h>

#include "Validaciones.h"

/// \fn float Sumar(float, float)
/// \brief Pide dos flotantes, los suma y devuelve el resultado.
/// \param num1
/// \param num2
/// \return
float Sumar(float num1, float num2);

/// \fn float Restar(float, float)
/// \brief Pide dos flotantes, los resta y devuelve el resultado.
/// \param num1
/// \param num2
/// \return
float Restar(float num1, float num2);

/// \fn float Multiplicar(float, float)
/// \brief Pide dos flotantes, los multiplica y devuelve el resultado.
/// \param num1
/// \param num2
/// \return
float Multiplicar(float num1, float num2);

/// \fn int Dividir(float*, float, float)
/// \brief Pide dos flotantes y una dirección de memoria. Llama a otra función
/// para verificar que sea distinto de cero, si es así devuelve true, realiza la operación,
/// y guarda en la dirección de memoria solicitada el resultado.
/// \param punteroResultado
/// \param num1
/// \param num2
/// \return
int Dividir(float *punteroResultado, float num1, float num2);

/// \fn int Factorear(int*, float)
/// \brief Pide un flotante y una dirección de memoria. Llamas a otra funciones
/// para verificar si el numero es negativo o flotante. Corrobora que el numero
/// efectivamente sea entero positivo y devuelve true, realiza la operación,
/// y guarda en la dirección de memoria solicitada el resultado.
/// \param punteroResultado
/// \param num
/// \return
int Factorear(int *punteroResultado, float num);

#endif /* OPERACIONESMATEMATICAS_H_ */
