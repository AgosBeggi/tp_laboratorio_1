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

#define CANCELLED -1
#define EMPTY 0
#define ACTIVE 1
#define DELAYED 2
#define RESCHEDULED 3

typedef struct{
	char flycode[10];
	int statusFlight;
}Status;

int initStatus(Status* status_list, int lenStatus);

int findStatusById(Status* status_list, int lenStatus, char flycode[]);

int addStatus(Status* status_list, int lenStatus, char flycode[]);

int findStatusEmpty(Status* status_list, int lenStatus);

int printStatus(Status* status_list, int lenStatus);

void print_A_Status(Status status);

#endif /* ARRAYSTATUS_H_ */
