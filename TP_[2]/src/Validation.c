/*
 * Validation.c
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#include "Validation.h"

int Its_A_Number_Int(char string[]){

	int i;
	int retorno;

	retorno = 1;

	if(string[0] == '-'){
		i = 1;
	}

	for(; string[i] != '\0'; i++){

		if(string[i] > '9' || string[i] < '0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int Its_A_Number_Float(char string[]){

	int i;
	int retorno;
	int contadorDecimal;

	retorno = 1;
	contadorDecimal = 0;

	if(string[0] == '-'){
		i = 1;
	}

	for(; string[i] != '\0'; i++){

		if(string[i] != '.'){
			contadorDecimal++;
		}

		if(string[i] > '9' || string[i] < '0' || contadorDecimal > 1){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

