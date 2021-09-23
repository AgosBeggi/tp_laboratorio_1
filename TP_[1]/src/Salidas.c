/*
 * Salidas.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */

void MostrarResultado(char mensaje[], float num1, float num2, float respuesta){

	printf(mensaje, num1, num2, respuesta);
}

void MostrarFactoreo(char mensaje[], float numero, int respuesta){

	printf(mensaje, numero, respuesta);

}

void MensajeError(char mensaje[]){

	printf("%s", mensaje);

}
