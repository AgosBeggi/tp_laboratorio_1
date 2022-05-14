/*
 * ArrayStatus.h
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#ifndef ARRAYSTATUS_H_
#define ARRAYSTATUS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENTS 1000

#define EMPTY 0
#define ACTIVE 1
#define DELAYED 2
#define RESCHEDULED 3
#define CANCELLED 4

typedef struct{
	char flycode[10];
	int statusFlight;
}Status;

//INICIALIZACIÓN
/// \fn int initStatus(Status*, int)
/// \brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initStatus(Status* status_list, int lenStatus);

//BUSQUEDA
/// \fn int findStatusByCode(Status*, int, char[])
/// \brief find a element by code and returns the index position in array.
/// \param status_list
/// \param lenStatus
/// \param flycode
/// \return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or status not found]
int findStatusByCode(Status* status_list, int lenStatus, char flycode[]);

/// \fn int findStatusEmpty(Status*, int)
/// \brief find the first position empty, returns the index position in array.
/// \param status_list
/// \param lenStatus
/// \return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int findStatusEmpty(Status* status_list, int lenStatus);

//AGREGAR
/// \fn int addStatus(Status*, int, char[])
/// \brief add in a existing list of status the values received as parameters
/// in the first empty position.
/// \param status_list
/// \param lenStatus
/// \param flycode
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without
///free space] - (0) if Ok
int addStatus(Status* status_list, int lenStatus, char flycode[]);

//MODIFICACIONES
/// \fn int changeStatus(Status*, int, int, char[])
/// \brief modifies the name of the element from the id matching the id of the parameter.
/// \param status_list
/// \param lenStatus
/// \param statusFlight
/// \param flycode
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int changeStatus(Status* status_list, int lenStatus, int statusFlight, char flycode[]);

//REPORTAR
/// \fn int printStatusList(Status*, int)
/// \brief print the content of passengers array.
/// \param status_list
/// \param lenStatus
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printStatusList(Status* status_list, int lenStatus);

/// \fn int printStatus(Status)
/// \brief print the content of a single element of the array.
/// \param status
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int printStatus(Status status);

//SUPRIMIR
/// \fn int deleteStatus(Status*, int, char[])
/// \brief Remove a element by Id (put isEmpty Flag in 1)
/// \param status_list
/// \param lenStatus
/// \param flycode
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int deleteStatus(Status* status_list, int lenStatus, char flycode[]);

#endif /* ARRAYSTATUS_H_ */
