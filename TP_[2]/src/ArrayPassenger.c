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
		char lastName[], float price, int typePassenger, char flycode[],
		Status* status_list, int lenStatus){

	int retorno = -1;//FALSE
	int index_P;
	int index_S;
	Passenger passenger_aux;

	if(list != NULL && len > 0 && id != -1 && name !=NULL && lastName !=NULL &&
		price != EMPTY && typePassenger != EMPTY && flycode != NULL  && status_list != NULL &&
		lenStatus > 0){

		index_P = findPassengerEmpty(list, len);
		index_S = findStatusEmpty(status_list, lenStatus);

		if(addStatus(status_list, lenStatus, flycode) == 0){
			strncpy(passenger_aux.flycode, status_list[index_S].flycode, sizeof(passenger_aux.flycode));
			passenger_aux.id = id;
			strncpy(passenger_aux.name, name, sizeof(passenger_aux.name));
			strncpy(passenger_aux.lastName, lastName, sizeof(passenger_aux.lastName));
			passenger_aux.price = price;
			strncpy(passenger_aux.flycode, flycode, sizeof(passenger_aux.flycode));
			passenger_aux.typePassenger = typePassenger;
			passenger_aux.isEmpty = FULL;

			for(int i = 0; i < len; i++){
				if(i == index_P && i == index_S){
					list[i] = passenger_aux;
					retorno = 0;//TRUE
				}
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
			if(strcmp(list[i].flycode, flycode) == 0){
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

//ORDENAR
int sortPassengers(Passenger *list, int len, int order, Status* status_list, int lenStatus) {

	int retorno = -1;
	int i;
	int isOrdered;

	Passenger aux;
	Status aux_S;

	if (list != NULL && len > 0 && order != -1){
		switch(order){
			case 1:
				do {
					isOrdered = 1;
					len--;
					for (i = 0; i < len; i++) {
						if (list[i].typePassenger > list[i + 1].typePassenger
							&& strcmp(list[i].flycode, status_list[i].flycode) == 0){
							aux = list[i];
							aux_S = status_list[i];
							list[i] = list[i + 1];
							status_list[i] = status_list[i + 1];
							list[i + 1] = aux;
							status_list[i + 1] = aux_S;
							isOrdered = 0;
						}else if(list[i].typePassenger == list[i + 1].typePassenger
								&& strcmp(list[i].lastName, list[i + 1].lastName) > 0
								&& strcmp(list[i].flycode, status_list[i].flycode) == 0){
							aux = list[i];
							aux_S = status_list[i];
							list[i] = list[i + 1];
							status_list[i] = status_list[i + 1];
							list[i + 1] = aux;
							status_list[i + 1] = aux_S;
							isOrdered = 0;
						}
					}
				} while (isOrdered == 0);
				retorno = 0;
				break;
			case 2:
				do {
					isOrdered = 1;
					len--;
					for (i = 0; i < len; i++) {
						if (list[i].typePassenger < list[i + 1].typePassenger
							&& strcmp(list[i].flycode, status_list[i].flycode) == 0) {
							aux = list[i];
							aux_S = status_list[i];
							list[i] = list[i + 1];
							status_list[i] = status_list[i + 1];
							list[i + 1] = aux;
							status_list[i + 1] = aux_S;
							isOrdered = 0;
						}else if(list[i].typePassenger == list[i + 1].typePassenger
								&& strcmp(list[i].lastName, list[i + 1].lastName) < 0
								&& strcmp(list[i].flycode, status_list[i].flycode) == 0){
							aux = list[i];
							aux_S = status_list[i];
							list[i] = list[i + 1];
							status_list[i] = status_list[i + 1];
							list[i + 1] = aux;
							status_list[i + 1] = aux_S;
							isOrdered = 0;
						}
					}
				} while (isOrdered == 0);
				retorno = 0;
				break;
		}
	}
	return retorno;
}

//REPORTAR
int printPassenger(Passenger* list, int len, Status* status_list, int lenStatus){//OK

	int retorno = -1;//FALSE

	if(list !=NULL && len > 0 && status_list !=NULL && lenStatus > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FULL && printPassengers(list[i], status_list[i]) == 0){
				retorno = 0;//TRUE
			}
		}
	}
 return retorno;
}

int printPassengers(Passenger passenger, Status status){//OK

	int retorno = -1;//FALSE

	if(passenger.isEmpty == FULL){
		switch(passenger.typePassenger){
			case 1:
				switch(status.statusFlight){
					case 1:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tACTIVO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 2:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tDEMORADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 3:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tREPROGRAMADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 4:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPRIMERA CLASE \t%-7s \tCANCELADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					}
				break;
			case 2:
				switch(status.statusFlight){
					case 1:
						printf("%d \t%-7s \t%-7s \t%0.2f \tEJECUTIVO \t%-7s \tACTIVO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 2:
						printf("%d \t%-7s \t%-7s \t%0.2f \tEJECUTIVO \t%-7s \tDEMORADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 3:
						printf("%d \t%-7s \t%-7s \t%0.2f \tEJECUTIVO \t%-7s \tREPROGRAMADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 4:
						printf("%d \t%-7s \t%-7s \t%0.2f \tEJECUTIVO \t%-7s \tCANCELADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					}
				break;
			case 3:
				switch(status.statusFlight){
					case 1:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPREMIUM \t%-7s \tACTIVO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 2:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPREMIUM \t%-7s \tDEMORADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 3:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPREMIUM \t%-7s \tREPROGRAMADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 4:
						printf("%d \t%-7s \t%-7s \t%0.2f \tPREMIUM \t%-7s \tCANCELADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					}
				break;
			case 4:
				switch(status.statusFlight){
					case 1:
						printf("%d \t%-7s \t%-7s \t%0.2f \tTURISTA \t%-7s \tACTIVO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 2:
						printf("%d \t%-7s \t%-7s \t%0.2f \tTURISTA \t%-7s \tDEMORADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 3:
						printf("%d \t%-7s \t%-7s \t%0.2f \tTURISTA \t%-7s \tREPROGRAMADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					case 4:
						printf("%d \t%-7s \t%-7s \t%0.2f \tTURISTA \t%-7s \tCANCELADO\n",
								passenger.id, passenger.name, passenger.lastName,
								passenger.price, passenger.flycode);
						break;
					}
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
				strncpy(list[i].flycode, flycode, sizeof(list[i].flycode));
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
