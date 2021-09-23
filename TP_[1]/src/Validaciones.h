/*
 * Validaciones.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>

/// \fn int EsFlotante(float)
/// \brief Pide un flotante, que es el tipo de
/// numero ingresado por default, verifica si realmente es un flotante.
/// Si es así retorna 0, en caso de ser entero retorna 1.
/// \param flotante
/// \return
int EsFlotante(float flotante);

/// \fn int EsNegativo(float)
/// \brief Pide un flotante, verifica si es menor a cero.
/// Si es así retorna 0, en caso contrario retorna 1.
/// \param flotante
/// \return
int EsNegativo(float flotante);

/// \fn int EsCero(float)
/// \brief Pide un flotante, verifica si es igual a cero.
/// Si es así retorna 1, en caso contrario retorna 0.
/// \param flotante
/// \return
int EsCero(float flotante);

#endif /* VALIDACIONES_H_ */
