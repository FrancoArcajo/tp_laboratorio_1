#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char confirma = 'n';
    char opcion = 'n';
    int flagText = 0;
    int flagBin = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

   do
    {
    	system("cls");

        switch(menu())
        {
            case 1:
            	if(flagBin != 1 && flagText == 0)
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{
						flagText = 1;
					}
            	}
            	else
				{
					printf("El archivo ya fue cargado.\n");
				}
                break;
            case 2:
            	if(flagText != 1 && flagBin == 0)
            	{
            		if(!controller_loadFromBinary("data.bin", listaEmpleados))
            		{
                      flagBin = 1;
            		}
            	}
            	else
            	{
                  printf("El archivo ya fue cargado.\n");
            	}
            	break;
            case 3:
            	if(flagText == 1 || flagBin == 1)
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Primero hay que cargar un archivo.\n");
            	}
            	break;
            case 4:
            	if(flagText == 1 || flagBin == 1)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 5:
            	if(flagText == 1 || flagBin == 1)
				{
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 6:
            	if(flagText == 1 || flagBin == 1)
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 7:
            	if(flagText == 1 || flagBin == 1)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
				break;
            case 8:
            	if(flagText == 1 || flagBin == 1)
            	{
            	    printf("Archivo en texto guardados\n\n");
            		controller_saveAsText("data.csv", listaEmpleados);
            	}
            	else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 9:
            	if(flagText == 1 || flagBin == 1)
            	{
            	    printf("Archivo en binario guardados\n\n ");
            		controller_saveAsBinary("data.bin", listaEmpleados);
            	}
            	else
				{
					printf("Error. Primero hay que cargar un archivo\n");
				}
            	break;
            case 10:
            	printf("Confirma salir? s/n: ");
            	fflush(stdin);
            	scanf("%c", &confirma);

            	if(confirma == 's')
            	{
            		opcion = 's';
            		ll_deleteLinkedList(listaEmpleados);
            	}
            	break;
        }

        system("pause");

    }while(opcion == 'n');

    return 0;
}
