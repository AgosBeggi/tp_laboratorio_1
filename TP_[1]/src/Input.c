/*
 * Input.c
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#include "Input.h"

int GetInt(char message[], int* number){

	int retorno = -1;//FALSE
	char aux[SIZE];
	int num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(ValidateInt(aux) == 0){
		num = atoi(aux);
		*number = num;
		retorno = 0;//TRUE
	}
	return retorno;
}

int GetFloat(char message[], float* number){

	int retorno = -1;//FALSE
	char aux[SIZE];
	float num;

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(ValidateFloat(aux) == 0){
		num = atof(aux);
		*number = num;
		retorno = 0;//TRUE
	}
	return retorno;
}

int GetChar(char message[], char* character){

	char aux;
	int retorno = -1;//FALSE

	printf("%s", message);
	fflush(stdin);
	scanf("%c", &aux);

	if(ValidateChar(aux) == 0){
		*character = aux;
		retorno = 0;//TRUE
	}
	return retorno;
}

int GetString(char message[], char string[]){

	char aux[SIZE];
	int retorno = -1;//FALSE

	printf("%s", message);
	fflush(stdin);
	scanf("%s", aux);

	if(ValidateString(aux) == 0){
		strcpy(string, aux);
		retorno = 0;//TRUE
	}
	return retorno;
}

