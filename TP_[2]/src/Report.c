/*
 * Report.c
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#include "Report.h"

void InformValues(float discount, float increase, float bitCoin, float unitPrice){

	printf("a) Precio con tarjeta de débito: $ %.2f\n", discount);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", increase);
	printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitCoin);
	printf("d) Precio unitario: $ %.2f\n", unitPrice);
}
