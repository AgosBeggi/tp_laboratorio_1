/*
 * Validaciones.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */

int EsFlotante(float flotante) {

	int entero;
	int retorno;

	entero = flotante;
	if (flotante - entero == 0) {
		retorno = 0;
	} else {
		retorno = 1;
	}
	return retorno;
}

int EsNegativo(float flotante) {

	int retorno;

	if (!(flotante < 0)) {
		retorno = 0;
	} else {
		retorno = 1;
	}
	return retorno;
}

int EsCero(float flotante) {
	int retorno;

	if (!(flotante == 0)) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}
