/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Beggi - Agostina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Menu.h"

#define ELEMENTS 1000
#define SIZE 51

int main(void) {
	setbuf(stdout, NULL);

	Passenger list [ELEMENTS];
	Status status_list[ELEMENTS];

	int opcion;
	int id = 0;

	int numeroId;

	int option;

	char name[SIZE];
	char lastName[SIZE];
	float price;
	char flycode[10];
	int typePassenger;

	char messageTypePassenger[250];
	char messageOk[250];
	char messageError[250];

	strcpy(messageTypePassenger, "TIPO DE PASAJERO\n\n1. PRIMERA CLASE\n2. EJECUTIVO\n3. PREMIUM\n4. TURISTA\n");
	strcpy(messageOk, "Operación exitosa");
	strcpy(messageError, "Opción incorrecta, vuelva a intentarlo.\n");

	// !!!!!!!Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
	//carga de algún empleado.!!!!!!!!

	//statusFlight (int), se entiende que admite dos valores para que discrimines
	//si el vuelo fue efectuado o no
	// estado de vuelo ACTIVO, CANCELADO, DEMORADO, REPROGRAMADO.
	//está pensado para hacer una segunda estructura relacionada con el codigo de vuelo, donde en la segunda estructura
	//el id sería el codigo de vuelo y otro campo de estado. Entonces solo cambiando el estado de vuelo
	//en la estructura donde está el codigo de vuelo, se puede cambiar el estado de vuelo, para todos los
	//pasajeros que tienen el mismo codigo de vuelo.

	puts("------------------------------------------------------------------");
	puts("\t\t\t  BIENVENIDO");
	puts("------------------------------------------------------------------");

	if(startMenu(list, ELEMENTS, status_list, ELEMENTS) == 0){
		do{
			puts("INGRESE UNA OPCIÓN\n");

			puts("1. ALTA");
			puts("2. MODIFICAR");
			puts("3. BAJA");
			puts("4. INFORMAR");
			puts("5. SALIR");

			puts("------------------------------------------------------------------");
			if(getInt("", &opcion) == 0){

				puts("------------------------------------------------------------------");

				switch(opcion){
				case 1:
					//ALTA
					id=idMenu(id);

					getString("NOMBRE: ", name);
					getString("APELLIDO: ", lastName);
					getFloat("PRECIO: ", &price);
					getStringAlnum("CODIGO DE VEULO: ", flycode);
					do{
						printf("%s\n", messageTypePassenger);
						getInt("", &typePassenger);
						if(typePassenger < 1 || typePassenger > 4){
							printf("%s\n", messageError);
						}

					}while(typePassenger != 1 && typePassenger != 2 && typePassenger != 3 && typePassenger != 4);


					if(singUpMenu(list, ELEMENTS, id, name, lastName, price, typePassenger, flycode)==0){
						puts("------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("------------------------------------------------------------------");

					}
					break;
				case 2:
					//MODIFICAR
					puts("ID \ttNOMBRE \tAPELLIDO  \tPRECIO  \tCODIGO \tTIPO");
					reportsMenu(list, ELEMENTS);
					puts("------------------------------------------------------------------");
					getInt("Ingrese el id del pasajero que desea modificar\n", &numeroId);
					//VALIDAR EL ID INGRESADO
					do{
						puts("¿Qué desea modificar?\n");
						puts("1. NOMBRE");
						puts("2. APELLIDO");
						puts("3. PRECIO");
						puts("4. CODIGO DE VUELO");
						puts("5. TIPO DE PASAJERO");

						getInt("", &option);

					}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);

					switch(option){
						case 1:
							if(MenuModifications(list, ELEMENTS, numeroId, option, "NOMBRE: ") == 0){
								puts("------------------------------------------------------------------");
								printf("%s\n", messageOk);
								puts("------------------------------------------------------------------");
							}
							break;
						case 2:
							if(MenuModifications(list, ELEMENTS, numeroId, option, "APELLIDO: ") == 0){
								puts("------------------------------------------------------------------");
								printf("%s\n", messageOk);
								puts("------------------------------------------------------------------");
							}
							break;
						case 3:
							if(MenuModifications(list, ELEMENTS, numeroId, option, "PRECIO: ") == 0){
								puts("------------------------------------------------------------------");
								printf("%s\n", messageOk);
								puts("------------------------------------------------------------------");
							}
							break;
						case 4:
							if(MenuModifications(list, ELEMENTS, numeroId, option, "CODIGO: \n") == 0){
								puts("------------------------------------------------------------------");
								printf("%s\n", messageOk);
								puts("------------------------------------------------------------------");
							}
							break;
						case 5:
							if(MenuModifications(list, ELEMENTS, numeroId, option, messageTypePassenger) == 0){
								puts("------------------------------------------------------------------");
								printf("%s\n", messageOk);
								puts("------------------------------------------------------------------");
							}
							break;
					}

					break;
				case 3:
					//BAJA
					puts("ID \ttNOMBRE \tAPELLIDO  \tPRECIO  \tCODIGO \tTIPO");
					reportsMenu(list, ELEMENTS);

					getInt("Ingrese el id del pasajero que desea eliminar\n", &numeroId);
					if(deleteMenu(list, ELEMENTS, numeroId) == 0){
						puts("------------------------------------------------------------------");
						printf("%s\n", messageOk);
						puts("------------------------------------------------------------------");
					}
					break;
				case 4:
					//INFORMES
//					if(MenuOrden(listaEmpleados, ELEMENTS) == 0){
//
//						puts("ID \ttNOMBRE \tAPELLIDO  \tPRECIO  \tCODIGO \tTIPO");
//						reportsMenu(list, ELEMENTS);
//						puts("------------------------------------------------------------------");
//					}
					break;
				case 5:
					puts("\t\t\t  **GRACIAS**");
					puts("------------------------------------------------------------------");
					break;
				default:
					printf("%s\n",messageError);
					break;
				}
			}else{
				printf("%s\n", messageError);
			}

		}while(opcion != 5);
	}else{
		puts("No se pudo inicializar la lista");
	}

	puts("\nTP_2\nBeggi A."); /* prints TP_2 */



	return EXIT_SUCCESS;
}
