#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"
#include "Validation.h"

#define SIZE_STRING 128

int main()
{
	setbuf(stdout, NULL);
	//ESTA VARIABLE ES PARA LAS FUNCIONES BOOLEANAS
	int estado;
	//DECLARO LA LISTA
	LinkedList* pArrayListEmployee;
	//VARIABLE QUE GUARDA LA RUTA O NOMBRE DEL ARCHIVO
	char ruta[SIZE_STRING];
	//VARIABLES DEL MENÚ
	int estadoOpcion;
	int opcion;

	//INICIO DEL PROGRAMA
	puts("-----------------------------------------------------------------");
	printf("\t\t\t  BIENVENIDO\n");
	puts("-----------------------------------------------------------------");
	//CREAR LISTA
	pArrayListEmployee = ll_newLinkedList();

	do{
		//MOSTRAR OPCIONES DEL MENÚ
		puts("Ingrese una opción: \n");
		puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
		puts("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
		puts("3. Alta de empleado.");
		puts("4. Modificar datos de empleado.");
		puts("5. Baja de empleado.");
		puts("6. Listar empleados.");
		puts("7. Ordenar empleados.");
		puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
		puts("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
		puts("10. Salir\n");

		//GUARDAR OPCIÓN ELEGIDA
		estadoOpcion = Get_A_Number_Int("", &opcion);
		puts("-----------------------------------------------------------------");

		switch(opcion){
			case 1:
				estado = Get_String(ruta, SIZE_STRING, "Ingrese el nombre del archivo.\n");
				estado = controller_loadFromText(ruta , pArrayListEmployee);
				if(estado == 1){
					puts("-----------------------------------------------------------------");
					puts("Se pudo cargar el archivo a la lista");
					puts("-----------------------------------------------------------------");
				}
				break;
			case 2:
				estado = Get_String(ruta, SIZE_STRING, "Ingrese la ruta del archivo.\n");
				estado = controller_loadFromBinary(ruta , pArrayListEmployee);
				if(estado == 1){
					puts("-----------------------------------------------------------------");
					puts("Se pudo cargar el archivo a la lista");
					puts("-----------------------------------------------------------------");
				}
				break;
			case 3:
				puts("Alta de empleado.");

				estado = controller_addEmployee(pArrayListEmployee);
				if(estado == 1){
					puts("-----------------------------------------------------------------");
					puts("Se pudo cargar el archivo a la lista");
					puts("-----------------------------------------------------------------");
				}
				break;
			case 4:
				puts("4. Modificar datos de empleado.");
				estado = controller_editEmployee(pArrayListEmployee);
				if(estado == 1){
					puts("-----------------------------------------------------------------");
					puts("Se pudo cargar el archivo a la lista");
					puts("-----------------------------------------------------------------");
				}
				break;
			case 5:
				puts("5. Baja de empleado.");
				puts("-----------------------------------------------------------------");
				break;
			case 6:
				puts("6. Listar empleados.");
				puts("-----------------------------------------------------------------");
				break;
			case 7:
				puts("7. Ordenar empleados.");
				puts("-----------------------------------------------------------------");
				break;
			case 8:
				puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
				puts("-----------------------------------------------------------------");
				break;
			case 9:
				puts("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
				puts("-----------------------------------------------------------------");
				break;
			case 10:
				puts("GRACIAS.");
				break;
			default:
				puts("Opción incorrecta, intenelo nuevamente.");
				puts("-----------------------------------------------------------------");
				break;
		}
	//Mientas la opción sea un numero y adeemás ese numero sea alguna de las opciones, iterar.
	} while(estadoOpcion == 1 && opcion != 10);
	/*estadoOpcion == 1 && (opcion != 1 || opcion != 2 || opcion != 3 || opcion != 4 ||
			opcion != 5 || opcion != 6 || opcion != 7 || opcion != 8 || opcion != 9 || opcion != 10)*/

	return 0;
}

