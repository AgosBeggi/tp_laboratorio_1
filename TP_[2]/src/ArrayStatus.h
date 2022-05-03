/*
 * ArrayStatus.h
 *
 *  Created on: 27 abr. 2022
 *      Author: BEGGI A.
 */

#ifndef ARRAYSTATUS_H_
#define ARRAYSTATUS_H_

#include <stdio.h>
#include <string.h>

#define ELEMENTS 1000


#define EMPTY 0
#define ACTIVE 1
#define DELAYED 2
#define RESCHEDULED 3
#define CANCELLED 4

typedef struct{
	int id_status;
	char flycode[10];
	int statusFlight;
}Status;

int initStatus(Status* status_list, int lenStatus);

int findStatusById(Status* status_list, int lenStatus, int id_status);

int addStatus(Status* status_list, int lenStatus, char flycode[], int id_status);

int findStatusEmpty(Status* status_list, int lenStatus);

int changeStatus(Status* status_list, int lenStatus, int id_status, int statusFlight);

int printStatusList(Status* status_list, int lenStatus);

int printStatus(Status status);

int deleteStatus(Status* status_list, int lenStatus, int id_status);

#endif /* ARRAYSTATUS_H_ */
