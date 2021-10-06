/*
 * Input.c
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#include "Input.h"

int Get_A_Number_Int(char message[], int* pNumber){

	int retorno;
	char string[40];
	int aux;

	retorno = 0;

	printf("%s", message);
	fflush(stdin);
	fgets(string, 40, stdin);
	string[strlen(string)-1] = '\0';

	aux = Its_A_Number_Int(string);

	if(aux == 1){
		aux = atoi(string);
		*pNumber = aux;
		retorno = 1;
	}

	return retorno;
}

int Get_A_Number_Float(char message[], float* pNumber){

	int retorno;
	char string[40];
	int aux;
	float aux2;

	retorno = 0;

	printf("%s", message);
	fflush(stdin);
	fgets(string, 40, stdin);
	string[strlen(string)-1] = '\0';

	aux = Its_A_Number_Float(string);

	if(aux == 1){
		aux2 = atof(string);
		*pNumber = aux2;
		retorno = 1;
	}

	return retorno;
}

int Get_String(char cadena[], int tamanio, char mensaje[]){

	int retorno;
	char string[51];

	retorno = 0;

	printf("%s", mensaje);
	fflush(stdin);
	fgets(string, 40, stdin);
	string[strlen(string)-1] = '\0';

	if(string != NULL){
		strncpy(cadena, string, tamanio);
		retorno = 1;
	}

	return retorno;
}
