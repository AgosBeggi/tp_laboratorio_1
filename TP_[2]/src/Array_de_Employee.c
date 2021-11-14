/*
 * Array_de_Employee.c
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#include "Array_de_Employee.h"

#define EMPTY 0
#define FULL 1
#define SIZE_STRING 51
#define SIZE_ITEMS 51
#define STATUS "Empty"

// INICIALIZAR VECTOR.
int initEmployees(Employee* list, int len){

	int retorno;
	int i;

	retorno = -1;

	if(len > EMPTY && list != NULL){
		for(i = 0; i < len; i++){
			list[i].id = EMPTY;
			list[i].salary = EMPTY;
			list[i].sector = EMPTY;
			strcpy(list[i].name, STATUS);
			strcpy(list[i].lastName, STATUS);
			list[i].isEmpty = EMPTY;
			retorno = 0;
		}
	}

	return retorno;
}

// AGREGAR UN EMPLEADO.
int addEmployee(Employee* list, int len, char name[], char lastName[], float salary, int sector, int id){

	int retorno;
	int i;
	int index;
	Employee employee;

	retorno = -1;

	if(len > EMPTY && list != NULL){
		for(i = 0; i < len; i++){
			if(list[i].isEmpty == EMPTY){
				index = i;
				break;
			}
		}
		if (index != -1){
			employee.id = id;
			strncpy(employee.lastName, lastName, SIZE_STRING);
			strncpy(employee.name, name, SIZE_STRING);
			employee.salary = salary;
			employee.sector = sector;
			employee.isEmpty = FULL;
			list[index] = employee;
			retorno = 0;
		}
	}
	return retorno;
}

// ENCONTRAR UN EMPLEADO POR ID.
int findEmployeeById(Employee* list, int len,int id){

	int index;
	int i;

	index = -1;

	for(i = 0; i < len; i++){
		if(list[i].id == id){
			index = i;
			break;
		}
	}
	return index;
}

//Eliminar un Empleado por Id (poner isEmpty Flag en 1).
//Return (-1) if Error [Invalid length or NULL pointer or if can't
//find a employee] - (0) if Ok.

// REMOVER UN EMPLEADO.
int removeEmployee(Employee* list, int len, int index){

	int retorno;
	int i;

	retorno = -1;

	if(len > EMPTY && list != NULL){
		for(i = 0; i <= index; i++){
			if(list[i].isEmpty == FULL){
				list[i].isEmpty = EMPTY;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//Ordene los elementos en la matriz de empleados, el orden de los argumentos
//indica orden ARRIBA o ABAJO.

// ORDENAR LISTA.
int sortEmployees(Employee* list, int len, int order){

	int i;
	int j;
	Employee aux;
	int retorno;

	retorno = -1;

	if(len > EMPTY && list != NULL){
		for(i = 0; i <len; i++){
			for(j = i+1; j <len; j++){
				if(order == 1){
					if(list[i].id < list[j].id){
						list[i].isEmpty = EMPTY;
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
						retorno = 0;
						break;
					}
				}
				if(order == 2){
					if(list[i].id > list[j].id){
						list[i].isEmpty = EMPTY;
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
						retorno = 0;
						break;
					}
				}
			}
		}
	}

	return retorno;
}

void printEmployee(Employee employee){

	char items[SIZE_ITEMS];

	snprintf(items, SIZE_ITEMS, "%d\t%s\t\t%s\t\t%d\t$%.2f\n", employee.id, employee.name, employee.lastName, employee.sector, employee.salary);
	printf("%s", items);
}


//Imprima el contenido de la matriz de empleados.
//Retorna un entero.
// IMPRIMIR LISTA.
int printEmployees(Employee* list, int len){

	int retorno;
	int i;
	char items[SIZE_ITEMS];

	snprintf(items, SIZE_ITEMS, "ID\tNOMBRE\t\tAPELLIDO\t\tSECTOR\tSALARIO\n");
	printf("%s", items);

	retorno = -1;

	for(i = 0; i < len; i++){
		if(list[i].isEmpty == FULL){
			printEmployee(list[i]);
			retorno = 0;
		}
	}
	return retorno;
}

