/*
 * Calculator.c
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#include "Calculator.h"

float Discount(float cost, float discount){

	float total;

	total = cost - (cost * discount);

	return total;
}

float Tax(float cost, float tax){

	float total;

	total = cost + (cost * tax);

	return total;
}

float BitCoin(float cost, float bitCoin){

	float total;

	total = bitCoin /cost;

	return total;
}

float UnitPrice(float cost, int units){

	float total;

	total = cost / units;

	return total;
}

float Difference(float costA, float costB){

	float total;

	if(costA > costB){
		total = costA - costB;
	}else{
		total = costB - costA;
	}

	return total;
}

int AllCalculations(float discount, float bitCoin, float interest, float price, int km, float*pDiscount, float* pIncrease, float* pBitCoin, float* pUnitPrice){

	int retorno;

	retorno = -1;

	if(pDiscount != NULL && pIncrease != NULL && pBitCoin != NULL && pUnitPrice != NULL){
		*pDiscount = Discount(price, discount);
		*pIncrease = Tax(price, interest);
		*pBitCoin = BitCoin(price, bitCoin);
		*pUnitPrice = UnitPrice(price, km);

		retorno = 0;
	}


	return retorno;
}

