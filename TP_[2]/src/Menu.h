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

int startMenu(Passenger* list, int len, Status* status_list, int lenStatus);

int singUpMenu(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[]);

int deleteMenu(Passenger* list, int len, int id);

int MenuModifications(Passenger* list, int len, int id, int option, char message[]);

int reportsMenu(Passenger* list, int len);

int orderMenu(Passenger* list, int len);

int idMenu(int id);


#endif /* MENU_H_ */
