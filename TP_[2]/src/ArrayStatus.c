/*
 * ArrayStatus.c
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#include "ArrayStatus.h"

//INICIALIZACIÓN
int initStatus(Status* status_list, int lenStatus){

	int retorno = -1;//FALSE
	Status status_aux;

	if(status_list !=NULL && lenStatus > 0){
		status_aux.statusFlight = EMPTY;
		for(int i = 0; i < lenStatus; i++){
			status_list[i] = status_aux;
			if(status_list[i].statusFlight == EMPTY){
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//BUSQUEDA
int findStatusByCode(Status* status_list, int lenStatus, char flycode[]){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(status_list !=NULL && lenStatus > 0 && flycode != NULL){
		for(int i = 0; i < lenStatus; i++){

			if(strcmp(status_list[i].flycode, flycode) == 0){
				index = i;//RETURNS POSITION OF ID FOUND
				break;
			}
		}
	}
	return index;
}

int findStatusEmpty(Status* status_list, int lenStatus){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(status_list !=NULL && lenStatus > 0){
		for(int i = 0; i < lenStatus; i++){
			if(status_list[i].statusFlight == EMPTY){
				index = i;//RETURNS FIRST POSITION EMPTY
				break;
			}
		}
	}
	return index;
}

//AGREGAR
int addStatus(Status* status_list, int lenStatus, char flycode[]){
	int retorno = -1;//FALSE
	int index;

	if(status_list != NULL && lenStatus > 0 && flycode != NULL){
		index = findStatusEmpty(status_list, lenStatus);
		for(int i = 0; i < lenStatus; i++){
			if(i == index){
				strncpy(status_list[i].flycode, flycode, sizeof(status_list[i].flycode));
				status_list[i].statusFlight = ACTIVE;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//MODIFICAR
int changeStatus(Status* status_list, int lenStatus, int statusFlight, char flycode[]){

	int retorno = -1;//FALSE
	int index;

	if(status_list !=NULL && lenStatus > 0 && statusFlight != -1 && flycode != NULL){
		index = findStatusByCode(status_list, lenStatus, flycode);
		for(int i = 0; i < lenStatus; i++){
			if(i == index){
				status_list[i].statusFlight = statusFlight;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

//REPORTAR
int printStatusList(Status* status_list, int lenStatus){//OK

	int retorno = -1;//FALSE

	if(status_list !=NULL && lenStatus > 0){
		for(int i = 0; i < lenStatus; i++){
			if(status_list[i].statusFlight != EMPTY && printStatus(status_list[i]) == 0){
				retorno = 0;//TRUE
			}
		}
	}
 return retorno;
}

int printStatus(Status status){//OK

	int retorno = -1;//FALSE

	if(status.statusFlight != EMPTY){

		switch(status.statusFlight){
		case 1:
			printf("%s \tACTIVO\n", status.flycode);
			break;
		case 2:
			printf("%s \tDEMORADO\n", status.flycode);
			break;
		case 3:
			printf("%s \tREPROGRAMADO\n", status.flycode);
			break;
		case 4:
			printf("%s \tCANCELADO\n", status.flycode);
			break;
		}
		retorno = 0;//TRUE
	}
	return retorno;
}

//SUPRIMIR
int deleteStatus(Status* status_list, int lenStatus, char flycode[]){

	int retorno = -1;//FALSE
	int index;

	if(status_list !=NULL && lenStatus > 0 && flycode != NULL){
		index = findStatusByCode(status_list, lenStatus, flycode);
		for(int i = 0; i < lenStatus; i++){
			if(i == index){
				status_list[i].statusFlight = CANCELLED;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}
