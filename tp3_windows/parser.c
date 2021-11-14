#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int estado;
	char aux_id[128];
	char aux_horas[128];
	char aux_sueldo[128];
	char aux_nombre[128];
	Employee* pEmpleado;

	retorno = 0;

	//HAGO UNA FALSA LECTURA PORQUE EL ARCHIVO TIENE ENCABEZADO
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_nombre, aux_horas, aux_sueldo);

	if(aux_id != NULL && aux_nombre != NULL && aux_horas != NULL && aux_sueldo != NULL){
		//RECORRO CADA LINEA DEL ARCHIVO HASTA ENCONTRAR EL FINAL
		while(!feof(pFile)){
			//LEO Y GUARDO LOS DATOS EN LAS VARIABLES
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", aux_id, aux_nombre, aux_horas, aux_sueldo);

			//LLAMO A CREAR UN EMPLEADO NUEVO CON PARÁMETROS
			pEmpleado = employee_newParametros(aux_id, aux_nombre, aux_horas, aux_sueldo);

			//LLAMO A AGREGAR UN EMPLEADO A LA LISTA
			estado = ll_add(pArrayListEmployee, (Employee*)pEmpleado);

			//COMPRUEBO QUE SE HAYA AGREGADO CORRECTAMENTE A LA LISTA (0 ES OK)
			if(estado == 0){
				//ASIGNO VALOR DE OK AL RETORNO
				retorno = 1;
			}
		}
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){

	return 1;
}

