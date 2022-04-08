/*
 ============================================================================
 Name        : TP_[1].c
 Author      : BEGGI A.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Calculator.h"
#include "Report.h"

#define DESCUENTO 0.1
#define INTERES 0.25
#define BITCOIN 4606954.55

int main(void) {
	setbuf(stdout, NULL);

	int option;
	int km;
	float precioAerolineas;
	float precioLatam;
	float descuentoA;
	float descuentoL;
	float aumentoA;
	float aumentoL;
	float bitA;
	float bitL;
	float precioUnitarioA;
	float precioUnitarioL;
	float diferencia;
	int flag;

	flag = 0;

	puts("------------------------------------------------------------------");
	puts("\t\t\t**BIENVENIDO**");
	puts("------------------------------------------------------------------");

	do{
		puts("INGRESE UNA OPCIÓN\n");

		puts("1. Ingresar Kilómetros");
		puts("2. Ingresar Precio de Vuelos");
		puts("3. Calcular todos los costos");
		puts("4. Informar Resultados");
		puts("5. Carga forzada de datos");
		puts("6. Salir");

		puts("------------------------------------------------------------------");
		if(GetInt("", &option) == 0){
			puts("------------------------------------------------------------------");
			switch(option){
			case 1:
				if(flag == 0){
					if(GetInt("Ingrese los Kilómetros\n", &km) == 0){
						puts("------------------------------------------------------------------");
						puts("Ingreso exitoso.");
						puts("------------------------------------------------------------------");
					}
					flag = 1;
				}
				break;
			case 2:
				if(flag == 1){
					if(GetFloat("- Precio vuelo Aerolíneas: ", &precioAerolineas) == 0){
						if(GetFloat("- Precio vuelo Latam: ", &precioLatam) == 0){
							puts("------------------------------------------------------------------");
							puts("Ingreso exitoso.");
							puts("------------------------------------------------------------------");
						}
					}
					flag = 2;
				}else{
					puts("Antes debe ingresar los Kilómetros.");
					puts("------------------------------------------------------------------");
				}
				break;
			case 3:
				if(flag == 2){
					if(AllCalculations(DESCUENTO, BITCOIN, INTERES, precioAerolineas, km, &descuentoA, &aumentoA, &bitA, &precioUnitarioA) == 0){

						if(AllCalculations(DESCUENTO, BITCOIN, INTERES, precioLatam, km, &descuentoL, &aumentoL, &bitL, &precioUnitarioL) == 0){
							puts("Cálculo exitoso");
							puts("------------------------------------------------------------------");
						}
					}
					flag = 3;
				}else{
					puts("Antes debe ingresar los Kilómetros y los precios de vuelo.");
					puts("------------------------------------------------------------------");
				}
				diferencia = Difference(precioAerolineas, precioLatam);
				break;
			case 4:
				if(flag == 3){
					printf("KMs Ingresados: %d km\n", km);

					printf("\nPrecio Aerolíneas: $ %.2f\n", precioAerolineas);
					InformValues(descuentoA, aumentoA, bitA, precioUnitarioA);

					printf("\nPrecio Aerolíneas: $ %.2f\n", precioLatam);
					InformValues(descuentoL, aumentoL, bitL, precioUnitarioL);

					printf("\nLa diferencia de precio es : $ %.2f\n", diferencia);

					puts("------------------------------------------------------------------");
				}else{
					puts("No es posible informar, sin antes haber hecho los cálculos.");
					puts("------------------------------------------------------------------");
				}
				break;
			case 5:

				km = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;
				if(AllCalculations(DESCUENTO, BITCOIN, INTERES, precioAerolineas, km, &descuentoA, &aumentoA, &bitA, &precioUnitarioA) == 0){
					if(AllCalculations(DESCUENTO, BITCOIN, INTERES, precioLatam, km, &descuentoL, &aumentoL, &bitL, &precioUnitarioL) == 0){
						diferencia = Difference(precioAerolineas, precioLatam);
					}
				}

				printf("KMs Ingresados: %d km\n", km);

				printf("\nPrecio Aerolíneas: $ %.2f\n", precioAerolineas);
				InformValues(descuentoA, aumentoA, bitA, precioUnitarioA);

				printf("\nPrecio Aerolíneas: $ %.2f\n", precioLatam);
				InformValues(descuentoL, aumentoL, bitL, precioUnitarioL);

				printf("\nLa diferencia de precio es : $ %.2f\n", diferencia);
				puts("\n------------------------------------------------------------------");
				break;
			case 6:
				puts("\t\t\t  **GRACIAS**");
				puts("------------------------------------------------------------------");
				break;
			default:
				puts("Opción incorrecta.\n");
				break;
			}
		}else{
			puts("Error. Ingrese sólo numeros\n");
		}
	}while(option != 6);

	puts("\nTP_1\nBeggi A.");

	return EXIT_SUCCESS;
}
