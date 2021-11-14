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
#include "Menu.h"
#include "Validation.h"

#define SIZE_LIST 4
#define SIZE_STRING 51
// \t cada tabulacion son 8 espacios
//strcpy = es insegura, no avisa si se desborda la cadena
//strcpy(cadena1, cadena2);
//strncpy = es segura, no desborda la cadena
//strncpy(cadena1, cadena2, sizeof(cadena1));
//strnlen (cadena1, sizeof(cadena1)); es segura y la puedo usar para determinar
//una cantidad maxima de caracteres
//strncat (cadena1, cadena2, sizeof(cadena1)); es segura y es para concatenar
//snprintf(cadena1, sizeof(cadena1), "texto", mascaras, lo que quiera);
//printf("%s", cadena1); //sirve para un título por ejemplo, o para listar

int main(void) {
	setbuf(stdout, NULL);

	Employee list[SIZE_LIST];
	int estado;
	int opcion;
	int retorno;
	int estadoOpcion;
	int id = 0;

	estado = initEmployees(list, SIZE_LIST);

	if(estado == 0){
		puts("-----------------------------------------------------------------");
		printf("\t\t\t  BIENVENIDO\n");
		puts("-----------------------------------------------------------------");

		do{
			puts("INGRESE UNA OPCIÓN: \n");
			puts("1. ALTA DE UN EMPLEADO");
			puts("2. MODIFICAR UN EMPLEADO");
			puts("3. BAJA DE UN EMPLEADO");
			puts("4. INFORMAR");

			estadoOpcion = Get_A_Number_Int("\n", &opcion);

			puts("-----------------------------------------------------------------");
			if(estadoOpcion == 1 && (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4)){
				retorno = MenuOptions(list, SIZE_LIST, opcion, id);
			}else{
				puts("Error");
			}

		} while (retorno == 1);
		puts("GRACIAS");
		puts("-----------------------------------------------------------------");
	}
	return EXIT_SUCCESS;
}

