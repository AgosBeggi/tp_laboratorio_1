#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define EMPTY 0

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// \fn Employee employee_new*()
/// \brief Reserva espacio en memoria, verifica que lo haya encontrado
/// e inicializa un empledo en EMPTY.
/// \return Retorna un puntero de tipo Employee.
Employee* employee_new();
/// \fn Employee employee_newParametros*(char*, char*, char*, char*)
/// \brief Llame a la función employee_new(); para guardar en ese espacio de memoria
/// los datos que obtiene por parámetros, previamente parseados.
/// \param idStr
/// \param nombreStr
/// \param horasTrabajadasStr
/// \param sueldoStr
/// \return Retorna un puntero de tipo Employee.
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

//AGREGAR ESTA AL DESARROLLO
void employee_delete(Employee*);

/// \fn int employee_setId(Employee*, int)
/// \brief Verifica que el puntero recibido sea distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param id
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_setId(Employee* this,int id);
/// \fn int employee_getId(Employee*, int*)
/// \brief Verifica que los punteros recibidos sean
/// distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param id
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_getId(Employee* this,int* id);

/// \fn int employee_setNombre(Employee*, char*)
/// \brief Verifica que el puntero recibido sea distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param nombre
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_setNombre(Employee* this,char* nombre);
/// \fn int employee_getNombre(Employee*, char*)
/// \brief erifica que los punteros recibidos sean
/// distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param nombre
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_getNombre(Employee* this,char* nombre);

/// \fn int employee_setHorasTrabajadas(Employee*, int)
/// \brief Verifica que el puntero recibido sea distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param horasTrabajadas
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/// \fn int employee_getHorasTrabajadas(Employee*, int*)
/// \brief Verifica que los punteros recibidos sean
/// distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param horasTrabajadas
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// \fn int employee_setSueldo(Employee*, int)
/// \brief Verifica que el puntero recibido sea distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param sueldo
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_setSueldo(Employee* this,int sueldo);
/// \fn int employee_getSueldo(Employee*, int*)
/// \brief Verifica que los punteros recibidos sean
/// distinto de NULL, y asigna el valor
/// del dato pasado por parámetro al puntero.
/// \param this
/// \param sueldo
/// \return Retorna un entero. 0 para falso, 1 para verdadero.
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
