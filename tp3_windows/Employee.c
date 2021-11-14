#include <stdio.h>

#include "Employee.h"

Employee* employee_new(){

	Employee* aux;
	Employee* unEmpleado;
	char aux_nombre[128] = "0";

	//RESERVO UN ESPACIO EN MEMORIA
	aux = (Employee*)malloc(sizeof(Employee));

	//VERIFICO SI ENCONTRÓ EL ESPACIO EN MEMORIA
	if(aux != NULL){
		//CARGO LA VARIABLE AUXILIAR CON VALOR VACÍO
		employee_setId(aux, EMPTY);
		employee_setNombre(aux, aux_nombre);
		employee_setHorasTrabajadas(aux, EMPTY);
		employee_setSueldo(aux, EMPTY);
		//LOS SETERS YA ESTÁN VERIFICADOS Y FUNCIOAN CORRECTAMENTE
		//POR ESO LE ASIGNO AL RETORNO LO QUE TIENE EL AUXILIAR
		unEmpleado = aux;
	}

	return unEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

	Employee* unEmpleado;
	int aux_id;
	int aux_horas;
	int aux_sueldo;

	//LLAMO A EMPLEADO NUEVO PARA RESERVAR ESPACIO EN MEMORIA
	unEmpleado = employee_new();
	//COMPRUEBO QUE LOS DATOS SEAN DISTINTOS DE NULL
	if(unEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL &&sueldoStr){

		//PARSEO LOS DATOS QUE CORRESPONDEN
		aux_id = atoi(idStr);
		aux_horas = atoi(horasTrabajadasStr);
		aux_sueldo = atoi(sueldoStr);

		//ASIGNO LOS VALORES QUE VA A GUARDAR LA VARIABLE DE ENTIDAD EMPLEADO
		employee_setId(unEmpleado, aux_id);
		employee_setNombre(unEmpleado, nombreStr);
		employee_setHorasTrabajadas(unEmpleado, aux_horas);
		employee_setSueldo(unEmpleado, aux_sueldo);
	}
	//RETORNO UN EMPLEADO CON LOS DATOS GUARDADOS
	return unEmpleado;
}

int employee_setId(Employee* this,int id){

	int retorno;

	retorno = 0;
	//VERIFICO QUE EL PUNTERO RECIBIDO NO SEA NULO
	if(this != NULL){
		//ASIGNO EL ID QUE RECIBO POR PARÁMETRO A LA ENTIDAD
		this->id = id;
		retorno = 1;
	}

	/*Por lo general los seters tienen reglas de negocio, entonces en esta funcion
	se podría preguntar por ejemplo, Si el id por parámetro es mayor a 1000, entonces recién ahí lo seteo
	agregando coneso un AND al if
	if(this != NULL && id > 1000)*/
	return retorno;
}

int employee_getId(Employee* this,int* id){

	int retorno;
	retorno = 0;

	//VERIFICO QUE LOS PUNTEROS RECIBIDOS NO SEAN NULO
	if(this != NULL && id != NULL){
		//ASIGNO EL ID QUE CONTIENE LA ENTIDAD AL PUNTERO RECIBIDO
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno;
	retorno = 0;

	if(this != NULL){
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre){

	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int retorno;
	retorno = 0;

	if(this != NULL){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

	int retorno;
	retorno = 0;

	if(this != NULL && horasTrabajadas != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){

	int retorno;
	retorno = 0;

	if(this != NULL){

		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){

	int retorno;
	retorno = 0;

	if(this != NULL && sueldo != NULL){
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

