#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/mascotas.h"
#include "../inc/controller.h"
#include "../inc/parser.h"
#include "../inc/menu.h"
#include "../inc/utn.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
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
                }
                while(confirma == 0);
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

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;
    Employee* pEmp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        fprintf(pFile, "ID  NOMBRE  HORAS SUELDO\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
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

int controller_createSubList(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int idInicio;
    int idFinal;
    LinkedList* subList;


    if(!(utn_getEntero(&idInicio, 1, "Ingrese desde que Id donde desea crear la sublista: ", "Error. Numero invalido.\n\n", 1, ll_len(pArrayListEmployee))))
    {
        if(!(utn_getEntero(&idFinal, 1, "Ingrese hasta que Id desea crear la sublista: ", "Error. Numero invalido\n\n", 1, ll_len(pArrayListEmployee))))
        {
            subList = ll_subList(pArrayListEmployee,idInicio,idFinal);
            controller_ListEmployee(subList);
            todoOk = 0;
        }
        ll_deleteLinkedList(subList);
    }
    return todoOk;
}

int controller_clearList(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    char confirma;

    printf("Confirma limpieza de la lista? s/n: ");
    fflush(stdin);
    scanf("%c", &confirma);

    if(confirma == 's' || confirma == 'S')
    {
        if(pArrayListEmployee != NULL)
        {
            ll_clear(pArrayListEmployee);
            printf("Limpieza finalizada.\n\n");
            todoOk = 0;
        }
        else
        {
            printf("Error. No se pudo limpiar la lista.\n\n");
        }
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

int controller_moveEmployee(LinkedList* pArrayListEmployee)
{
    char confirma;
    int id;
    int auxId;
    int ultimoId;
    int indice;
    int nuevoIndice;
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

        utn_getEntero(&id, 2, "Ingrese ID del empleado a mover: ", "Error, ese ID no existe.\n\n", 1, ultimoId);

        indice = employee_searchPosById(pArrayListEmployee, id);
        if(indice > -1)
        {
            employee_printEmployee(pArrayListEmployee);

            printf("Confirma el movimiento del empleado? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                pEmp = (Employee*) ll_pop(pArrayListEmployee, indice);
                controller_ListEmployee(pArrayListEmployee);

                if(utn_getEntero(&auxId, 2, "Luego de que id desea mover al empleado? ", "Error, ID invalido.\n\n", 1, ultimoId) == 0)
                {
                    nuevoIndice = employee_searchPosById(pArrayListEmployee, auxId);

                    if(nuevoIndice > -1)
                    {
                        ll_push(pArrayListEmployee, nuevoIndice+1, pEmp);
                        todoOk = 0;
                        printf("Movimiento de empleado realizado\n\n");
                    }
                    else
                    {
                        printf("Error, ese ID no existe.\n\n");
                        ll_push(pArrayListEmployee, indice, pEmp);
                    }
                }
                else
                {
                    ll_push(pArrayListEmployee, indice, pEmp);;
                }
            }
        }
        else
        {
            printf("Error, ese ID no existe.\n\n");
        }
    }
    return todoOk;
}


int controller_saveCopy(char* path,LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    char auxNombre[20];
    int auxId;
    int auxHoras;
    int auxSueldo;
    int todoOk = -1;

    Employee* pEmp;
    LinkedList* pArrayListSaveCopy = ll_newLinkedList();

    pFile = fopen(path, "w");

    if(pArrayListSaveCopy != NULL)
    {
        pArrayListSaveCopy = ll_clone(pArrayListEmployee);

        if(pFile != NULL  && ll_containsAll(pArrayListSaveCopy,pArrayListEmployee))
        {
            pFile = fopen(path, "w");
            fprintf(pFile,"ID   NOMBRE    HORAS   SUELDO\n");
            for(int i = 0; i < ll_len(pArrayListSaveCopy); i++)
            {
                pEmp = ll_get(pArrayListSaveCopy, i);

                if((employee_getId(pEmp, &auxId) == 0) &&
                        (employee_getNombre(pEmp, auxNombre) == 0) &&
                        (employee_getHorasTrabajadas(pEmp, &auxHoras) == 0) &&
                        (employee_getSueldo(pEmp, &auxSueldo) == 0))
                {

                    fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
                    todoOk = 0;
                }
            }
            fclose(pFile);
            printf("Copia guardada.\n\n");
            ll_deleteLinkedList(pArrayListSaveCopy);
        }
    }
    else
    {
        printf("Hubo un error\n\n");
    }
    return todoOk;
}
