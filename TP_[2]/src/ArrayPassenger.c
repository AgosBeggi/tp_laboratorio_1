/*
 * ArrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#include "ArrayPassenger.h"


//INICIALIZACIÓN
int initPassengers(Passenger* list, int len){

	int retorno = -1;//FALSE
	Passenger passenger_aux;

	if(list !=NULL && len > 0){
		passenger_aux.id = EMPTY;
		strcpy(passenger_aux.name, "0");
		strcpy(passenger_aux.lastName, "0");
		passenger_aux.price = EMPTY;
		strcpy(passenger_aux.flycode.flycode, "0");
		passenger_aux.typePassenger = EMPTY;
		passenger_aux.isEmpty = EMPTY;

		for(int i = 0; i < len; i++){
			list[i] = passenger_aux;
			if(list[i].isEmpty == EMPTY){
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//AGREGAR
int addPassenger(Passenger* list, int len, int id, char name[],
		char lastName[], float price, int typePassenger, char flycode[]){
	int retorno = -1;//FALSE
	int index;
	Passenger passenger_aux;

	if(list !=NULL && len > 0 && id != -1 && name != NULL){
		passenger_aux.id = id;
		strncpy(passenger_aux.name, name, sizeof(passenger_aux.name));
		strncpy(passenger_aux.lastName, lastName, sizeof(passenger_aux.lastName));
		passenger_aux.price = price;
		strncpy(passenger_aux.flycode.flycode, flycode, sizeof(passenger_aux.flycode));
		passenger_aux.typePassenger = typePassenger;
		passenger_aux.isEmpty = FULL;

		index = findPassengerEmpty(list, len);

		for(int i = 0; i < len; i++){
			if(i == index){
				list[i] = passenger_aux;
				retorno = 0;//TRUE
			}
		}
	}
	return retorno;
}

//BUSQUEDA
int findPassengerEmpty(Passenger* list, int len){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == EMPTY){
				index = i;//RETURNS FIRST POSITION EMPTY
				break;
			}
		}
	}
	return index;
}

int findPassengerById(Passenger* list, int len,int id){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0 && id != -1){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				index = i;//RETORNA POSICION DEL ID ENCONTRADO
				break;
			}
		}
	}
	return index;
}

int findPassengerByFlycode(Passenger* list, int len, char flycode[]){//OK

	int index = -1;//RETURNS AN ILLOGICAL VALUE

	if(list !=NULL && len > 0 && flycode != NULL){
		for(int i = 0; i < len; i++){
			if(strcmp(list[i].flycode.flycode, flycode) == 0){
				index = i;//RETORNA POSICION DEL ID ENCONTRADO
				break;
			}
		}
	}
	return index;
}

//SUPRIMIR
int removePassenger(Passenger* list, int len, int id){//OK

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1){
		index = findPassengerById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].isEmpty = EMPTY;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengers(Passenger *list, int len, int order) {

	int retorno = -1;
	int i;
	int isOrdered;

	Passenger aux;

	if (list != NULL && len > 0 && order != -1){
		do {
			isOrdered = 1;
			len--;
			for (i = 0; i < len; i++) {
				if (list[i].id > list[i + 1].id) {
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
					isOrdered = 0;
				}
			}
		} while (isOrdered == 0);
		retorno = 0;
	}
	return retorno;
}

//REPORTAR
int printPassenger(Passenger* list, int len){//OK

	int retorno = -1;//FALSE

	if(list !=NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FULL && printPassengers(list[i]) == 0){
				retorno = 0;//TRUE
			}
		}
	}
 return retorno;
}

int printPassengers(Passenger passenger){//OK

	int retorno = -1;//FALSE
	int aux;



	if(passenger.isEmpty == FULL){
		aux = passenger.flycode.id_status;
		switch(passenger.typePassenger){
			case 1:
				printf("%d\n", aux);
				if(passenger.flycode.statusFlight == 1){
					printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tACTIVO\n",
					passenger.id, passenger.name, passenger.lastName,
					passenger.price, passenger.flycode.flycode);
					//printf("");
				}
				if(passenger.flycode.statusFlight == 2){
					printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tDEMORADO\n",
					passenger.id, passenger.name, passenger.lastName,
					passenger.price, passenger.flycode.flycode);
					//printf("%s \tDEMORADO\n", passenger.flycode.flycode);
				}
				if(passenger.flycode.statusFlight == 3){
					printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tREPROGRAMADO\n",
					passenger.id, passenger.name, passenger.lastName,
					passenger.price, passenger.flycode.flycode);
					//printf("%s \tREPROGRAMADO\n", passenger.flycode.flycode);
				}
				if(passenger.flycode.statusFlight == 4){
					printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tCANCELADO\n",
					passenger.id, passenger.name, passenger.lastName,
					passenger.price, passenger.flycode.flycode);
					//printf("%s \tCANCELADO\n", passenger.flycode.flycode);
				}
				break;
			case 2:
				printf("%d \t%-7s \t%-7s \t%0.2f \tEJECUTIVO \t%-7s \tCANCELADO\n",
				passenger.id, passenger.name, passenger.lastName,
				passenger.price, passenger.flycode.flycode);
//				printf("%d \t%-7s \t%-7s \t%0.2f \tEJECUTIVO \n",
//						passenger.id, passenger.name, passenger.lastName,
//						passenger.price);
				break;
			case 3:
				printf("%d \t%-7s \t%-7s \t%0.2f \tPREMIUM \t%-7s \tCANCELADO\n",
				passenger.id, passenger.name, passenger.lastName,
				passenger.price, passenger.flycode.flycode);
//				printf("%d \t%-7s \t%-7s \t%0.2f \tPREMIUM \n",
//						passenger.id, passenger.name, passenger.lastName,
//						passenger.price);
				break;
			case 4:
				printf("%d \t%-7s \t%-7s \t%0.2f \tTURISTA \t%-7s \tCANCELADO\n",
				passenger.id, passenger.name, passenger.lastName,
				passenger.price, passenger.flycode.flycode);
//				printf("%d \t%-7s \t%-7s \t%0.2f \tTURISTA \n",
//						passenger.id, passenger.name, passenger.lastName,
//						passenger.price);
				break;
			}
		retorno = 0;//TRUE
	}
	return retorno;
}

//MODIFICAR
int modifyPassengerName(Passenger* list, int len, int id, char name[]){//OK

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && name != NULL){
		index = findPassengerById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				strncpy(list[i].name, name, sizeof(list[i].name));
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyPassengerLastName(Passenger* list, int len, int id, char lastName[]){//OK

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && lastName != NULL){
		index = findPassengerById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				strncpy(list[i].lastName, lastName, sizeof(list[i].lastName));
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyTypePassenger(Passenger* list, int len, int id, int typePassenger){//OK

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && typePassenger != EMPTY){
		index = findPassengerById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].typePassenger = typePassenger;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyPassengerPrice(Passenger* list, int len, int id, float price){//OK

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && price != EMPTY){
		index = findPassengerById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				list[i].price = price;
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}

int modifyPassengerFlycode(Passenger* list, int len, int id, char flycode[]){//OK

	int retorno = -1;//FALSE
	int index;

	if(list !=NULL && len > 0 && id != -1 && flycode != NULL){
	index = findPassengerById(list, len, id);
		for(int i = 0; i < len; i++){
			if(i == index){
				strncpy(list[i].flycode.flycode, flycode, sizeof(list[i].flycode));
				retorno = 0;//TRUE
				break;
			}
		}
	}
	return retorno;
}


//Imaginemos que el caso que estamos tratando no es complicado ya que solo se cuenta con 2
//campos, pero si la estructura tuviese más campos, se debería asignar uno por uno y la tarea
//sería tediosa.
//Ejemplo 2
//Cargar los datos en una estructura para luego copiar los datos a otra.

//#include <stdio.h>
//#include <string.h>
//struct fecha { int dia,mes,anio;};

//struct gente {
//char nombre[20];
//struct fecha f_nacimiento;
//};

//void main(void){
	//struct gente pers;
	//struct fecha fn;

	//printf("Ingrese nombre");
	//gets(pers.nombre);

	//printf("Ingrese dia de nacimiento");
	//scanf("%d",&fn.dia);

	//printf("Ingrese mes de nacimiento");
	//scanf("%d",&fn.mes);

	//printf("Ingrese anio de nacimiento");
	//scanf("%d",&fn.anio);

	//acá se pasa el dia, mes y anio a la otra estructura que tiene el dato fecha con tipo de dato estruscura fecha
	//pers.f_nacimiento=fn;
//}

//Notas:
//• Los campos de una estructura pueden ser cualquiera de los tipos de variables conocidas
//(char , int , float , double) y tambien pueden ser vectores , matrices o punteros.
//• No se puede tener como estructura anidada a la misma estructura que se esta
//definiendo
