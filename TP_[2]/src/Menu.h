/*
 * Menu.h
 *
 *  Created on: 3 oct. 2021
 *      Author: Beggi - Agostina
 */

#ifndef MENU_H_
#define MENU_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Array_de_Employee.h"
#include "Input.h"
#include "Validation.h"

/// \fn int MenuOptions(int*)
/// \brief Print different options by console for the user to choose one.
/// It asks for a memory address and saves the chosen option.
/// \param opcion
/// \return Return
int MenuOptions(Employee* list, int len, int opcion, int id);

int MenuModification(Employee* list, int len, int id, int opcion);

int MenuList();

#endif /* MENU_H_ */
