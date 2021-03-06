/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/controller.h"
#include "../inc/employee.h"
#include "../inc/menu.h"


int main()
{
    char confirma = 'n';
    char opcion = 'n';

    LinkedList* listaEmpleados = ll_newLinkedList();

   do
    {
    	system("cls");

        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	if(!ll_isEmpty(listaEmpleados))
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Error. Primero hay que cargar un archivo.\n");
            	}
            	break;
            case 3:
            	if(!ll_isEmpty(listaEmpleados))
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 4:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 5:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 6:
            	if(!ll_isEmpty(listaEmpleados))
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
				break;
				 case 7:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		controller_clearList(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            	 case 8:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		controller_createSubList(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            	case 9:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		controller_moveEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            	 case 10:
            	if(!ll_isEmpty(listaEmpleados))
				{
            		controller_saveCopy("dataCopia.csv", listaEmpleados);
				}
				else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 11:
            	if(!ll_isEmpty(listaEmpleados))
            	{
            	    printf("Archivo en texto guardados\n\n");
            		controller_saveAsText("data.csv", listaEmpleados);
            	}
            	else
				{
					printf("Error. Primero hay que cargar un archivo.\n");
				}
            	break;
            case 12:
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



/*int main(void)
{
        startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort
    return 0;
}*/
































