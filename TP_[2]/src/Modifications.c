/*
 * Modifications.c
 *
 *  Created on: 4 oct. 2021
 *      Author: Beggi - Agostina
 */

#include "Modifications.h"

#define SIZE_STRING 51

int Get_Name(Employee* list, int len,int id){

	int retorno;
	int estado;
	int i;
	Employee employee;

	retorno = 0;

	estado = Get_String(employee.name, SIZE_STRING, "NOMBRE: ");
	if(estado == 1){
		for(i = 0; i < len; i++){
			if(list[i].id == id){
				strncpy(list[i].name, employee.name, SIZE_STRING);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int Get_Lastname(Employee* list, int len,int id){

	int retorno;
	int estado;
	int i;
	Employee employee;

	retorno = 0;

	estado = Get_String(employee.lastName, SIZE_STRING, "APELLIDO: ");
	if(estado == 1){
		for(i = 0; i < len; i++){
			if(list[i].id == id){
				strncpy(list[i].lastName, employee.lastName, SIZE_STRING);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int Get_Salary(Employee* list, int len,int id){

	int retorno;
	int estado;
	float salario;
	int i;
	Employee employee;

	retorno = 0;

	estado = Get_A_Number_Float("SALARIO: ", &salario);
	if(estado == 1){
		employee.salary = salario;
		for(i = 0; i < len; i++){
			if(list[i].id == id){
				list[i].salary = employee.salary;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int Get_Sector(Employee* list, int len,int id){

	int retorno;
	int estado;
	float sector;
	int i;
	Employee employee;

	retorno = 0;

	estado = Get_A_Number_Float("SECTOR: ", &sector);
	if(estado == 1){
		employee.sector = sector;
		for(i = 0; i < len; i++){
			if(list[i].id == id){
				list[i].sector = employee.sector;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
