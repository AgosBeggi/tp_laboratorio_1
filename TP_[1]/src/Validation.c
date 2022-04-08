/*
 * Validation.c
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#include "Validation.h"

int ValidateInt(char number[]){//OK

	int retorno = 0;//TRUE

	for (int i = 0; i < strlen(number); i++){
		if(!isdigit(number[i])){
			retorno = -1;//FALSE
			break;
		}
	}
	return retorno;
}

int ValidateFloat(char number[]){//OK

	int retorno = 0;//TRUE

	for (int i = 0; i < strlen(number); i++){
		if(!isdigit(number[i]) && number[i] != '.'){
			retorno = -1;//FALSE
			break;
		}
	}
	return retorno;
}

int ValidateChar(char character){//OK

	int retorno = 0;//TRUE

	if (!(isalpha(character))) {
		retorno = -1;//FALSE
	  }
	return retorno;
}

int ValidateString(char string[]){//OK

	int retorno = 0;//TRUE

	for (int i = 0; i < strlen(string); i++){
		if(!isalpha(string[i]) && string[i] != 'ñ'){
			retorno = -1;//FALSE
			break;
		}
	}
	return retorno;
}


