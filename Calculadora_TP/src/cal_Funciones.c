#include<stdio.h>
#include <stdlib.h>
#include "cal_Funciones.h"


/**
 * \brief Solicita un mensje y valor al usuario y devuelve el resultado.
 * \param mensaje, Es el mensaje a ser mostrado
 * \param .............
 * \return El número ingresado por el usuario
 *
 */
int getOpciones(char mensaje[], int opcion)
{
    int auxiliar = opcion;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

/**
 * \brief Solicita un valor al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getValidar(char mensaje[], int valor1) {
    int auxiliar = valor1;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", auxiliar);

    return auxiliar;
}

/** \brief Realiza la suma de dos numeros enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero entero.
 *
 */
int suma(int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}

/** \brief Realiza la resta de dos numeros en enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero entero.
 *
 */
int resta(int a, int b)
{

    int resultado;
    resultado= a - (b);

    return resultado;
}

/** \brief Realiza una multiplicacion entre dos enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero entero.
 *
 */
int multiplicacion( int a, int b)
{

    int resultado;
    resultado= a * b;

    return resultado;
}

/** \brief Realiza la division de dos numeros enteros.
 *
 * \param Pide el primer numero entero.
 * \param Pide el segundo numero entero.
 * \return Retorna un numero flotante.
 *
 */
float division(int a, int b)
{

    float resultado;

    resultado=(float) a / b;


    return resultado;
}

/** \brief Realiza el factorial de un numero.
 *
 * \param Pide un numero entero.
 * \return Retorna un numero long.
 *
 */
long int factorial(int a)
{

    long factorial=1;
    int i;

    for(i=a; i>=1; i--)
    {

        factorial = factorial * i;
    }
    return factorial;
}

