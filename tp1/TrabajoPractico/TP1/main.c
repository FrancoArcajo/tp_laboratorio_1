#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int numero1;
    int numero2;
    int respSuma;
    int respResta;
    int respMultiplicacion;
    float respDivision;
    int factorial1;
    int factorial2;
    int opcion;
    int flagOp1 = 0;
    int flagOp2 = 0;
    char seguir = 'n';

    do
    {
        system("cls");

        if (flagOp1 == 0)
        {
            printf("1. Ingresar primer operando (A=x)\n");
        }
        else
        {
            printf("1. Ingresar primer operando (A=%d)\n", numero1);
        }
        if (flagOp2 == 0)
        {
            printf("2. Ingresar segundo operando (B=y)\n");
        }
        else
        {
            printf("2. Ingresar segundo operando (B=%d)\n", numero2);
        }

        printf("3. Calcular todas las operaciones\n");
        printf("   a) Calcular la suma (A+B)\n");
        printf("   b) Calcular la resta (A-B)\n");
        printf("   c) Calcular la division (A/B)\n");
        printf("   d) Calcular la multiplicacion (A*B)\n");
        printf("   e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("Seleccione opcion\n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el primer numero: ");
            scanf("%d", &numero1);
            flagOp1 = 1;
            break;

        case 2:
            printf("Ingrese el segundo numero: ");
            scanf("%d", &numero2);
            flagOp2 = 1;
            break;

        case 3:
            respSuma = sumar(numero1, numero2);
            respResta = restar(numero1, numero2);
            respMultiplicacion = multiplicar(numero1, numero2);
            if (numero2 != 0)
            {
                respDivision = dividir(numero1, numero2);
            }
            factorial1 = factorial(numero1);
            factorial2 = factorial(numero2);
            break;

        case 4:
            printf("Resultado suma entre %d, %d es: %d \n", numero1, numero2, respSuma);
            printf("Resultado resta entre %d, %d es: %d \n", numero1, numero2, respResta);
            printf("Resultado multiplicacion entre %d, %d es: %d \n", numero1, numero2, respMultiplicacion);
            if (numero2 != 0)
            {
                printf("Resultado division entre %d, %d es: %.2f \n", numero1, numero2, respDivision);
            }
            else
            {
                printf("No se puede dividir por cero\n");
            }
            printf("Resultado factorial operando A %d es %d \n", numero1, factorial1);
            printf("Resultado factorial operando B %d es %d \n", numero2, factorial2);
            system("pause");
            break;

        case 5:
            printf("Esta seguro que desea salir?(s o n)");
            fflush(stdin);
            scanf("%c", &seguir);
            break;

        default:
            printf("Ingrese una opcion valida: ");
            scanf("%d", &opcion);
        }

    }
    while (seguir == 'n');

    return 0;
}

/// FUNCION C

int sumar(int num1,int num2){
    int suma;
    suma = num1 + num2;

    return suma;
}

int restar (int num1, int num2) {
    int resta;
    resta = num1 - num2;

    return resta;
}
int multiplicar (int num1, int num2) {
    int multiplicacion;
    multiplicacion = num1 * num2;

    return multiplicacion;
}
float dividir (int num1, int num2) {
    float division;
    division = num1 / num2;

    return division;

}
int factorial (int numero){

    if(numero >= 13){
        return -1;
    }else if(numero <= 1){
        return 1;
    }else{
        return numero * factorial(numero - 1);
    }
}

/// FUNCION H
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED

/** \brief Calcula la suma de dos numeros.
 *
 * \param Ingreso primer numero para sumar
 * \param Ingreso el segundo numero para sumar.
 * \return Devuelve suma.
 *
 */

int sumar (int num1, int num2);

/** \brief Calcula la resta de dos numeros.
 *
 * \param Ingreso el primer numero para restar.
 * \param Ingreso el segundo numero para restar.
 * \return Devuelve la resta.
 *
 */

int restar (int num1, int num2);

/** \brief Calcula la multiplicacion de dos numeros.
 *
 * \param Ingreso primer numero para multiplicar.
 * \param Ingreso segundo numero para multiplicar.
 * \return Devuelve la multiplicacion.
 *
 */


int multiplicar (int num1, int num2);

/** \brief Calcula la division de dos numeros.
 *
 * \param Ingreso primer numero para dividir.
 * \param Ingreso segundo numero para dividir.
 * \return Devuelve la division.
 *
 */


float dividir (float num1, float num2);

/** \brief Calcula la factorizacion de un numero.
 *
 * \param Ingreso numero para factorizar.
 * \return Devuelve la factorizacion.
 *
 */

int factorial  (int numero);

