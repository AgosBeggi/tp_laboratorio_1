/*
 * Menu.c
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#include "Menu.h"

#define SIZE_STRING 51

int MenuOptions(Employee* list, int len, int opcion, int id){

	int retorno;
	int estadoName;
	int estadoLastName;
	int estadoSalary;
	int estadoSector;
	char name[51];
	char lastName[51];
	float salary = 0;
	int sector = 0;
	int estado;
	int ingresoOpcion;
	int posicion;
	int estadoBusquedaID;
	int opcion2;
	int estadoEliminado;
	int index;
	int estadoAdd;

	//---------------------
	int opcion4;
	int order = 1;



	switch (opcion) {
		case 1:
			//id++;

			estadoName = Get_String(name, SIZE_STRING, "NOMBRE: ");
			while(estadoName == 1){
				puts("Error. Intente nuevamente.");
				estadoName = Get_String(name, SIZE_STRING, "NOMBRE: ");
			}
			estadoLastName = Get_String(lastName, SIZE_STRING, "APELLIDO: ");
			while(estadoLastName == 1){
				puts("Error. Intente nuevamente.");
				estadoLastName = Get_String(lastName, SIZE_STRING, "APELLIDO: ");
			}
			estadoSalary = Get_A_Number_Float("SALARIO: ", &salary);
			while(estadoSalary != 1){
				puts("Error. Intente nuevamente.");
				estadoSalary = Get_A_Number_Float("SALARIO: ", &salary);
			}
			estadoSector = Get_A_Number_Int("SECTOR: ", &sector);
			while(estadoSector != 1){
				puts("Error. Intente nuevamente.");
				estadoSector = Get_A_Number_Int("SECTOR: ", &sector);
			}
			if(estadoName == 1 && estadoLastName == 1 && estadoSalary == 1 && estadoSector== 1){
				id = id + 1;
				estadoAdd = addEmployee(list, len, name, lastName, salary, sector, id);
			}
			if(estadoAdd == 0){
				puts("\nSe cargó correctamente.");
			}
		break;
		case 2:
			estado = printEmployees(list, len);
			puts("-----------------------------------------------------------------");
			puts("\t\t\t  MODIFICAR");
			puts("-----------------------------------------------------------------");
			estado = Get_A_Number_Int("1. NOMBRE\n2. APELLIDO\n3. SALARIO\n4. SECTOR\n", &ingresoOpcion);
			puts("-----------------------------------------------------------------");

			estado = Get_A_Number_Int("Ingrese el ID del empleado a modificar: ", &posicion);
			puts("-----------------------------------------------------------------");
			estadoBusquedaID = findEmployeeById(list, len, posicion);//retorna la posicion del id encontrado o -1 para error
			if(estado == 1 && estadoBusquedaID == 0){
				opcion2 = MenuModification(list, len, posicion, ingresoOpcion);
				if(opcion2 == 1){
					puts("-----------------------------------------------------------------");
					puts("Se modificó correctamente.");
				}
			}
			break;
		case 3:
			puts("-----------------------------------------------------------------");
			puts("\t\t\t  ELIMINAR");
			puts("-----------------------------------------------------------------");
			puts("Ingrese el ID del empleado a dar de baja: \n");
			estado = printEmployees(list, len);
			estado = Get_A_Number_Int("\n", &index);
			puts("-----------------------------------------------------------------");
			estadoBusquedaID = findEmployeeById(list, len, index);//retorna la posicion del id encontrado o -1 para error
			if(estado == 1){
				estadoEliminado = removeEmployee(list, len, posicion);
				if(estadoEliminado == 0){
					puts("-----------------------------------------------------------------");
					puts("Se eliminó correctamente.");
					estado = sortEmployees(list, len, order);
				}else{
					puts("Error.");
				}

			}
			break;
		case 4:
			//opcion4 = MenuList();


			estado = printEmployees(list, len);
			break;
		default:
			puts("Opción incorrecta.");//si acá doy una opcion incorrecta, el id no funciona
			break;
		}
		puts("-----------------------------------------------------------------");
		estado = Get_A_Number_Int("¿Desea continuar?\n1. Si\n2. No\n", &retorno);
		puts("-----------------------------------------------------------------");




	return retorno;
}


int MenuModification(Employee* list, int len, int id, int opcion){

	int retorno;
	int estado;
	int estadoLastName;
	int estadoSalary;
	int estadoSector;
	Employee employee;

	estado = 0;

	switch(opcion){
		case 1:
			estado = Get_Name(list, len, id);
			break;
		case 2:
			estado = Get_Lastname(list, len, id);
			break;

		case 3:
			estado = Get_Salary(list, len, id);
			break;

		case 4:
			estado = Get_Sector(list, len, id);
			break;
		}


	return estado;
}

//OTRO MENU3 PARA INFORMAR CADA UNA DE LAS COSAS
//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
int MenuList(void){

	return 0;
}
