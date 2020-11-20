#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "utn.h"

int menu()
{
	int opcion;

	system("cls");
	printf("***MENU PRINCIPAL***\n\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n\n");

	utn_getEntero(&opcion, 9, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 10);

	return opcion;
}

int menuEdit()
{
	int opcion;

	system("cls");

	printf("*** MENU EDICION ***\n\n");
	printf("1. Modificar nombre\n");
	printf("2. Modificar horas trabajadas\n");
	printf("3. Modificar sueldo\n");
	printf("4. Salir\n\n");

	utn_getEntero(&opcion, 3, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 4);

	return opcion;
}

int menuSort()
{
	int opcion;
	system("cls");

	printf("*** MENU DE ORDENAMIENTO ***\n\n");
	printf("1. Ordenar por ID\n");
	printf("2. Ordenar por nombre\n");
	printf("3. Ordenar por horas trabajadas\n");
	printf("4. Ordenar por sueldo\n");
	printf("5. Salir\n\n");

	utn_getEntero(&opcion, 4, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 5);

	return opcion;

}

