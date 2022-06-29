/*
 ============================================================================
 Name        : TP_[2].c
 Author      : BEGGI A.
 Version     :
 Copyright   : Your copyright notice
 Description : TP_[2].c in C, Ansi-style

 El trabajo se considera incompleto ya que la opcion "4-Informar" solo tiene un listar con las
opciones ordenar de forma ascdendente o descendente, no se entiende que toma por criterio de
ordenamiento.
El punto 4 pide:
4. INFORMAR:
1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
 ============================================================================
 */

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
	int id;

	int numeroId;

	int option;
	int option_aux;
	int orden;
	int criterio;

	int flag = 0;
	int flagControl = 0;

	char name[SIZE];
	char lastName[SIZE];
	float price;
	char flycode[10];
	int typePassenger;
	int status;

	float totalPasajes;
	float promedioPasajes;
	int contadorPasajesArribaPromedio;

	char messageTypePassenger[250];
	char messageOk[250];
	char messageError[250];
	char messageTitle[250];
	char messageStatus[250];

	strcpy(messageTypePassenger, "\nTIPO DE PASAJERO:\n 1. PRIMERA CLASE\n 2. EJECUTIVO\n 3. PREMIUM\n 4. TURISTA\n");
	strcpy(messageOk, "Operaci�n exitosa");
	strcpy(messageError, "Error, vuelva a intentarlo.\n");
	strcpy(messageTitle, "ID \tNOMBRE \t\tAPELLIDO  \tPRECIO \t\tTIPO \t\tCODIGO  \tESTADO\n"
			"-----------------------------------------------------------------------------------------------------");
	strcpy(messageStatus, "ESTADO DE VUELO\n\n1. ACTIVO\n2. DEMORADO\n3. REPROGRAMADO\n4. CANCELADO\n");

	puts("-----------------------------------------------------------------------------------------------------");
	puts("\t\t\t\t\t\tBIENVENIDO");
	puts("-----------------------------------------------------------------------------------------------------");
	puts("(Presiona 0 para carga autom�tica)");
	puts("-----------------------------------------------------------------------------------------------------");

	if(startMenu(list, ELEMENTS, status_list, ELEMENTS) == 0){
		do{
			puts("INGRESE UNA OPCI�N\n");

			puts("1. ALTA");
			puts("2. MODIFICAR");
			puts("3. BAJA");
			puts("4. INFORMAR");
			puts("5. SALIR");
			puts("-----------------------------------------------------------------------------------------------------");
			if(getInt("", &opcion) == 0){
				puts("-----------------------------------------------------------------------------------------------------");
			}else{
				printf("%s\n", messageError);
			}
			switch(opcion){
				case 0:
					if(flag == 0){
						if(hardcodeListMenu(list, ELEMENTS, id, status_list, ELEMENTS) == 0){
							printf("%s\n", messageOk);
							puts("-----------------------------------------------------------------------------------------------------");
						}
						flag = 1;
					}
					break;
				case 1:
					//ALTA
					id = idMenu();
					if(flagControl == 0 || flagControl == 1){
						while(getString("NOMBRE: ", name) != 0){
							printf("%s\n", messageError);
						}
						while(getString("APELLIDO: ", lastName) != 0){
							printf("%s\n", messageError);
						}
						do{
							getFloat("PRECIO: ", &price);
							if(price <= 0){
								printf("%s\n", messageError);
							}
						}while(price <= 0);
						do{
							printf("%s\n", messageTypePassenger);
							getInt("", &typePassenger);
							if(typePassenger < 1 || typePassenger > 4){
								printf("%s\n", messageError);
							}
						}while(typePassenger != 1 && typePassenger != 2 && typePassenger != 3 && typePassenger != 4);

						while(getCode("CODIGO: \n(s�lo 6 digitos)\n", flycode) != 0){
							printf("%s\n", messageError);
						}

						do{
							printf("%s\n", messageStatus);
							getInt("", &status);
							if(status < 1 || status > 4){
								printf("%s\n", messageError);
							}
						}while(status != 1 && status != 2 && status != 3 && status != 4);

						if(singUpMenu(list, ELEMENTS, id, name, lastName, price, typePassenger, flycode, status, status_list, ELEMENTS)==0){
							puts("-----------------------------------------------------------------------------------------------------");
							printf("%s\n", messageOk);
							puts("-----------------------------------------------------------------------------------------------------");
						}
						flagControl = 1;
					}
					break;
				case 2:
					//MODIFICAR
					if(flagControl == 1 || flag == 1){
					do{
						printf("%s\n", messageTitle);
						reportsMenu(list, ELEMENTS, status_list, ELEMENTS, 1);
						puts("-----------------------------------------------------------------------------------------------------");
						getInt("Ingrese el id del pasajero que desea modificar\n", &numeroId);

						if(findElemenMenu(list, ELEMENTS, numeroId, messageTitle, status_list) != -1){
							puts("-----------------------------------------------------------------------------------------------------");
							puts("\n�Desea continuar?\n");
							puts("1. SI");
							puts("2. NO");
							getInt("", &option_aux);
							if(option_aux == 1){
								do{
									puts("�Qu� desea modificar?\n");
									puts("1. NOMBRE");
									puts("2. APELLIDO");
									puts("3. PRECIO");
									puts("4. TIPO DE PASAJERO");
									puts("5. ESTADO DE VUELO");

									getInt("", &option);
								}while(option != 1 && option != 2 && option != 3 && option != 4 && option != 5);
									switch(option){
										case 1:
											if(modificationsMenu(list, ELEMENTS, numeroId, option, "NOMBRE: ", status_list, ELEMENTS, messageError) == 0){
												puts("-----------------------------------------------------------------------------------------------------");
												printf("%s\n", messageOk);
												puts("-----------------------------------------------------------------------------------------------------");
											}
											break;
										case 2:
											if(modificationsMenu(list, ELEMENTS, numeroId, option, "APELLIDO: ", status_list, ELEMENTS, messageError) == 0){
												puts("-----------------------------------------------------------------------------------------------------");
												printf("%s\n", messageOk);
												puts("-----------------------------------------------------------------------------------------------------");
											}
											break;
										case 3:
											if(modificationsMenu(list, ELEMENTS, numeroId, option, "PRECIO: ", status_list, ELEMENTS, messageError) == 0){
												puts("-----------------------------------------------------------------------------------------------------");
												printf("%s\n", messageOk);
												puts("-----------------------------------------------------------------------------------------------------");
											}
											break;
										case 4:
											if(modificationsMenu(list, ELEMENTS, numeroId, option, messageTypePassenger, status_list, ELEMENTS, messageError) == 0){
												puts("-----------------------------------------------------------------------------------------------------");
												printf("%s\n", messageOk);
												puts("-----------------------------------------------------------------------------------------------------");
											}
											break;
										case 5:
											if(modificationsMenu(list, ELEMENTS, numeroId, option, messageStatus, status_list, ELEMENTS, messageError) == 0){
												puts("-----------------------------------------------------------------------------------------------------");
												printf("%s\n", messageOk);
												puts("-----------------------------------------------------------------------------------------------------");
											}
											break;
									}
							}
							else{
								puts("-----------------------------------------------------------------------------------------------------");
							}
						}
					}while(option_aux != 1 && option_aux != 2);
					}else{puts("No es posible realizar la operacion, no hay datos cargados.\n");}
					break;
				case 3:
					//BAJA
					if(flagControl == 1 || flag == 1){
						do{
							printf("%s\n", messageTitle);
							reportsMenu(list, ELEMENTS, status_list, ELEMENTS, 1);
							puts("-----------------------------------------------------------------------------------------------------");
							getInt("Ingrese el id del pasajero que desea eliminar\n", &numeroId);

							if(findElemenMenu(list, ELEMENTS, numeroId, messageTitle, status_list) != -1){
								puts("-----------------------------------------------------------------------------------------------------");
								puts("\n�Desea continuar?\n");
								puts("1. SI");
								puts("2. NO");
								getInt("", &option_aux);
								if(option_aux == 1){
									if(deleteMenu(list, ELEMENTS, numeroId, status_list, ELEMENTS) == 0){
										puts("-----------------------------------------------------------------------------------------------------");
										printf("%s\n", messageOk);
										puts("-----------------------------------------------------------------------------------------------------");
									}
								}
							}puts("-----------------------------------------------------------------------------------------------------");
						}while(option_aux != 1 && option_aux != 2);
						flagControl = 0;
					}else{puts("No es posible realizar la operacion, no hay datos cargados.\n");}
					break;
				case 4:
					//INFORMES
					if(flagControl == 1 || flag == 1){
						puts("�Qu� informe desea visualizar?\n");
						puts("1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.");
						puts("2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio.");
						puts("3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�");
						puts("-----------------------------------------------------------------------------------------------------");
						getInt("", &criterio);
						while(criterio != 1 && criterio != 2 && criterio != 3){
							getInt(messageError, &criterio);
						}
						if(criterio != 2){
							puts("�C�mo desea ordenar la lista?\n");
							puts("1. DESCENDENTE");
							puts("2. ASCENDENTE");
							puts("-----------------------------------------------------------------------------------------------------");
							getInt("", &orden);
							while(orden != 1 && orden != 2){
								getInt(messageError, &orden);
							}
						}
						switch(criterio){
						case 1:
							if(orderMenu(list, ELEMENTS, status_list, ELEMENTS, orden, criterio) == 0){
								printf("%s\n", messageTitle);
								reportsMenu(list, ELEMENTS, status_list, ELEMENTS, criterio);
								puts("-----------------------------------------------------------------------------------------------------");
							}
							break;
						case 2:
							contadorPasajesArribaPromedio = reportPriceMenu(list, ELEMENTS, status_list, ELEMENTS, &totalPasajes, &promedioPasajes);
							if(contadorPasajesArribaPromedio > 0){
								printf("La suma total de todos los precios de los pasajes es %.2f\n", totalPasajes);
								printf("El promedio de los pasajes es %.2f\n", promedioPasajes);
								printf("La cantidad de pasajes con un precio mayor al promedio es %d\n", contadorPasajesArribaPromedio);
								puts("-----------------------------------------------------------------------------------------------------");
							}
							break;
						case 3:
							if(orderMenu(list, ELEMENTS, status_list, ELEMENTS, orden, criterio) == 0){
								printf("%s\n", messageTitle);
								reportsMenu(list, ELEMENTS, status_list, ELEMENTS, criterio);
								puts("-----------------------------------------------------------------------------------------------------");
							}
							break;
						}



					}else{puts("No es posible realizar la operacion, no hay datos cargados.\n");}
					break;
				case 5:
					puts("\t\t\t  **GRACIAS**");
					puts("-----------------------------------------------------------------------------------------------------");
					break;
				default:
					printf("%s\n",messageError);
					break;
			}

		}while(opcion != 5);
	}else{
		puts("No se pudo inicializar la lista");
	}

	puts("\nTP_2\nBeggi A.");
	return EXIT_SUCCESS;
}
