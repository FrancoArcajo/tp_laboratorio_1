#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Controller.h"
#include "utn.h"
#include "menu.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = -1;

	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
		{
			printf("Archivo de texto cargado con exito\n");
			todoOk = 0;
		}
		else
		{
			printf("Error para cargar archivo\n");
        }
    }
	else
	{
		printf("Error para cargar archivo\n");
	}

	fclose(pFile);

    return todoOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
   	int todoOk = -1;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			todoOk = 0;
			printf("Archivo binario cargado con exito\n");
		}
		else
		{
          printf("Error al cargar archivo\n");
		}
	}
	else
	{
      printf("Error\n");
	}

	fclose(pFile);
    return todoOk;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    char auxNombre[127];
    int auxHorasTrabajadas;
    int auxSueldo;
    int ultimoId;

    Employee* pEmp = employee_new();

    if(pArrayListEmployee != NULL && pEmp!=NULL)
    {
        if(!utn_getCadena(auxNombre,127, 2,"Ingrese nombre: ","\nError, Nombre Invalido\n")
         && !utn_getEntero(&auxHorasTrabajadas, 2, "Ingrese horas trabajadas: ","\nError, Horas invalidoas(0 a 10000)\n",0,10000)
         && !utn_getEntero(&auxSueldo, 2, "Ingrese el sueldo: ","\nError, Valor invalido(10000 a 300000) \n",10000,300000))
        {
            normalizeStr(auxNombre);

            ultimoId = employee_updateId(pArrayListEmployee) + 1;

                   employee_setId(pEmp, ultimoId);
				   employee_setNombre(pEmp, auxNombre);
				   employee_setHorasTrabajadas(pEmp, auxHorasTrabajadas);
				   employee_setSueldo(pEmp, auxSueldo);

					ll_add(pArrayListEmployee, pEmp);
					printf("Alta exitosa\n");
					todoOk = 0;
        }
           else
           {
             employee_delete(pEmp);
           }
    }
    return todoOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int auxId;
	int ultimoId;
	int indice;
	int confirma = 0;
	int todoOk = -1;

    Employee* pEmp;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmp = ll_get(pArrayListEmployee, i);

			employee_getId(pEmp, &auxId);
			if(auxId >= ultimoId)
			{
				ultimoId = auxId;
			}
		}
		if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a modificar.\n", "Error, ID invalido\n", 0, ultimoId))
		{
			indice = employee_searchPosById(pArrayListEmployee, auxId);
			if(indice > -1)
			{
			    system("cls");
				printf("\n    ID       Nombre     Horas Trabajadas  Sueldo\n\n");

               do
				{
					switch(menuEdit())
					{
						case 1:
							if(employee_modifyName(pArrayListEmployee, indice) == 0)
							{
							    printf("Nombre modificado con exito\n");
							    system("pause");
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 2:
							if(employee_modifyHoursWorked(pArrayListEmployee, indice) == 0)
							{
								printf("Horas trabajadas modificadas con exito\n\n");
								system("pause");
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 3:

							if(employee_modifySalary(pArrayListEmployee, indice) == 0)
							{
								printf("Sueldo modificado con exito\n\n");
								system("pause");
							}
							else
							{
								printf("Error.\n");
							}
							break;
						case 4:
						    printf("Saliendo del programa\n\n");
							confirma = 1;
							break;
					}
				}while(confirma == 0);
			}
		}
	}
	return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char confirma;
	int auxId;
	int ultimoId;
	int indice;
	int todoOk = -1;

	Employee* pEmp;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		ultimoId = employee_updateId(pArrayListEmployee);

		if(!utn_getEntero(&auxId, 2, "Ingrese ID del empleado a eliminar.\n", "ID invalido", 0, ultimoId))
		{
			indice = employee_searchPosById(pArrayListEmployee, auxId);
			if(indice > -1)
			{
				pEmp = ll_get(pArrayListEmployee, indice);

				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");

				employee_printEmployee(pArrayListEmployee);

                printf("Confirma la baja? s/n: ");
				scanf("%c", &confirma);

				if(confirma == 's' || confirma == 'S')
				{
					ll_remove(pArrayListEmployee, indice);

					if(employee_delete(pEmp) == 0)
					{
						printf("Baja realizada.\n");
						todoOk = 0;
					}
				}
			}
		}
	}
    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
   Employee* pEmp = employee_new();

    if(pArrayListEmployee != NULL && pEmp != NULL)
    {
        employee_printEmployee(pArrayListEmployee);
    }

    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int orden;

    if(pArrayListEmployee != NULL)
    {

       printf("Menu de ordenamiento\n\n");
       opcion = menuSort();

        switch(opcion)
        {
        case 1:
            utn_getEntero(&orden, 2, "1 ASC o 0 DESC: ", "Error, ingrese 0 o 1\n", 0, 1);
            printf("\nLa lista esta siendo ordenada...\n");
            ll_sort(pArrayListEmployee, employee_compareId, orden);
             printf("\nLa lista ha sido ordenada con exito.\n");
            break;
        case 2:
            utn_getEntero(&orden, 2, "1 ASC o 0 DESC: ", "Error, ingrese 0 o 1\n", 0, 1);
            printf("\nLa lista esta siendo ordenada...\n");
            ll_sort(pArrayListEmployee, employee_compareName, orden);
             printf("\nLa lista ha sido ordenada con exito.\n");
            break;
        case 3:
            utn_getEntero(&orden, 2, "1 ASC o 0 DESC: ", "Error, ingrese 0 o 1\n", 0, 1);
            printf("\nLa lista esta siendo ordenada...\n");
            ll_sort(pArrayListEmployee, employee_compareHoursWorked, orden);
            printf("\nLa lista ha sido ordenada con exito.\n");
            break;
        case 4:
            utn_getEntero(&orden, 2, "1 ASC o 0 DESC: ", "Error, ingrese 0 o 1\n", 0, 1);
            printf("\nLa lista esta siendo ordenada...\n");
            ll_sort(pArrayListEmployee, employee_compareSalary, orden);
             printf("\nLa lista ha sido ordenada con exito.\n");
            break;
        case 5:
            break;
        default:
            printf("Opcion invalida\n\n");
            break;
        }
    }
    return opcion;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int len;

    FILE* pFile;
    Employee* pEmp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        fprintf(pFile, "ID  Nombre  HorasTrabajadas Sueldo\n");
        len = ll_len(pArrayListEmployee);

        for(int i=0; i < len; i++)
        {
            pEmp = (Employee*)ll_get(pArrayListEmployee, i);
            if(pEmp != NULL)
            {
                fprintf(pFile, "%d,%s,%d,%d\n", pEmp->id, pEmp->nombre, pEmp->horasTrabajadas, pEmp->sueldo);
            }
        }

        todoOk = 0;

        free(pEmp);
        fclose(pFile);
    }
    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = -1;

	FILE* pFile;
	Employee* pEmp;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i=0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmp = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmp, sizeof(Employee), 1, pFile);
		}

		printf("Archivo guardado con exito\n");
		fclose(pFile);

		todoOk = 0;
	}

    return todoOk;
}

