/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Beggi - Agostina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*TP_1
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 */

#include <stdio.h>
#include <stdlib.h>

#include "Ingresos.h"
#include "Validaciones.h"
#include "OperacionesMatematicas.h"
#include "Salidas.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float primerNumero;
	float segundoNumero;
	int flagPrimerNumero;
	int flagSegundoNumero;
	float suma;
	float resta;
	float division;
	float resultadoDividir;
	float multiplicacion;
	int factorialA;
	int factorialB;
	int resultadoFactoreoA;
	int resultadoFactoreoB;

	flagPrimerNumero = 0;
	flagSegundoNumero = 0;

	do {
		printf("\n1. Ingresar 1er operando\n");
		printf("2. Ingresar 2do operando\n");
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			primerNumero = IngresoNumero("Ingrese el primer numero\n");
			flagPrimerNumero = 1;
			break;
		case 2:
			segundoNumero = IngresoNumero("Ingrese el segundo numero\n");
			flagSegundoNumero = 1;
			break;
		case 3:
			if (flagPrimerNumero == 1 && flagSegundoNumero == 1) {
				suma = Sumar(primerNumero, segundoNumero);
				resta = Restar(primerNumero, segundoNumero);
				division = Dividir(&resultadoDividir, primerNumero, segundoNumero);
				multiplicacion = Multiplicar(primerNumero, segundoNumero);
				factorialA = Factorear(&resultadoFactoreoA, primerNumero);
				factorialB = Factorear(&resultadoFactoreoB, segundoNumero);
			} else {
				printf(
						"Debe ingresar los operandos para poder hacer las operaciones matematicas\n");
			}
			break;
		case 4:
			MostrarResultado("El resultado de %.2f + %.2f es: %.2f\n", primerNumero, segundoNumero, suma);
			MostrarResultado("El resultado de %.2f - %.2f es: %.2f\n", primerNumero, segundoNumero, resta);

			if (division == 1) {
				MostrarResultado("El resultado de %.2f / %.2f es: %.2f\n", primerNumero, segundoNumero, resultadoDividir);
			} else {
				MensajeError("No se puede dividir por cero\n");
			}

			MostrarResultado("El resultado de %.2f * %.2f es: %.2f\n", primerNumero, segundoNumero, multiplicacion);
			if(factorialA==1){
				MostrarFactoreo("El factorial de %.2f es: %d\n", primerNumero, resultadoFactoreoA);
			}else{
				MensajeError("No se puede factorear por numeros negativos o con decimales\n");
			}
			if(factorialB==1){
				MostrarFactoreo("El factorial de %.2f es: %d\n", segundoNumero, resultadoFactoreoB);
			}else{
				MensajeError("No se puede factorear por numeros negativos o con decimales\n");
			}
			break;
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}
