#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    int cantidad;
    char buffer[4][128];

    Employee* pEmp;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
           cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

             if(cantidad == 4)
             {
                pEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListEmployee, pEmp);
             }
              else
               {
                 break;
               }
        }
        todoOk = 0;
    }

    return todoOk;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    Employee* pEmp;

    if(pFile != NULL)
    {
        do
        {
			pEmp = employee_new();
			if(fread(pEmp, sizeof(Employee), 1, pFile) == 1)
            {
				ll_add(pArrayListEmployee, pEmp);
				todoOk = 0;
			}
		}while(!feof(pFile));
	}

    return todoOk;
}
