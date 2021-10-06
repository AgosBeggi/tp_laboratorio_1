/*
 * Modifications.h
 *
 *  Created on: 4 oct. 2021
 *      Author: Beggi - Agostina
 */

#ifndef MODIFICATIONS_H_
#define MODIFICATIONS_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Array_de_Employee.h"
#include "Input.h"
#include "Validation.h"

int Get_Name(Employee* list, int len,int id);

int Get_Lastname(Employee* list, int len,int id);

int Get_Salary(Employee* list, int len,int id);

int Get_Sector(Employee* list, int len,int id);

#endif /* MODIFICATIONS_H_ */
