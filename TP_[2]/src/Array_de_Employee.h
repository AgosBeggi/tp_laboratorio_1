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

/// \fn int initEmployees(Employee*, int)
/// \brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// \param list
/// \param len
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int initEmployees(Employee* list, int len);

/// \fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// \brief Add in a existing list of employees the values received as parameters
///  in the first empty position.
/// \param list
/// \param len
/// \param name
/// \param lastName
/// \param salary
/// \param sector
/// \param id
/// \return Return (-1) if Error [Invalid length or NULL pointer or without
/// free space] - (0) if Ok.
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector, int id);

/// \fn int findEmployeeById(Employee*, int, int)
/// \brief Find an Employee by Id en returns the index position in array.
/// \param list
/// \param len
/// \param id
/// \return Return employee index position or (-1) if [Invalid length or NULL
/// pointer received or employee not found].
int findEmployeeById(Employee* list, int len,int id);

/// \fn int removeEmployee(Employee*, int, int)
/// \brief Remove a Employee by Id (put isEmpty Flag in 1).
/// \param list
/// \param len
/// \param index
/// \return Return (-1) if Error [Invalid length or NULL pointer or if can't
/// find a employee] - (0) if Ok.
int removeEmployee(Employee* list, int len, int index);

/// \fn int sortEmployees(Employee*, int, int)
/// \brief Sort the elements in the array of employees, the argument order
/// indicate UP or DOWN order.
/// \param list
/// \param len
/// \param order
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int sortEmployees(Employee* list, int len, int order);

void printEmployee(Employee employee);

/// \fn int printEmployees(Employee*, int)
/// \brief Print the content of employees array.
/// \param list
/// \param len
/// \return Return int.
int printEmployees(Employee* list, int len);

#endif /* ARRAY_DE_EMPLOYEE_H_ */
