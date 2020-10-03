#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

int initEmployees(eEmpleado empleados[], int tam) {

int error = 1;

    if(empleados != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            empleados[i].isEmpty = 1;
        }
         error = 0;
    }

    return error;
}

int menu()
{
    int opcion;
    system("cls");

    printf(" ** ABM Empleados ** \n\n");
    printf("1) Alta\n");
    printf("2) Modificar\n");
    printf("3) Baja\n");
    printf("4) Informar\n");
    printf("5) Salir\n\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado empleados[], int tam) {
  int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int addEmployees(eEmpleado empleados[], int tam, int id) {

int error = 1;
int indice;
eEmpleado nuevoEmpleado;

    if(empleados != NULL && tam > 0)
    {
            system("cls");
            printf("  *** Alta Empleado ***\n\n");

        indice = buscarLibre(empleados, tam);

        if(indice == -1)
        {

            printf("Sistema Completo.\n");

        }  else
          {

            nuevoEmpleado.id = id;
            nuevoEmpleado.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
            printf("Ingrese salario: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.salario);
            printf("Ingrese sector: ");
            scanf("%d", &nuevoEmpleado.sector);

            empleados[indice] = nuevoEmpleado;

            error = 0;
        }
   }
    return error;
}

int findEmployeeById(eEmpleado empleados[], int tam, int id) {

    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].id == id && !empleados[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int removeEmployee(eEmpleado empleados[], int tam) {

int id;
int indice;
int error = 1;
char confirma;

    if(empleados != NULL && tam > 0){
        system("cls");
        printf("  *** Baja de Empleado *** \n\n");

        printEmployees(empleados,tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findEmployeeById(empleados, tam, id);

     if(indice == -1)
      {
            printf("No hay ninguna persona con ese id\n");
      } else
         {
           printEmployee(empleados[indice]);
           printf("Confirma baja? ");
           fflush(stdin);
           scanf("%c", &confirma);
           if(confirma == 's')
           {

           empleados[indice].isEmpty = 1;
           error = 0;

           } else
              {
              error = 2;
              }
  }
}
  return error;
}

int sortEmployees(eEmpleado empleados[], int tam, int criterio) {

eEmpleado auxEmpleado;
int error = 1;

if(empleados != NULL && tam > 0){
for (int i=0; i < tam-1; i++)
{
    for (int j= i+1; j < tam; j++)
    {
        // Me tira un warning en esta linea aunque tengo la biblioteca <string.h> no se si es problema de mi codeblock o mi computadora
        if (criterio == 1 && (stricmp(empleados[i].apellido, empleados[j].apellido) > 0 || (empleados[i].sector > empleados[j].sector)))
         {
            auxEmpleado = empleados[i];
            empleados[i] = empleados[j];
            empleados[j] = auxEmpleado;
         }
        else if (criterio == 0 && (stricmp(empleados[i].apellido, empleados[j].apellido) < 0 || (empleados[i].sector < empleados[j].sector)))
         {
           auxEmpleado = empleados[i];
           empleados[i] = empleados[j];
           empleados[j] = auxEmpleado;
         }
    }
}
    error = 0;
 }
return error;
}

int printEmployees(eEmpleado empleados[], int tam){

    int flag = 0;
    int error = 1;

    if(empleados != NULL && tam > 0)
    {
            //system("cls");
            printf("  Id                    Nombre             Apellido       Salario    Salario \n");
        for(int i = 0; i < tam; i++)
        {
            if(!empleados[i].isEmpty)
            {
                printEmployee(empleados[i]);
                flag = 1;
            }
        }
            if(!flag)
            {
            printf("    No hay personas en la lista\n");
            }

          printf("\n\n");
          error = 0;
    }
    return error;
}

void printEmployee(eEmpleado empleado){
     printf("  %4d   %20s    %20s   %.2f  %d \n",empleado.id,empleado.nombre,empleado.apellido,empleado.salario, empleado.sector);
}

int modificarEmpleado(eEmpleado empleados[], int tam) {

int id;
int opcion;
int indice = 0;
int error = 1;
char confirma;
eEmpleado auxEmpleado;

    if(empleados != NULL && tam > 0)
    {
        printEmployees(empleados,tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findEmployeeById(empleados, tam, id);
        auxEmpleado = empleados[indice];
    }
if(indice == -1)
{
  printf("No hay ninguna persona con ese id\n");
}
  else
    {
          printf("  *** Modificar Empleado *** \n\n");
          printf("1. Modificar Nombre\n");
          printf("2. Modificar Apellido\n");
          printf("3. Modificar salario\n");
          printf("4. Modificar sector\n");
          printf("5. Salir\n");
          printf("Seleccione una opcion: ");
          scanf("%d", &opcion);
          switch(opcion)
          {
            case 1:
            printf("Ingrese nuevo nombre");
            fflush(stdin);
            gets(auxEmpleado.nombre);
            break;
            case 2:
            printf("Ingrese nuevo apellido");
            fflush(stdin);
            gets(auxEmpleado.apellido);
            break;
            case 3:
            printf("Ingrese nuevo sector: ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.sector);
            break;
            case 4:
            printf("Ingrese nuevo salario: ");
            fflush(stdin);
            scanf("%f", &auxEmpleado.salario);
            break;
        default:
            printf("Ingrese un caracter valido\n\n");
        }

         printf("Realmente quiere modificarlo?: ");
         fflush(stdin);
         scanf("%c", &confirma);
            if (confirma == 's')
            {
              //me tira un warning y no entiendo porque
              empleados[indice] = auxEmpleado;
              error = 0;
            }
             else
             {
                 printf("Modificacion cancelada");
             }
    }
      return error;
}

void informarSalario (eEmpleado empleados[], int tam){

float acumTotal = 0;
float promedio;
int contTotal = 0;
int contSuperan = 0;

if(empleados != NULL && tam > 0)
{
  for (int i = 0; i < tam; i++)
   {
    if(empleados[i].isEmpty == 0)
    {
        acumTotal = acumTotal + empleados[i].salario;
        contTotal++;
    }
   }

promedio = acumTotal / contTotal;

for(int i=0; i < tam; i++)
{
    if(empleados[i].isEmpty == 0 && empleados[i].salario > promedio)
    {
      contSuperan++;
    }
}
system("cls");
printf("** INFORMES SALARIOS **");
printf("El total de todos los salarios es de: %.2f\n",acumTotal);
printf("El promedio de los salarios es de: %0.2f\n", promedio);
printf("La cantidad de empleados que superan el salario promedio es de: %d\n", contSuperan);
   }
}
