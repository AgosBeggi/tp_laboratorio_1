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

	/*if(string[0] == '-'){
		i = 1;
	}*/

	for(i = 0; string[i] != '\0'; i++){

		if(string[i] > '9' || string[i] < '0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int Its_A_Number_Float(char string[]){

	int i;
	float retorno;
	int contadorDecimal;

	retorno = 1;
	contadorDecimal = 0;

	if(string[0] == '-'){
		i = 1;
	}

	for(i = 1; string[i] != '\0'; i++){

		if(string[i] == '.'){
			contadorDecimal++;
		}

		if(string[i] > '9' || string[i] < '0' || contadorDecimal > 1){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int Is_It_Char(char string[]){

	int i;
	int retorno;

	retorno = 0;

	for(i = 0; i < strlen(string); i++){
		if(string != NULL && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')){
		retorno = 1;
		break;
		}
	}

	return retorno;
}

