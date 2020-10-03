#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

# define TAM  1000

int main()
{
    char confirmacion;
    char seguir = 's';
    int proximoId = 1;
    eEmpleado lista[TAM];
    int rta;
    int flagAlta = 0;
    int opcion;


    if(!initEmployees(lista, TAM))
    {

        printf("Inicializacion exitosa!\n");
    }
      else
        {
          printf("Fallo al inicializar");
        }
    do
    {
    switch(menu())
        {
        case 1:
            if(!addEmployees(lista, TAM, proximoId))
            {
              proximoId++;
              printf("Alta exitosa.\n");
              flagAlta = 1;
            }
            else
            {
                printf("No se pudo realizar el alta.");

            }

        break;

        case 2:
            if(flagAlta == 1)
            {
               rta = modificarEmpleado(lista, TAM);
            if (rta == 0)
            {
                printf("Se ha modificado con exito!!!\n\n");
            }
            else if (rta == 2)
            {
                printf("Modificacion cancelada por el usuario...\n\n");
            }
            else
            {
               printf("Hubo un problema al intentar realizar la modificacion...\n\n");
            }
            }
             else
              {
                printf("Primero debe realizar el alta\n");
              }
        break;

        case 3:
            if (flagAlta == 1 ) {
            rta = removeEmployee(lista, TAM);
            if (rta == 0)
            {
                printf("Se ha realizado la baja con exito!!!\n\n");
            }
            else if (rta == 2)
                {
                 printf("Baja cancelada por el usuario...\n\n");
                }
            else {
                   printf("Hubo un problema al intentar realizar la baja...\n\n");
                 }
            }
            else
            {
                printf("Primero debe realizar el alta\n");
            }

            break;

        case 4:
           if (flagAlta == 1)
            {
                system("cls");
                printf("** INFORMAR **\n\n");
                printf("1) Lista de empleados\n");
                printf("2) Informe de salario\n");
                printf("Ingrese una opcion: ");
                fflush(stdin);
                scanf("%d", &opcion);
                if(opcion == 1 && !sortEmployees(lista, TAM, 1 ))
                {
                printEmployees(lista, TAM);
                }
                else if (opcion == 2 && !sortEmployees(lista, TAM, 1))
                {
                 informarSalario (lista, TAM);
                }
                else
                {
                     printf("Opcion invalida.\n");
                }
            }
               else
                {
                printf("Primero debe realizar el alta\n");
                }

         break;
        case 5:
            printf("Realmente quiere salir?\n");
            fflush(stdin);
            scanf("%c",&confirmacion);
            if(confirmacion == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Ingrese un caracter valido\n\n");
        }
        system("pause");

} while(seguir == 's');

    return 0;
}

