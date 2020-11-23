#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/mascotas.h"
#include "../inc/controller.h"
#include "../inc/parser.h"
#include "../inc/menu.h"
#include "../inc/utn.h"

int menu()
{
	int opcion;

	system("cls");
	printf("***MENU PRINCIPAL***\n\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Alta de empleado\n");
	printf("3. Modificar datos de empleado\n");
	printf("4. Baja de empleado\n");
	printf("5. Listar empleados\n");
	printf("6. Ordenar empleados\n");
	printf("7. Limpiar lista\n");
	printf("8. Crear sublista\n");
	printf("9. Mover empleado\n");
	printf("10. Hacer una copia de datos de los empleados en un archivo csv\n");
	printf("11. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("12. Salir\n\n");

	utn_getEntero(&opcion, 11, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 12);

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
