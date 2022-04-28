/*
 * ArrayStatus.c
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#include "ArrayStatus.h"

int initStatus(Status* status_list, int lenStatus){

	int retorno = -1;//FALSE
	Status status_aux;

	strcpy(status_aux.flycode, "0");
	status_aux.statusFlight = EMPTY;

	for(int i = 0; i < lenStatus; i++){
		status_list[i] = status_aux;
		if(status_list[i].statusFlight == EMPTY){
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int findStatusById(Status* status_list, int lenStatus, char flycode[]){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	for(int i = 0; i < lenStatus; i++){
		if(strcmp(status_list[i].flycode, flycode)){
			index = i;//RETURNS POSITION OF ID FOUND
			break;
		}
	}
	return index;
}
int findStatusEmpty(Status* status_list, int lenStatus){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	for(int i = 0; i < lenStatus; i++){
		if(status_list[i].statusFlight == EMPTY){
			index = i;//RETURNS FIRST POSITION EMPTY
			break;
		}
	}
	return index;
}

int addStatus(Status* status_list, int lenStatus, char flycode[]){
	int retorno = -1;//FALSE
	int index;

	index = findStatusEmpty(status_list, lenStatus);

	for(int i = 0; i < lenStatus; i++){
		if(i == index){
			strncpy(status_list[i].flycode, flycode, sizeof(status_list[i].flycode));
			status_list->statusFlight = ACTIVE;
			retorno = 0;//TRUE
		}
	}
	return retorno;
}

int printStatus(Status* status_list, int lenStatus){//OK

	int retorno = -1;//FALSE

	for(int i = 0; i < lenStatus; i++){
		if(status_list[i].statusFlight != EMPTY){
			print_A_Status(status_list[i]);
			retorno = 0;//TRUE
		}
	}

 return retorno;
}

void print_A_Status(Status status){//OK

	printf("%c \t%-2d \n", status.flycode, status.statusFlight);

}
