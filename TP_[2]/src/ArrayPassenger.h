/*
 * ArrayPassenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <string.h>
#include "ArrayStatus.h"

#define EMPTY 0
#define FULL 1
#define ELEMENTS 1000

#define PRIMERA 1
#define EJECUTIVO 2
#define PREMIUM 3
#define TURISTA 4

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}Passenger;

//INICIALIZACIÓN
/// \fn int initPassengers(Passenger*, int)
/// \brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// \param list
/// \param len
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(Passenger* list, int len);

//AGREGAR
/// \fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[], Status*, int)
/// \brief add in a existing list of passengers the values received as parameters
/// in the first empty position
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
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without
///free space] - (0) if Ok
int addPassenger(Passenger* list, int len, int id, char name[],
		char lastName[], float price, int typePassenger, char flycode[], int statePassenger,
		Status* status_list, int lenStatus);

//BUSQUEDA
/// \fn int findPassengerById(Passenger*, int, int)
/// \brief find a Passenger by Id and returns the index position in array.
/// \param list
/// \param len
/// \param id
/// \return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int findPassengerById(Passenger* list, int len,int id);

/// \fn int findPassengerEmpty(Passenger*, int)
/// \brief find the first position empty, returns the index position in array.
/// \param list
/// \param len
/// \return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int findPassengerEmpty(Passenger* list, int len);

/// \fn int findPassengerByFlycode(Passenger*, int, char[])
/// \brief
/// \param list
/// \param len
/// \param flycode
/// \return Return index position or (-1) if [Invalid length or NULL
/// pointer received or passenger not found].
int findPassengerByFlycode(Passenger* list, int len, char flycode[]);

//SUPRIMIR
/// \fn int removePassenger(Passenger*, int, int)
/// \brief Remove a Passenger by Id (put isEmpty Flag in 1)
/// \param list
/// \param len
/// \param id
/// \return Return (-1) if Error [Invalid length or NULL pointer or if can't
/// find a passenger] - (0) if Ok
int removePassenger(Passenger* list, int len, int id);

//ORDENAR
/// \fn int sortPassengers(Passenger*, int, int, Status*, int)
/// \brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order
/// \param list
/// \param len
/// \param order
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengers(Passenger* list, int len, int order, Status* status_list, int lenStatus);

int sortPassengers2(Passenger* list, int len, int order, Status* status_list, int lenStatus);

//INFORMES
/// \fn int printPassenger(Passenger*, int, Status*, int)
/// \brief print the content of passengers array.
/// \param list
/// \param len
/// \param status_list
/// \param lenStatus
/// \return int int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printPassenger(Passenger* list, int len, Status* status_list, int lenStatus);

int printActivePassengers(Passenger* list, int len, Status* status_list, int lenStatus);

int printActivePassenger(Passenger passenger, Status status);

/// \fn int printPassengers(Passenger, Status)
/// \brief print the content of a single element of the array.
/// \param passenger
/// \param status
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printPassengers(Passenger passenger, Status status);

//MODIFICACIONES
/// \fn int modifyPassengerName(Passenger*, int, int, char[])
/// \brief modifies the name of the element from the id matching the id of the parameter.
/// \param list
/// \param len
/// \param id
/// \param name
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modifyPassengerName(Passenger* list, int len, int id, char name[]);

/// \fn int modifyPassengerLastName(Passenger*, int, int, char[])
/// \brief modifies the last name of the element from the id matching the id of the parameter.
/// \param list
/// \param len
/// \param id
/// \param lastName
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modifyPassengerLastName(Passenger* list, int len, int id, char lastName[]);

/// \fn int modifyTypePassenger(Passenger*, int, int, int)
/// \brief modifies the type of the element from the id matching the id of the parameter.
/// \param list
/// \param len
/// \param id
/// \param typePassenger
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modifyTypePassenger(Passenger* list, int len, int id, int typePassenger);

/// \fn int modifyPassengerPrice(Passenger*, int, int, float)
/// \brief modifies the price of the element from the id matching the id of the parameter.
/// \param list
/// \param len
/// \param id
/// \param price
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modifyPassengerPrice(Passenger* list, int len, int id, float price);

/// \fn int modifyPassengerFlycode(Passenger*, int, int, char[])
/// \brief modifies the fly code of the element from the id matching the id of the parameter.
/// \param list
/// \param len
/// \param id
/// \param flycode
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int modifyPassengerFlycode(Passenger* list, int len, int id, char flycode[]);

#endif /* ARRAYPASSENGER_H_ */
