/*
 * Array_de_Employee.h
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#ifndef ARRAY_DE_EMPLOYEE_H_
#define ARRAY_DE_EMPLOYEE_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Input.h"
#include "Validation.h"

struct {
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;
}typedef Employee;

#endif /* ARRAY_DE_EMPLOYEE_H_ */
