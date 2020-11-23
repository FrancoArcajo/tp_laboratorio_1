/*#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief reserva memoria para una estructura de tipo empleado e inicializa los campos, retorna su posicion de memoria.
 * \param void
 * \return Employee* retorna el puntero a la estructura
 */
Employee* employee_new();

/** \brief reserva memoria para una estructura de tipo empleado e inicializa los campos, retorna su posicion de memoria.
 * \param es el Id generado para el nuevo empleado
 * \param es el nombre del nuevo empleado
 * \param es la cantidad de horas trabajadas
 * \param es el sueldo del empleado
 * \return Employee* retorna el puntero a la estructura
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Elimina un empleado.
 * \param puntero de la estructura de empleado
 * \return -1 en caso de error, 0 en caso  contrario.
 */

int employee_delete(Employee* this);

/**
 * \brief Valida y carga el id en el campo del empleado
 * \param this: puntero a empleado, id: id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_setId(Employee* this,int id);

/**
 * \brief Carga el id del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, id: puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_getId(Employee* this,int* id);

 /**
 * \brief Devuelve el id mas alto de la lista
 * \param LinkedList
 * \return -1 en caso de error, id mas alto en caso de exito
 */

int employee_updateId(LinkedList* pArrayListEmployee);
/**
 * \brief Valida y carga el nombre en el campo del empleado
 * \param this: puntero a empleado, nombre: nombre a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_setNombre(Employee* this,char* nombre);

/**
 * \brief Carga el nombre del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, nombre: cadena de caracteres en la que la funcion cargara el nombre
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_getNombre(Employee* this,char* nombre);

/**
 * \brief Valida y carga las horas trabajadas en el campo del empleado
 * \param this: puntero a empleado, horasTrabajadas: horas a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, horasTrabajadas: puntero a la variable en la que la funcion cargara las horas trabajadas
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * \brief Valida y carga el sueldo en el campo del empleado
 * \param this: puntero a empleado, sueldo: sueldo a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_setSueldo(Employee* this,int sueldo);

/**
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_getSueldo(Employee* this,int* sueldo);

/**
 * \brief Busca un empleado por id
 * \param LinkedList
 * \param id a buscar en la lista
 * \return -1 en caso de error, index del empleado en caso de exito
 */

int employee_searchPosById(LinkedList* pArrayListEmployee, int id);

/**
 * \brief Imprime un empleado
 * \param LinkedList
 */

void employee_printEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Compara los ids de dos empleados
 * \param puntero a primer empleado a comparar
 * \param puntero a segundo empleado a comparar
 * \return 1 si el id del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */

int employee_compareId(void* employeeA, void* employeeB);

/**
 * \brief Compara los nombres de dos empleados
 * \param puntero a primer empleado a comparar
 * \param puntero a segundo empleado a comparar
 * \return 0 si fue un exito
 */

int employee_compareName(void* employeeA, void* employeeB);

/**
 * \brief Compara las horas trabajadas de dos empleados
 * \param puntero a primer empleado a comparar
 * \param puntero a segundo empleado a comparar
 * \return 1 si las horas trabajadas del primer empleado son mas que las del segundo empleado, -1 si son menos y 0 si son iguales
 */

int employee_compareHoursWorked(void* employeeA, void* employeeB);

/**
 * \brief Compara los sueldos de dos empleados
 * \param puntero a primer empleado a comparar
 * \param puntero a segundo empleado a comparar
 * \return 1 si el sueldo del primer empleado es mas alto que el del segundo empleado, -1 si es mas bajo y 0 si son iguales
 */

int employee_compareSalary(void* employeeA, void* employeeB);

/**
 * \brief Modifica el nombre de un empleado
 * \param LinkedList
 * \param indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_modifyName(LinkedList* pArrayListEmployee, int indice);

/**
 * \brief Modifica las horas trabajadas de un empleado
 * \param LinkedList
 * \param indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_modifyHoursWorked(LinkedList* pArrayListEmployee, int indice);

/**
 * \brief Modifica el salario de un empleado
 * \param LinkedList
 * \param indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */

int employee_modifySalary(LinkedList* pArrayListEmployee, int indice);

#endif // MASCOTAS_H_INCLUDED*/
