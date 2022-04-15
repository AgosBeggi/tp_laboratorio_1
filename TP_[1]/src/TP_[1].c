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
#define AUX_KM 7090
#define AUX_PRECIO_AEROLINEAS 162965.00
#define AUX_PRECIO_LATAM 159339.00

int main(void) {
	setbuf(stdout, NULL);

	int option;
	int km;
	float precioAerolineas;
	float precioLatam;
	float descuentoA;
	float aux_descuentoA;
	float descuentoL;
	float aux_descuentoL;
	float aumentoA;
	float aumentoL;
	float aux_aumentoA;
	float aux_aumentoL;
	float bitA;
	float bitL;
	float aux_bitA;
	float aux_bitL;
	float aux_precioUnitarioA;
	float aux_precioUnitarioL;
	float precioUnitarioA;
	float precioUnitarioL;
	float diferencia;
	float aux_diferencia;
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
					puts("Antes debe ingresar los precios.");
					puts("------------------------------------------------------------------");
				}
				diferencia = Difference(precioAerolineas, precioLatam);
				break;
			case 4:
				if(flag == 3){
					printf("KMs Ingresados: %d km\n", km);

					printf("\nPrecio Aerolíneas: $ %.2f\n", precioAerolineas);
					InformValues(descuentoA, aumentoA, bitA, precioUnitarioA);

					printf("\nPrecio Latam: $ %.2f\n", precioLatam);
					InformValues(descuentoL, aumentoL, bitL, precioUnitarioL);

					printf("\nLa diferencia de precio es : $ %.2f\n", diferencia);

					puts("------------------------------------------------------------------");
				}else{
					puts("No es posible informar, sin antes haber hecho los cálculos.");
					puts("------------------------------------------------------------------");
				}
				break;
			case 5:

				if(AllCalculations(DESCUENTO, BITCOIN, INTERES, AUX_PRECIO_AEROLINEAS, AUX_KM, &aux_descuentoA, &aux_aumentoA, &aux_bitA, &aux_precioUnitarioA) == 0){

					if(AllCalculations(DESCUENTO, BITCOIN, INTERES, AUX_PRECIO_LATAM, AUX_KM, &aux_descuentoL, &aux_aumentoL, &aux_bitL, &aux_precioUnitarioL) == 0){
						aux_diferencia = Difference(AUX_PRECIO_AEROLINEAS, AUX_PRECIO_LATAM);
					}
				}

				printf("KMs Ingresados: %d km\n", AUX_KM);

				printf("\nPrecio Aerolíneas: $ %.2f\n", AUX_PRECIO_AEROLINEAS);
				InformValues(aux_descuentoA, aux_aumentoA, aux_bitA, aux_precioUnitarioA);

				printf("\nPrecio Latam: $ %.2f\n", AUX_PRECIO_LATAM);
				InformValues(aux_descuentoL, aux_aumentoL, aux_bitL, aux_precioUnitarioL);

				printf("\nLa diferencia de precio es : $ %.2f\n", aux_diferencia);
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
