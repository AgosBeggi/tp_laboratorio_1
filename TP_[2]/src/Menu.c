/*
 * Menu.c
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#include "Menu.h"

void MenuOptions(int *opcion){

	int opciones;
	int estadoOpcion;

	printf("1. Alta\n");
	printf("2. Mostrar\n");
	printf("3. Borrar producto\n");
	printf("4. Modificar Producto\n");
	printf("5. Ordenado Por Precio\n");
	printf("6. Ordenado Por Descripcion\n");
	printf("7. Listado de Iphone de EEUU\n");

	estadoOpcion = IngresoEntero("\nElija una opcion\n", &opciones);
	puts("-----------------------------------------------------------------");

	 if(estadoOpcion == 1){
		 *opcion = opciones;
	 }
}

