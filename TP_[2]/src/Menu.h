/*
 * Menu.h
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#ifndef MENU_H_
#define MENU_H_

#include "ArrayPassenger.h"
#include "ArrayStatus.h"
#include "Input.h"

#define SIZE 51

int idMenu(int* id, Passenger* list, int len);

int startMenu(Passenger* list, int len, Status* status_list, int lenStatus);

int hardcodeListMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus, int* auxId);

int singUpMenu(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, Status* status_list, int lenStatus);

int deleteMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus);

int MenuModifications(Passenger* list, int len, int id, int option, char message[], Status* status_list, int lenStatus, char messageError[]);

int reportsMenuAll(Passenger* list, int len, Status* status_list, int lenStatus);

int reportsMenu(Passenger* list, int len, Status* status_list, int lenStatus);

int orderMenu(Passenger* list, int len, int order);




#endif /* MENU_H_ */
