/*
 * Calculator.h
 *
 *  Created on: 7 abr. 2022
 *  Author: BEGGI A.
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stdio.h>

/// @fn float Discount(float, float)
/// @brief Receive a price and a discount,
/// calculate the total price with the discount applied.
/// @param cost
/// @param discount
/// @return Returns the calculated total.
float Discount(float cost, float discount);

/// @fn float Tax(float, float)
/// @brief Receive a price and a tax, calculate
/// the total price with the increase applied.
/// @param cost
/// @param tax
/// @return Returns the calculated total.
float Tax(float cost, float tax);

/// @fn float BitCoin(float, float)
/// @brief Receive a price and the value of a bitcoin,
/// calculate the total price in bitcoin.
/// @param cost
/// @param bitCoin
/// @return Returns the calculated total.
float BitCoin(float cost, float bitCoin);

/// @fn float UnitPrice(float, int)
/// @brief Receive a price and the number of units,
/// calculate the total unit price.
/// @param cost
/// @param units
/// @return Returns the calculated total.
float UnitPrice(float cost, int units);

/// @fn float Difference(float, float)
/// @brief It receives two prices and calculates
/// the difference between them.
/// @param costA
/// @param costB
/// @return Returns the calculated total.
float Difference(float costA, float costB);

/// @fn int AllCalculations(float, float, float, float, int, float*, float*, float*, float*)
/// @brief Calculates each of the values with the price and passes each result to the pointers by value.
/// @param discount
/// @param bitCoin
/// @param interest
/// @param price
/// @param km
/// @param pDiscount
/// @param pIncrease
/// @param pBitCoin
/// @param pUnitPrice
/// @return Returns 0 for true and -1 for false.
int AllCalculations(float discount, float bitCoin, float interest, float price, int km, float*pDiscount, float* pIncrease, float* pBitCoin, float* pUnitPrice);

#endif /* CALCULATOR_H_ */
