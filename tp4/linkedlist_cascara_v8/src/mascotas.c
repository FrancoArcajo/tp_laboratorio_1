#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/mascotas.h"
#include "../inc/controller.h"
#include "../inc/menu.h"
#include "../inc/utn.h"

Employee* employee_new()
{

	Employee* this = (Employee*) malloc(sizeof(Employee));

	if(this != NULL)
	{
      employee_setId(this, 0);
      employee_setNombre(this, "");
      employee_setHorasTrabajadas(this, 0);
      employee_setSueldo(this, 0);
	}
	return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();

		if(this != NULL)
		{
          employee_setId(this,atoi(idStr));
          employee_setNombre(this,nombreStr);
          employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
          employee_setSueldo(this,atoi(sueldoStr));
		}

		return this;
}

int employee_delete(Employee* this)
{
   int todoOk = -1;

   if(this != NULL)
    {
      free(this);
      this = NULL;
      todoOk = 0;
    }
    return todoOk;
}

int employee_setId(Employee* this,int id)
{
    int todoOk = -1;

    if(this != NULL && id >= 0)
    {
      this ->id = id;
      todoOk = 0;
    }

     return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = -1;

     if(this != NULL && id != NULL)
    {
        *id = this ->id;
        todoOk = 0;
    }
    return todoOk;

}

int employee_updateId(LinkedList* pArrayListEmployee)
{
	int auxId;
	int proximoId = 0;
	int flag = 0;

    Employee* pEmp;

	if(pArrayListEmployee != NULL)
	{
		for(int i=0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmp = (Employee*) ll_get(pArrayListEmployee,i);
			employee_getId(pEmp, &auxId);

			if(auxId > proximoId || flag == 0)
			{
			    proximoId = auxId;
			    flag = 1;
			}
        }
	}
	return proximoId;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = -1;

    if(this != NULL && nombre != NULL)
    {
        if(strlen(nombre) > 0)
        {
            strcpy(this ->nombre,nombre);
            todoOk = 0;
        }
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = -1;

     if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this ->nombre);
        todoOk = 0;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = -1;

    if(this != NULL && horasTrabajadas >= 0 )
    {
       this ->horasTrabajadas = horasTrabajadas;
       todoOk = 0;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = -1;

     if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this ->horasTrabajadas ;
        todoOk = 0;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = -1;

    if(this != NULL && sueldo >= 0)
    {
      this ->sueldo = sueldo;
       todoOk = 0;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = -1;

     if(this != NULL && sueldo != NULL)
    {
        *sueldo = this ->sueldo ;
        todoOk = 0;
    }
    return todoOk;
}

void employee_printEmployee(LinkedList* pArrayListEmployee){

    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;

    Employee* pEmp = NULL;

    if(pArrayListEmployee != NULL){

        pEmp = employee_new();
        if(pEmp != NULL){

            printf("   ID                NOMBRE        HORAS      SUELDO\n\n");
            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                pEmp = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(pEmp, &auxId);
                employee_getNombre(pEmp, auxNombre);
                employee_getHorasTrabajadas(pEmp, &auxHorasTrabajadas);
                employee_getSueldo(pEmp, &auxSueldo);
                printf("%4d   %20s       %5d       %5d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            }
        }
    }
}

int employee_searchPosById(LinkedList* pArrayListEmployee, int id)
{
	int todoOk = -1;
	Employee* pEmp;

	for(int i=0; i < ll_len(pArrayListEmployee); i++)
	{
		pEmp = ll_get(pArrayListEmployee, i);

	  if(pEmp->id == id){
            todoOk = i;
            break;
        }
    }
    return todoOk;
}

int employee_compareName(void* employeeA, void* employeeB)
{
    int todoOk = 0;

    Employee* pEmp1;
    Employee* pEmp2;

    if(employeeA != NULL && employeeB != NULL)
    {
        pEmp1 = (Employee*)employeeA;
        pEmp2 = (Employee*)employeeB;

        todoOk = strcmp(pEmp1->nombre,pEmp2->nombre);

    }
    return todoOk;

}
int employee_compareSalary(void* employeeA, void* employeeB)
{
    int todoOk = 0;

    Employee* pEmp1;
    Employee* pEmp2;

    if(employeeA != NULL && employeeB != NULL)
    {
        pEmp1=(Employee*)employeeA;
        pEmp2=(Employee*)employeeB;

        if(pEmp1->sueldo > pEmp2->sueldo)
        {
            todoOk = 1;
        }
        else if(pEmp1->sueldo < pEmp2->sueldo)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
int employee_compareId(void* employeeA, void* employeeB)
{
    int todoOk = 0;

    Employee* pEmp1;
    Employee* pEmp2;

    if(employeeA != NULL && employeeB != NULL)
    {

        pEmp1 = (Employee*)employeeA;
        pEmp2 = (Employee*)employeeB;


        if(pEmp1->id > pEmp2->id)
        {
            todoOk = 1;
        }
        else if(pEmp1->id < pEmp2->id)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
int employee_compareHoursWorked(void* employeeA, void* employeeB)
{
    int todoOk = 0;

    Employee* pEmp1;
    Employee* pEmp2;

    if(employeeA != NULL && employeeB != NULL)
    {
        pEmp1 = (Employee*)employeeA;
        pEmp2 = (Employee*)employeeB;

        if(pEmp1->horasTrabajadas > pEmp2->horasTrabajadas)
        {
            todoOk = 1;
        }
        else if(pEmp1->horasTrabajadas < pEmp2->horasTrabajadas)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}


int employee_modifyName(LinkedList* pArrayListEmployee, int indice)
{
    int todoOk = -1;
	char auxNombre[128];

	Employee* pEmp;

	pEmp = ll_get(pArrayListEmployee, indice);

	if(utn_getCadena(auxNombre, 128, 2, "Ingrese nuevo nombre: ","\nError, nombre invalido.\n") == 0)
	{
		normalizeStr(auxNombre);
		employee_setNombre(pEmp, auxNombre);
		todoOk = 0;
	}

	return todoOk;
}

int employee_modifyHoursWorked(LinkedList* pArrayListEmployee, int indice)
{
    int todoOk = -1;
	int auxHoras;

	Employee* pEmp;

	pEmp = ll_get(pArrayListEmployee, indice);

	if(utn_getEntero(&auxHoras, 2, "Ingrese modificacion de horas trabajadas: ", "\nError, horas invalidas.\n", 0, 100000) == 0)
	{
		employee_setHorasTrabajadas(pEmp, auxHoras);
		todoOk = 0;
	}

	return todoOk;
}

int employee_modifySalary(LinkedList* pArrayListEmployee, int indice)
{
    int todoOk = -1;
	int auxSueldo;

	Employee* pEmp;

	pEmp = ll_get(pArrayListEmployee, indice);

	if(utn_getEntero(&auxSueldo, 2, "Ingrese nuevo sueldo: ", "\nError, sueldo invalido.\n", 10000, 300000) == 0)
	{
		employee_setSueldo(pEmp, auxSueldo);
		todoOk = 0;
	}

 return todoOk;
}
