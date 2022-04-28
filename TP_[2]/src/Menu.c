/*
 * Menu.c
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */


#include "Menu.h"

int startMenu(Passenger* list, int len, Status* status_list, int lenStatus){

	int retorno = -1;

	if(initPassengers(list, len) == 0 && initStatus(status_list, lenStatus) == 0){
		retorno = 0;
	}
	return retorno;
}

int singUpMenu(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[]){

	int retorno = -1;

	if(addPassenger(list, len, id, name, lastName, price, typePassenger, flycode) == 0){
		retorno = 0;
	}
	return retorno;
}

int deleteMenu(Passenger* list, int len, int id){
	int retorno = -1;

	if(removePassenger(list, len, id) == 0){
		retorno = 0;
	}
	return retorno;
}

int MenuModifications(Passenger* list, int len, int id, int option, char message[]){

	int retorno = -1;
	char name[SIZE];
	char lastName[SIZE];
	float price;
	char flycode[10];
	int typePassenger;

	switch(option){
		case 1:
			if(getString(message, name) == 0 && modifyPassengerName(list, len, id, name) == 0){
				retorno = 0;
			}
			break;
		case 2:
			if(getString(message, lastName) == 0){
				if(modifyPassengerLastName(list, len, id, lastName) == 0){
					retorno = 0;
				}
			}
			break;
		case 3:
			if(getFloat(message, &price) == 0){
				if(modifyPassengerPrice(list, len, id, price) == 0){
					retorno = 0;
				}
			}
			break;
		case 4:
			if(getStringAlnum(message, flycode) == 0){
				if(modifyPassengerFlycode(list, len, id, flycode) == 0){
					retorno = 0;
				}
			}
			break;
		case 5:
			do{
				printf(message);
				getInt("", &typePassenger);
				if(typePassenger < 1 || typePassenger > 4){
					puts("Opción incorrecta, vuelta a intentarlo.\n");
				}
			}while(typePassenger != 1 && typePassenger != 2 && typePassenger != 3 && typePassenger != 4);

			if(modifyPassengerTypePassenger(list, len, id, typePassenger) == 0){
				retorno = 0;
			}
			break;
		default:
			puts("Opción incorrecta, vuelta a intentarlo.\n");
			break;
	}

	return retorno;
}

int reportsMenu(Passenger* list, int len){

	int retorno = -1;

	if(printPassenger(list, len) == 0){
		retorno = 0;
	}
	return retorno;
}

int orderMenu(Passenger* list, int len){
	int retorno = -1;
		int orden;

		puts("¿Cómo desea ordenar la lista?\n");
		puts("1. DESCENDENTE");
		puts("2. ASCENDENTE");
		puts("------------------------------------------------------------------\n");

		getInt("", &orden);
		while(orden != 1 && orden != 2){
			getInt("Opción incorrecta, vuelta a intentarlo.", &orden);
		}

		if(sortPassengers(list, len, orden) == 0){
			retorno = 0;
			orden = 0;
		}

		return retorno;
}

int idMenu(int id){

	int contador = 1;

	contador+=id;

	return contador;
}
