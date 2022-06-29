/*
 * Validation.c
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 *  El programa permite que en nombre y apellido se puedan
 *  ingresar numeros y el precio acepta
 *	numeros negativos.
 */

#include "Validation.h"
#include <stdio.h>

int isInt(char number[]){

	int retorno = 0;
	int len = strlen(number);

	if(isdigit(number[0]) || (number[0] == '-' && len > 0)){
		for (int i = 1; i < len; i++){
			if(!isdigit(number[i])){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int isFloat(char number[]){

	int retorno = 0;
	int len = strlen(number);
	int count;

	if(isdigit(number[0]) || (number[0] == '-' && len > 0)){
		for (int i = 1; i < len; i++){
			if(!isdigit(number[i])){
				if(number[i] == '.'){
					count++;
					if(count > 1){
						retorno = -1;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int isChar(char character){

	int retorno = 0;

	if (!(isalpha(character))) {
		retorno = -1;
	  }
	return retorno;
}

int isString(char chains[]){

	int retorno = 0;

	for (int i = 0; i < strlen(chains); i++){
		chains[i] = toupper(chains[i]);
		if(!isalpha(chains[i]) && chains[i] != 'ñ'){
			retorno = -1;
		}
	}
	return retorno;
}

int isStringAlnum(char chains[]){

	int retorno = 0;

	for (int i = 0; i < strlen(chains); i++){
		chains[i] = toupper(chains[i]);
		if(!isalnum(chains[i]) && chains[i] != 'ñ'){
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int isStringAlnumCode(char chains[]){

	int retorno = 0;
	int len = strlen(chains);

	if(len == 6){
		for (int i = 0; i < len; i++){
		chains[i] = toupper(chains[i]);
			if(!isalnum(chains[i]) && chains[i] != 'ñ'){
				retorno = -1;
				break;
			}
		}
	}else{
		retorno = -1;
	}


	return retorno;
}


