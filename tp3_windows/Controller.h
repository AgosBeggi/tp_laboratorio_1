#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input.h"

#define LEER_TEXTO "r"
#define LEER_BIN "rb"
#define ESCRIBIR_TEXTO "w"
#define ESCRIBIR_BIN "wb"

/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
/// \param path
/// \param pArrayListEmployee
/// \return int
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
/// \param path
/// \param pArrayListEmployee
/// \return int
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// \fn int controller_addEmployee(LinkedList*)
/// \brief Alta de empleados
/// \param pArrayListEmployee
/// \return int
int controller_addEmployee(LinkedList* pArrayListEmployee);

Employee* controller_Datos_Employee(void);

Employee* controller_Edit_Employee(void);

/// \fn int controller_editEmployee(LinkedList*)
/// \brief Modificar datos de empleado
/// \param pArrayListEmployee
/// \return int
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_removeEmployee(LinkedList*)
/// \brief Baja de empleado
/// \param pArrayListEmployee
/// \return int
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_ListEmployee(LinkedList*)
/// \brief Listar empleados
/// \param pArrayListEmployee
/// \return int
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_sortEmployee(LinkedList*)
/// \brief Ordenar empleados
/// \param pArrayListEmployee
/// \return int
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
/// \param path
/// \param pArrayListEmployee
/// \return int
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
/// \param path
/// \param pArrayListEmployee
/// \return int
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


