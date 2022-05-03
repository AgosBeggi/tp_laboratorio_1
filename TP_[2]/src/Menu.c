/*
 * Menu.c
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */


#include "Menu.h"

//INICIALIZACIÓN
int idMenu(int* id, Passenger* list, int len){

	int retorno = -1;//FALSE
	int index;

	index = findPassengerEmpty(list, len);

	for(int i = 0; i < len; i++){
		if(i == index){
			list[i].id = index +1;
			*id = list[i].id;
			retorno = 0;//TRUE
			break;
		}
	}
	return retorno;
}

int startMenu(Passenger* list, int len, Status* status_list, int lenStatus){

	int retorno = -1;

	if(list != NULL && len > 0 && status_list !=NULL && lenStatus > 0){
		if(initPassengers(list, len) == 0 && initStatus(status_list, lenStatus) == 0){
			retorno = 0;
		}
	}
	return retorno;
}

int hardcodeListMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus){

	int retorno = -1;//FALSE
	int indexP;
	int indexS;
	int control;
	int j = 0;
	char name[10][51]={"ANTONIO", "MARIA", "JOSE", "CARMEN", "FRANCISCO", "JOSEFA", "JUAN", "ISABEL", "MANUEL", "DOLORES"};
	char lastName[10][51]={"GARCIA", "MARTINEZ", "SANCHEZ", "GONZALEZ", "GOMEZ", "PEREZ", "JUAN", "NAVARRO", "DIAZ", "HERNANDEZ"};
	float price[10]={95560.0, 75200.0, 67103.0, 55460.0, 95056.0, 40926.0, 55046.0, 75200.0, 67103.0, 49026.0};
	char flycode[10][10]={"A1Z26", "B9X62", "C7M58", "D4J13", "E2R47", "A1Y27", "B1W63", "C8L59", "D5K14", "E3Q48"};
	int typePassenger[10]={1,2,3,4,1,2,3,4,2,3};

	if(list != NULL && len > 0 && status_list !=NULL && lenStatus > 0){

		indexP = findPassengerEmpty(list, len);
		indexS = findStatusEmpty(status_list, lenStatus);
		control = id + 9;

		for(int i = 0; i < len; i++){
			indexP = findPassengerEmpty(list, len);
			indexS = findStatusEmpty(status_list, lenStatus);
			if(i == indexP && i == indexS){
				list[i].id = id;
				strcpy(list[i].name, name[j]);
				strcpy(list[i].lastName, lastName[j]);
				list[i].price = price[j];
				strcpy(list[i].flycode.flycode, flycode[j]);
				list[i].typePassenger = typePassenger[j];
				status_list[i].id_status = id;
				strcpy(status_list[i].flycode, flycode[j]);
				status_list[i].statusFlight = ACTIVE;
				list[i].isEmpty = FULL;
			}
			if(id == control){
				retorno = 0;//TRUE
				break;
			}
			id++;
			j++;
		}
	}
	return retorno;
}

//AGREGAR
int singUpMenu(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[], Status* status_list, int lenStatus){

	int retorno = -1;

	if(list != NULL && len > 0 && id != -1 && name !=NULL && lastName !=NULL && price != EMPTY
			&& typePassenger != EMPTY && flycode != NULL  && status_list != NULL && lenStatus > 0){

		if(addPassenger(list, len, id, name, lastName, price, typePassenger, flycode) == 0 && addStatus(status_list, lenStatus, flycode, id) == 0){
			retorno = 0;
		}
	}
	return retorno;
}

//SUPRIMIR
int deleteMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus){
	int retorno = -1;

	if(list != NULL && len > 0 && id != -1 && status_list != NULL && lenStatus > 0){
		if(removePassenger(list, len, id) == 0 &&deleteStatus(status_list, lenStatus, id) == 0){
			retorno = 0;
		}
	}

	return retorno;
}

//MODIFICAR
int MenuModifications(Passenger* list, int len, int id, int option, char message[], Status* status_list, int lenStatus, char messageError[]){

	int retorno = -1;
	char name[SIZE];
	char lastName[SIZE];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;

	if(list != NULL && len > 0 && id != -1 && option != -1 && message != NULL && status_list != NULL && lenStatus > 0 && messageError != NULL){
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
						printf("%s\n", messageError);
					}
				}while(typePassenger != 1 && typePassenger != 2 && typePassenger != 3 && typePassenger != 4);

				if(modifyTypePassenger(list, len, id, typePassenger) == 0){
					retorno = 0;
				}
				break;
			case 6:
				do{
					printf(message);
					getInt("", &statusFlight);
					if(statusFlight < 1 || statusFlight > 4){
						printf("%s\n", messageError);
					}
				}while(statusFlight != 1 && statusFlight != 2 && statusFlight != 3 && statusFlight != 4);

				if(changeStatus(status_list, lenStatus, id, statusFlight) == 0){
					retorno = 0;
				}
				break;
		}
	}
	return retorno;
}

//REPORTAR
int reportsMenu(Passenger* list, int len, Status* status_list, int lenStatus){

	int retorno = -1;

	if(list != NULL && len > 0 && status_list != NULL && lenStatus > 0){
		if(printPassenger(list, len) == 0 && printStatusList(status_list, lenStatus) == 0){
			retorno = 0;
		}
	}
	return retorno;
}

//ORDENAR
int orderMenu(Passenger* list, int len, int order){
	int retorno = -1;

		if(sortPassengers(list, len, order) == 0){
			retorno = 0;
			order = 0;
		}

		return retorno;
}


