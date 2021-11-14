#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){

	//DECLARO UN PUNTERO A ARCHIVO
	FILE* pArchivo;

	int estado;
	int retorno;

	retorno = 0;

	//ABRIR ARCHIVO
	pArchivo = fopen(path, LEER_TEXTO);

	//VERIFICO QUE EL PUNTERO A ARCHIVO SEA DISTINTO DE NULL
	if(pArchivo != NULL){
		estado = parser_EmployeeFromText(pArchivo, pArrayListEmployee);
	}

	//FERIFICO EL RETORNO OK DE LA FUNCIÓN ANTERIOR
	if(estado == 1){
		//FCLOSE RETORNA 0 PARA OK
		fclose(pArchivo);
		retorno = 1;
	}

	return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
	//DECLARO UN PUNTERO A ARCHIVO
	FILE* pArchivo;

	int estado;
	int retorno;

	retorno = 0;

	//PUTS DE VERIFICACION
	puts("entro a control");

	//CREAR ARCHIVO BIN
	pArchivo = fopen(path, ESCRIBIR_BIN);
	fclose(pArchivo);
	//ABRIR ARCHIVO
	pArchivo = fopen(path, LEER_BIN);

	//VERIFICO QUE EL PUNTERO A ARCHIVO SEA DISTINTO DE NULL
	if(pArchivo != NULL){
		estado = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
	}

	//FERIFICO EL RETORNO OK DE LA FUNCIÓN ANTERIOR
	if(estado == 1){
		//FCLOSE RETORNA 0 PARA OK
		fclose(pArchivo);
		retorno = 1;
	}

	return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee){

	int estado;
	int retorno;

	Employee* unEmpleado;

	retorno = 0;

	unEmpleado = controller_Datos_Employee();

	estado = ll_add(pArrayListEmployee, (Employee*) unEmpleado);

	if(estado == 0){
		retorno = 1;
	}

    return retorno;
}

Employee* controller_Datos_Employee(void){

	char id[51];
	char nombre[128];
	char horas[51];
	char sueldo[51];
	Employee* unEmpleado;

	Get_String(id, 51, "Ingrese el id");
	Get_String(nombre, 128, "Ingrese el nombre");
	Get_String(horas, 51, "Ingrese las horas trabajadas");
	Get_String(sueldo, 51, "Ingrese el sueldo");

	unEmpleado = employee_newParametros(id, nombre, horas, sueldo);

	return unEmpleado;
}


int controller_editEmployee(LinkedList* pArrayListEmployee){

	int pNumber;
	//int retorno;
	int* index;

	Employee* pEmpleado;
	//Employee* aux;
	Get_A_Number_Int("Ingrese el id del empleado a modificar.\n", &pNumber);
	printf("id %d\n", pNumber);

	//SE FIJA SI EL ELEMENTO QUE SE LE PASA POR PARAMETRO ESTÁ INCLUÍDO EN LA LISTA
	//if(ll_contains(pArrayListEmployee, (int*) pNumber) == 0){

		//DEVUELVE EL DATO QUE ESTÁ GUARDADO EN ESE INDICIE DE LA LISTA.
		pEmpleado = (Employee*)ll_get(pArrayListEmployee, pNumber-1);
		printf("id %d\n", pNumber);
		printf("datos %d %s %d %d\n", pEmpleado->id, pEmpleado->nombre, pEmpleado->horasTrabajadas, pEmpleado->sueldo);
		//DEVUELVE EL INDICE DEL DATO QUE SE QUIERE ENCONTRAR, PASANDOLE EL PUNTERO A ESE DATO
		index = ll_indexOf(pArrayListEmployee, (Employee*) pEmpleado);
		printf("index %d\n", index);
	//}

	//GUARDAR ELEMENTO
	int ll_add(LinkedList* this, void* pElement);

    return 1;
}

Employee* controller_Edit_Employee(void){

	char id[51];
	char nombre[128];
	char horas[51];
	char sueldo[51];
	int* pNumber;
	Employee* unEmpleado;

	puts("Ingrese una opción: \n");
	puts("1. Modificar nombre.");
	puts("2. Modificar horas.");
	puts("3. Modificar sueldo.");

	Get_A_Number_Int("", pNumber);

	/*switch(pNumber){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
	}*/

	Get_String(nombre, 128, "Ingrese el nombre");
	Get_String(horas, 51, "Ingrese las horas trabajadas");
	Get_String(sueldo, 51, "Ingrese el sueldo");

	unEmpleado = employee_newParametros(id, nombre, horas, sueldo);

	return unEmpleado;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
