/*
 * Ingresos.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */

float IngresoNumero(char mensaje[]) {

	float flotante;

	printf("%s", mensaje);
	scanf("%f", &flotante);

	return flotante;
}

