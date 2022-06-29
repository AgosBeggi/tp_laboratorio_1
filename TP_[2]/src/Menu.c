/*
 * Menu.c
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */


#include "Menu.h"

//INICIALIZACIÓN
int idMenu(){

	static int id = 0;
	id++;
	return  id;
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
	int control = 0;
	int i = 0;
	int j = 0;
	char name[10][51]={"ANTONIO", "MARIA", "JOSE", "CARMEN", "FRANCISCO", "JOSEFA", "JUAN", "ISABEL", "MANUEL", "DOLORES"};
	char lastName[10][51]={"GARCIA", "MARTINEZ", "SANCHEZ", "GONZALEZ", "GOMEZ", "PEREZ", "CORREA", "NAVARRO", "DIAZ", "HERNANDEZ"};
	float price[10]={95560.0, 75200.0, 67103.0, 55460.0, 95056.0, 40926.0, 55046.0, 75200.0, 67103.0, 49026.0};
	char flycode[10][10]={"1Z2AG", "9X6BZ", "7M5CB", "4J1DB", "2R4ET", "1Y2AT", "1W6BB", "8L5CP", "5K1DA", "3Q4EH"};
	int typePassenger[10]={1,2,3,4,1,2,3,4,2,3};
	int statePassenger[10]={1,2,3,4,1,2,3,4,2,3};

	if(list != NULL && len > 0 && status_list !=NULL && lenStatus > 0){
		for(; control < 10; control++){
			id = idMenu();
			for(; i < len; i++){
				addPassenger(list, len, id, name[j], lastName[j], price[j], typePassenger[j], flycode[j], statePassenger[j], status_list, lenStatus);
				break;
			}
			j++;
		}
	}
		retorno = 0;//TRUE

	return retorno;
}

void generateCodeMenu(char flycode[]){

	char auxCharCode[10];

	auxCharCode[0] = '1' + (rand() % 10);
	auxCharCode[1] = 'A' + (rand() % 26);
	auxCharCode[2] = '1' + (rand() % 10);
	auxCharCode[3] = 'A' + (rand() % 26);
	auxCharCode[4] = 'A' + (rand() % 26);

	printf("CODIGO: %s\n", auxCharCode);

	strncpy(flycode, auxCharCode, 10);
}

//AGREGAR
int singUpMenu(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger,
		char flycode[], int status, Status* status_list, int lenStatus){

	int retorno = -1;

	if(list != NULL && len > 0 && id != -1 && name !=NULL && lastName !=NULL && price != EMPTY
			&& typePassenger != EMPTY && flycode != NULL && status_list != NULL && lenStatus > 0){

		if(addPassenger(list, len, id, name, lastName, price, typePassenger, flycode, status, status_list, lenStatus) == 0){
			retorno = 0;
		}
	}
	return retorno;
}

//SUPRIMIR
int deleteMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus){
	int retorno = -1;
	char flycode[10];

	if(list != NULL && len > 0 && id != -1 && status_list != NULL && lenStatus > 0){
		if(removePassenger(list, len, id) == 0 &&deleteStatus(status_list, lenStatus, flycode) == 0){
			retorno = 0;
		}
	}

	return retorno;
}

//MODIFICAR
int modificationsMenu(Passenger* list, int len, int id, int option, char message[], Status* status_list, int lenStatus, char messageError[]){

	int retorno = -1;
	char name[SIZE];
	char lastName[SIZE];
	float price;
	int typePassenger;
	int statusFlight;

	if(list != NULL && len > 0 && id != -1 && option != -1 && message != NULL && status_list != NULL && lenStatus > 0 && messageError != NULL){
		switch(option){
			case 1:
				while(getString(message, lastName) != 0){
					printf("%s\n", messageError);
				}
				if(modifyPassengerName(list, len, id, name) == 0){
					retorno = 0;
				}
				break;
			case 2:
				while(getString(message, lastName) != 0){
					printf("%s\n", messageError);
				}
				if(modifyPassengerLastName(list, len, id, lastName) == 0){
					retorno = 0;
				}
				break;
			case 3:
				do{
					getFloat(message, &price);
					if(price <= 0){
						printf("%s\n", messageError);
					}
				}while(price <= 0);
				if(modifyPassengerPrice(list, len, id, price) == 0){
					retorno = 0;
				}
				break;
			case 4:
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
			case 5:
				do{
					printf(message);
					getInt("", &statusFlight);
					if(statusFlight < 1 || statusFlight > 4){
						printf("%s\n", messageError);
					}
				}while(statusFlight != 1 && statusFlight != 2 && statusFlight != 3 && statusFlight != 4);

				int index = findPassengerById(list, len, id);
				if(changeStatus(status_list, lenStatus, statusFlight, list[index].flycode) == 0){
					retorno = 0;
				}
				break;
		}
	}
	return retorno;
}

//REPORTAR
int reportsMenu(Passenger* list, int len, Status* status_list, int lenStatus, int criterio){
	int retorno = -1;

	if(list != NULL && len > 0 && status_list != NULL && lenStatus > 0){
		switch(criterio){
		case 1:
			printPassenger(list, len, status_list, lenStatus);
			break;
		case 3:
			printActivePassengers(list, len, status_list, lenStatus);
			break;
		}
		retorno = 0;
	}
	return retorno;
}

//ORDENAR
int orderMenu(Passenger* list, int len, Status* status_list, int lenStatus, int order, int criterio){
	int retorno = -1;

	switch(criterio){
	case 1:
		if(list != NULL && len > 0 && status_list != NULL && lenStatus > 0 && order != -1
			&& sortPassengers(list, len, order, status_list, lenStatus) == 0){
			retorno = 0;
		}
		break;
	case 3:
		if(list != NULL && len > 0 && status_list != NULL && lenStatus > 0 && order != -1
			&& sortPassengers2(list, len, order, status_list, lenStatus) == 0){
			retorno = 0;
		}
		break;

	}
	return retorno;
}

int reportPriceMenu(Passenger* list, int len, Status* status_list, int lenStatus, float* totalPasajes, float* promedioPasajes){

	int contadorPasajesArribaPromedio = 0;
	int contadorPasajeros = 0;
	float totalPrecios = 0;
	float promedio;

	if(list != NULL && len > 0 && status_list != NULL && lenStatus > 0){

		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FULL){
				totalPrecios = totalPrecios + list[i].price;
				contadorPasajeros++;
			}
		}
		promedio = totalPrecios / contadorPasajeros;

		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FULL && list[i].price < promedio){
				contadorPasajesArribaPromedio++;
			}
		}
		if(contadorPasajesArribaPromedio > 0){
			*totalPasajes = totalPrecios;
			*promedioPasajes = promedio;
		}
	}
	return contadorPasajesArribaPromedio;
}

//BUSQUEDA
int findElemenMenu(Passenger* list, int len, int id, char message[], Status* status_list){

	int index = -1;

	if(list !=NULL && len > 0){
		index = findPassengerById(list, len, id);
		if(index != -1){
			puts("Usted eligio: \n\n");
			printf("%s\n", message);
			printPassengers(list[index], status_list[index]);
		}
		else{
			puts("Pasajero no encontrado.\n");
		}
	}
	return index;
}
