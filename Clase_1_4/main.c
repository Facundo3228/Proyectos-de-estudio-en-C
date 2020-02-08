#include <stdio.h>
#include <stdlib.h>

/**
    4) Escribir un programa que realice las siguientes acciones:

    Solicite al usuario 10 números
    Calcule cuántos son negativos y cuantos son positivos
    Muestre por pantalla la cantidad de negativos y la cantidad de positivos
    nexo: sacar el promedio de los numeros positivos y la suma de los numeros negativos
*/

int main()
{
    int numero;
    int contador = 1;
    int contaPositivo = 0;
    int acumuladorPositivo = 0;
    int promedioPositivos;
    int contaNegativo = 0;
    int acumuladorNegativo = 0;


    do {
        printf("ingrese numero %d : ", contador);
        scanf("%d", &numero);

        if(numero <= 0) {
            contaNegativo++;
            acumuladorNegativo += numero;
        }else {
            contaPositivo++;
            acumuladorPositivo += numero;
        }
        contador++;
    }while(contador <= 5);

    promedioPositivos = acumuladorPositivo / contaPositivo;

    printf("\nLa cantidad de numeros positivos son: %d\nLa cantidad de numeros negativos son: %d \n\nLa suma de los numeros negativos es: %i \nEl promedio de los numeros positivos es: %i \n", contaPositivo,contaNegativo,acumuladorNegativo,promedioPositivos);

    return 0;
}
