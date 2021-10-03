/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Beggi - Agostina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Array_de_Employee.h"
#include "Input.h"
#include "Validation.h"
#include "Menu.h"

#define SIZE_LIST 1000

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	char seguir;

	Employee list[SIZE_LIST];

	puts("-----------------------------------------------------------------");
	printf("\t\t\t\tBienvenido\n");

	//INICIALIZAR LISTA

	do {
		puts(
				"-----------------------------------------------------------------");
		MenuSieteOpcionesProducto(&opcion); //ok

		switch (opcion) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		default:
			break;
		}
		puts(
				"-----------------------------------------------------------------");
		printf("¿Desea continuar?\n(s/n)\n");
		scanf("%c", &seguir);
	} while (seguir == 's' || seguir == 'S');

	puts("-----------------------------------------------------------------");
	printf("Gracias\n");

	return EXIT_SUCCESS;
}

