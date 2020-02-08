#include<stdio.h>
#include <stdlib.h>
#include "cal_Funciones.h"



int main()
{
    //variables
    int terminarMenu = 0;
    int opcionesMenu;
    char mensaje[50];
    int operando1;
    int operando2;
    //Banderas.
    int validarOperando1 = 0;
    int validarOperando2 = 0;
    //variables de operaciones aritmeticas.
    int sumar;
    int restar;
    float dividir;
    int multiplicar;
    long factor1;
    long factor2;
    //Banderas.
    int banderaOperaciones = 0;
    int banderaOpcionesMenu = 0;

    do
    {
        fflush(stdin);
        printf("---------- SELECSIONE UNA OPCION DEL MENU ----------\n");
        //Valida si fue inisiada la opcion por primera vez.
        if(validarOperando1 == 1) {
            printf("|           (1) Ingrese primer valor: A = %d        |\n", operando1); //Pide el primer valor y lo muestra como valor fijo.
        }else {
            printf("|           (1) Ingrese primer valor:               |\n");
        }
        if(validarOperando2 == 1) {
            printf("|           (2) Ingrese segundo valor: B = %d       |\n", operando2); //Pide el segundo valor y lo muestra como valor fijo.
        }else {
            printf("|           (2) Ingrese segundo valor:              |\n");
        }
        printf("|           (3) Calcular operaciones                |\n");
        printf("|           (4) Informar resultados                 |\n");
        printf("|           (5) salir                               |\n");
        printf("-----------------------------------------------------\n");
        printf("\nSeleccione una opcion del menu: ");

        banderaOpcionesMenu = scanf("%d", &opcionesMenu);

        switch(opcionesMenu){
            case 1:
                printf("Ingrese primer valor: ");//Pide el primer operando.
                validarOperando1 = scanf("%d", &operando1);//bandera para validar si ya se le cargo un numero, es para cuando se sigue despues de hacer los calculos. y aparte guarda el numero ingresado.

                banderaOperaciones = 0;
                fflush(stdin);

                //Valida si es un numero.
                while(validarOperando1 != 1) {
                        validarOperando1 = getValidar("INCORRECTO!!!, Ingrese primer valor: ", &operando1);
                        break;
                        //printf("incorrecto, ingrese primer valor: ");
                        //fflush(stdin);
                        //validarOperando1 = scanf("%d", &operando1);
                }

            break;

            case 2:
                if(validarOperando1 == 1) {
                        printf("Ingrese segundo valor: ");//Pide el segundo operando.
                        //bandera para validar si ya se le cargo un numero, es para cuando se sigue despues de hacer los calculos. y aparte guarda el numero ingresado.
                        validarOperando2 = scanf("%d", &operando2);
                        banderaOperaciones = 0;
                        fflush(stdin);

                        //Valida si es un numero.
                        while(validarOperando2 != 1) {
                                validarOperando2 = getValidar("INCORRECTO!!!, Ingrese segundo valor: ", &operando2);
                                break;
                            //printf("incorrecto, ingrese segundo valor: ");
                            //fflush(stdin);
                            //validarOperando2 = scanf("%d", &operando2);
                        }

                }else{
                    // Si no se ingreso el primer operando no va a dejar ingresar el segundo para no generar errores en los calculos.
                    printf("Primero seleccione la opcion 1 del menu he ingrese el valor 1\n");
                }

            break;

            case 3:
                //Valida que se hallan ingresado ambos numero A y B.
                if(validarOperando1 == 1 && validarOperando2 == 1) {
                    //Si se verifica que se hallan ingresado los numero se calculan las operaciones.
                    sumar = suma(operando1, operando2);
                    restar = resta(operando1, operando2);
                    dividir = division(operando1, operando2);
                    multiplicar = multiplicacion(operando1, operando2);
                    factor1 = factorial(operando1);
                    factor2 = factorial(operando2);
                    printf("Operaciones realizadas\n");
                    banderaOperaciones = 1;
                }else{
                    printf("Error, no se ingreso operandos\n");
                }

            break;

            case 4:
                //Valida que se hallan calculado las operaciones.
                if(validarOperando2 == 1 && validarOperando1 == 1) {
                    //Valida si se modifico algun numero despues de calcular las operaciones, para que no el mismo resultado para distintos numeros.
                    if(banderaOperaciones == 1) {
                        fflush(stdin);
                        printf("El resultado de A+B es: %d\n", sumar);
                        printf("El resultado de A-B es: %d\n", restar);

                        // Verifica si un operando es cero antes de calcular la division.
                        if(operando1 == 0 || operando2 == 0) {
                                printf("No es posible dividir por cero\n");
                        }else {
                            printf("El reultado de A/b es: %.2f\n", dividir);
                        }
                        printf("El resultado de A*B es: %d\n", multiplicar);

                        //Verifica si algunoi de los operandos es negativo.
                        if(operando1 < 0 || operando2 < 0) {
                            //Verifica si operando 1 es negativo.
                            if(operando1 < 0 && operando2 >= 0) {
                                printf("No es posible calcular el factorial de A por que es negativo. El factorial de B es: %ld\n", factor2);
                            }else if(operando2 < 0 && operando1 >= 0) {
                                //verifica si operando 2 es negativo.
                                printf("No es posible calcular el factorial de B por que es negativo. El factorial de A es: %ld\n", factor1);
                            }else {
                                // En el caso que ambos numeros sean negativos.
                                printf("No es posible calcular el factorial de A y B por que ambos son negativos.\n");
                            }
                        }else {
                            // En el caso que se hallan ingresado bien los numeros (ambos positivos).
                            printf("El factorial de A es: %ld y El factorial de B es: %ld\n", factor1, factor2);
                        }
                    }else if(banderaOperaciones == 0) {
                        //En el caso de que se hallan ingresado los numeros, pero no se hallan calculado las operaciones.
                        printf("Primero aceda a la opcion 3 para realizar las operaciones\n");
                    }
                }else {
                    //En el caso de que no se hallan ingresado operandos.
                    printf("Primero aceda a la opcion 3 para realizar las operaciones\n");
                }
            break;

            case 5:
                terminarMenu = 1;//bandera para salir de while
            break;

            default:
                if(banderaOpcionesMenu != 1){
                        printf("Opcion incorrecta.\n");// Valida que se ingrese un numero.
                }else {
                        printf("Opcion incorrecta.\n");// En el caso de ingresar otro numero que no sea del 1 al 5.
                }
            break;
        }
        system("pause");
        system("cls");
    }while(terminarMenu != 1);

   return 0;
}
/////////////////
