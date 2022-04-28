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

#define EMPTY 0
#define FULL 1
#define ELEMENTS 1000

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
/// @fn int initEmployees(Passenger*, int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array.
/// @param list Passenger*
/// @param len
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(Passenger* list, int len);

//AGREGAR
/// @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[])
/// @brief add in a existing list of passengers the values received as parameters
/// in the first empty position
/// @param list Passenger*
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without
///free space] - (0) if Ok
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[], float price, int typePassenger, char flycode[]);

//BUSQUEDA
/// @fn int findPassengerById(Passenger*, int, int)
/// @brief find a Passenger by Id en returns the index position in array.
/// @param list Passenger*
/// @param len
/// @param id
/// @return  Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int findPassengerById(Passenger* list, int len,int id);

//ESTA FUNCION ES MIA AGREGADA AL ARRAY DE EMPLEADOS
// /// @fn int findEmployeeByEmpty(Employee*, int)
// /// @brief find the first position empty, returns the index position in array.
// /// @param list
// /// @param len
// /// @return Return index position or (-1) if [Invalid length or NULL
// /// pointer received or employee not found]
//int findEmployeeByEmpty(Employee* list, int len);
int findPassengerEmpty(Passenger* list, int len);

//SUPRIMIR
/// @fn int removePassenger(Passenger*, int, int)
/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
/// @param list Passenger*
/// @param len
/// @param id
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can't
/// find a passenger] - (0) if Ok
int removePassenger(Passenger* list, int len, int id);

//MODIFICAR ESTÁN CREADAS POR MI EN EL ARRAY DE EMPLEADOS
//int modifyEmployeeName(Employee* list, int len, int id, char name[]);
//
//int modifyEmployeeLastName(Employee* list, int len, int id, char lastName[]);
//
//int modifyEmployeeSector(Employee* list, int len, int id, int sector);
//
//int modifyEmployeeSalary(Employee* list, int len, int id, float salary);

//ORDENAR
//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
/// @fn int sortEmployees(Employee*, int, int)
/// @brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order
/// @param list Passenger*
/// @param len
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengers(Passenger* list, int len, int order);

//agregadas a esta biblio para este tp
/// @fn int sortPassengersByCode(Passenger*, int, int)
/// @brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order
/// @param list Passenger*
/// @param len
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int
int sortPassengersByCode(Passenger* list, int len, int order);

//INFORMES
/// @fn int printPassenger(Passenger*, int)
/// @brief print the content of passengers array
/// @param list Passenger*
/// @param length
/// @return int
int printPassenger(Passenger* list, int length);

void printPassengers(Passenger passenger);

int modifyPassengerName(Passenger* list, int len, int id, char name[]);

int modifyPassengerLastName(Passenger* list, int len, int id, char lastName[]);

int modifyPassengerTypePassenger(Passenger* list, int len, int id, int typePassenger);

int modifyPassengerPrice(Passenger* list, int len, int id, float price);

int modifyPassengerFlycode(Passenger* list, int len, int id, char flycode[]);

#endif /* ARRAYPASSENGER_H_ */
