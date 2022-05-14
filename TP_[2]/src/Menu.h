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

/// \fn int idMenu()
/// \brief using static int generate an autoincrementing id.
/// \return int id.
int idMenu();

/// \fn int startMenu(Passenger*, int, Status*, int)
/// \brief calls initPassengers and initStatus to initialize the two parameter lists.
/// \param list
/// \param len
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int startMenu(Passenger* list, int len, Status* status_list, int lenStatus);

/// \fn void generateCodeMenu(char[])
/// \brief generates an alphanumeric code and assigns it to the parapet flycode.
/// \param flycode
void generateCodeMenu(char flycode[]);

/// \fn int hardcodeListMenu(Passenger*, int, int, Status*, int)
/// \brief automatically fills 10 positions of the parameter lists.
/// \param list
/// \param len
/// \param id
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int hardcodeListMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus);

/// \fn int singUpMenu(Passenger*, int, int, char[], char[], float, int, char[], Status*, int)
/// \brief calls addPassenger and findStatusByCode to add a sado to each list of parameters
/// \param list
/// \param len
/// \param id
/// \param name
/// \param lastName
/// \param price
/// \param typePassenger
/// \param flycode
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int singUpMenu(Passenger* list, int len, int id, char name[],char lastName[],
		float price, int typePassenger,char flycode[], Status* status_list, int lenStatus);

/// \fn int deleteMenu(Passenger*, int, int, Status*, int)
/// \brief calls removePassenger and deleteStatus to remove an element in both parameter lists.
/// \param list
/// \param len
/// \param id
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int deleteMenu(Passenger* list, int len, int id, Status* status_list, int lenStatus);

/// \fn int modificationsMenu(Passenger*, int, int, int, char[], Status*, int, char[])
/// \brief calls functions from the ArrayPassenger.h and ArrayStatus.h libraries
/// and, depending on the parameter option, calls the indicated function to
/// make the relevant changes.
/// \param list
/// \param len
/// \param id
/// \param option
/// \param message
/// \param status_list
/// \param lenStatus
/// \param messageError
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modificationsMenu(Passenger* list, int len, int id, int option, char message[], Status* status_list, int lenStatus, char messageError[]);

/// \fn int reportsMenu(Passenger*, int, Status*, int)
/// \brief calls printPassenger to print the data from the two parameter lists
/// \param list
/// \param len
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int reportsMenu(Passenger* list, int len, Status* status_list, int lenStatus);

/// \fn int orderMenu(Passenger*, int, Status*, int, int)
/// \brief calls sortPassengers to sort the data from the two parameter lists
/// \param list
/// \param len
/// \param status_list
/// \param lenStatus
/// \param order
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int orderMenu(Passenger* list, int len, Status* status_list, int lenStatus, int order);

/// \fn int findElemenMenu(Passenger*, int, int, char[], Status*)
/// \brief calls findPassengerById and if it returns a valid position, prints the selected
/// item using the printPassengers function.
/// \param list
/// \param len
/// \param id
/// \param message
/// \param status_list
/// \return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int findElemenMenu(Passenger* list, int len, int id, char message[], Status* status_list);

#endif /* MENU_H_ */
