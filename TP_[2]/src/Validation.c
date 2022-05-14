/*
 * Validation.c
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#include "Validation.h"

int isInt(char number[]){//OK

	int retorno = 0;//TRUE

	for (int i = 0; i < strlen(number); i++){
		if(!isdigit(number[i])){
			retorno = -1;//FALSE
			break;
		}
	}
	return retorno;
}

int isFloat(char number[]){//OK

	int retorno = 0;//TRUE

	for (int i = 0; i < strlen(number); i++){
		if(!isdigit(number[i]) && number[i] != '.'){
			retorno = -1;//FALSE
			break;
		}
	}
	return retorno;
}

int isChar(char character){//OK

	int retorno = 0;//TRUE

	if (!(isalpha(character))) {
		retorno = -1;//FALSE
	  }
	return retorno;
}

int isString(char chains[]){//OK

	int retorno = -1;//TRUE

	for (int i = 0; i < strlen(chains); i++){
		if(isalpha(chains[i]) && chains[i] != '�'){
			chains[i] = toupper(chains[i]);
			retorno = 0;//FALSE
			//break;
		}
	}
	return retorno;
}

int isStringAlnum(char chains[]){//OK

	int retorno = 0;//TRUE

	for (int i = 0; i < strlen(chains); i++){
		if(!isalnum(chains[i]) && chains[i] != '�'){
			retorno = -1;//FALSE
			break;
		}
	}
	return retorno;
}



