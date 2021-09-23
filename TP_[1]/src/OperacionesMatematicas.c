/*
 * OperacionesMatematicas.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Agostina Beggi
 */

float Sumar(float num1, float num2) {

	float resultado;

	resultado = num1 + num2;

	return resultado;
}

float Restar(float num1, float num2) {

	float resultado;

	resultado = num1 - num2;

	return resultado;
}

float Multiplicar(float num1, float num2) {
	float resultado;

	resultado = num1 * num2;

	return resultado;

}

int Dividir(float *punteroResultado, float num1, float num2) {

	int validarCero;
	float resultado;
	int retorno;

	validarCero = EsCero(num2);
	if (!(validarCero == 0)) {
		resultado = num1 / num2;
		*punteroResultado = resultado;
		retorno = 1;
	} else {
		retorno = 0;

	}

	return retorno;
}

int Factorear(int *punteroResultado, float num) {

	int validarFlotante;
	int flotanteAEntero;
	int validarSigno;
	int retorno;
	int i;
	int acumulador;

	acumulador = 1;

	validarFlotante = EsFlotante(num);
	validarSigno = EsNegativo(num);

	if (validarFlotante == 0 && validarSigno == 0) {
		flotanteAEntero = num;
		for (i = 1; i <= flotanteAEntero; i++) {
			acumulador = acumulador * i;
		}
		*punteroResultado=acumulador;
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}

