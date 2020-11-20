#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_updateId(LinkedList* pArrayListEmployee);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_searchPosById(LinkedList* pArrayListEmployee, int id);
void employee_printEmployee(LinkedList* pArrayListEmployee);

int employee_compareId(void* employeeA, void* employeeB);
int employee_compareName(void* employeeA, void* employeeB);
int employee_compareHoursWorked(void* employeeA, void* employeeB);
int employee_compareSalary(void* employeeA, void* employeeB);

int employee_modifyName(LinkedList* pArrayListEmployee, int indice);
int employee_modifyHoursWorked(LinkedList* pArrayListEmployee, int indice);
int employee_modifySalary(LinkedList* pArrayListEmployee, int indice);


#endif // employee_H_INCLUDED
