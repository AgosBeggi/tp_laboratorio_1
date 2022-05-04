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
		status_aux.id_status = EMPTY;
		//status_aux.passenger.id = status_aux.id_status;
		strcpy(status_aux.flycode, "0");
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
int findStatusById(Status* status_list, int lenStatus, int id_status){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(status_list !=NULL && lenStatus > 0 && id_status != -1){
		for(int i = 0; i < lenStatus; i++){
			if(status_list[i].id_status == id_status){
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
int addStatus(Status* status_list, int lenStatus, int id_status){
	int retorno = -1;//FALSE
	int index;
	char auxCharCode[10];

	if(status_list !=NULL && lenStatus > 0 && id_status != -1){
		index = findStatusEmpty(status_list, lenStatus);

		for(int i = 0; i < lenStatus; i++){
			if(i == index){
				auxCharCode[0] = '1' + (rand() % 10);
				auxCharCode[1] = 'A' + (rand() % 26);
				auxCharCode[2] = '1' + (rand() % 11);
				auxCharCode[3] = 'A' + (rand() % 26);
				auxCharCode[4] = 'A' + (rand() % 26);

				status_list->id_status = id_status;
				strncpy(status_list[i].flycode, auxCharCode, sizeof(status_list[i].flycode));
				status_list[i].statusFlight = ACTIVE;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//MODIFICAR
int changeStatus(Status* status_list, int lenStatus, int id_status, int statusFlight){

	int retorno = -1;//FALSE
	int index;

	if(status_list !=NULL && lenStatus > 0 && id_status != -1){
		index = findStatusById(status_list, lenStatus, id_status);
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
			printf("%d \t%s \tACTIVO\n", status.id_status, status.flycode);
			break;
		case 2:
			printf("%d \t%s \tDEMORADO\n", status.id_status, status.flycode);
			break;
		case 3:
			printf("%d \t%s \tREPROGRAMADO\n", status.id_status, status.flycode);
			break;
		case 4:
			printf("%d \t%s \tCANCELADO\n", status.id_status, status.flycode);
			break;
		}
		retorno = 0;//TRUE
	}
	return retorno;
}

//SUPRIMIR
int deleteStatus(Status* status_list, int lenStatus, int id_status){

	int retorno = -1;//FALSE
	int index;

	if(status_list !=NULL && lenStatus > 0 && id_status != -1){
		index = findStatusById(status_list, lenStatus, id_status);
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
