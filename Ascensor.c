#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main ()
{
    /*Definición de variables*/
    int vflag = 1;
    int piso_actual, piso_deseado;

    while (vflag != 0) /*Bucle que ejecutará el menú las veces necesarias hasta cerrar el programa*/
    {
        /*Definición de variable para el 'primer switch' */
        int i;

        printf("MENU DE OPCIONES\n");
        puts("1. Llamar ascensor");
        puts("2. Seleccionar piso");
        puts("3. Mostrar piso actual");
        puts("4. Salir");
        printf("Ingrese la opcion que desee >> ");

        scanf("%d", &i); /*Asignación de valor a la variable 'i'*/

        switch (i) /*Primer Switch*/
        {
            case 1: /*Se ingresará el piso en el que se encuentra el usuario*/
            {
                system("cls"); /*Limpíeza de cadena de carácteres en la pantalla*/
                printf("Ingrese el piso en el que se encuentra >> ");
                scanf("%d", &piso_actual); /*Asignación de valor a la varibale 'piso_actual' */
                system("cls");

                break;
            }
            case 2: /*Se ingresará el piso al que desea acceder el usuario*/
            {
                /*Definición de variables tipo "Bandera" que mantendrán activos sub-bucles dentro del 'Primer Switch' */
                int vflag_ascensor_subir = 1; /*Bandera para cuando sube el ascensor*/
                int vflag_ascensor_bajar = 1; /*Bandera para cuando baja el ascensor*/

                system("cls"); /*Limpíeza de cadena de carácteres en la pantalla*/

                printf("Pisos\n");
                puts("9 = Noveno Piso");
                puts("8 = Octavo Piso");
                puts("7 = Septimo Piso");
                puts("6 = Sexto Piso");
                puts("5 = Quinto Piso");
                puts("4 = Cuarto Piso");
                puts("3 = Terced Piso");
                puts("2 = Segundo piso");
                puts("1 = Primer piso");
                puts("0 = Planta Baja");

                printf("Ingrese el piso al que desea acceder >> ");
                scanf("%d", &piso_deseado); /*Asignación de valor a la variable 'piso_deseado', tomando el valor del piso al que se 
                desea subir*/
                
                if (piso_actual < piso_deseado) /*Si el piso_actual es menor al piso_deseado*/
                {
                    while (vflag_ascensor_subir == 1) /*Bucle while para subir el ascensor*/
                    {
                        system("cls"); /*Limpíeza de cadena de carácteres en la pantalla*/

                        for (int j = 9; j >= 0; j--) /*Bucle que recorre desde 9 hasta 0, imprimiendo la posición del ascensor por cada
                        iteración*/
                        {

                            if (j == piso_actual){ /*Si el valor de 'j' es igual al valor del piso actual, se colocará la figura del
                            ascensor para representarlo*/

                                printf("| %c |\n", 219); /*Figura del ascensor, interpretada con el código ASCCI alt + 219*/
                                piso_actual++; /*Incremento en 1 al valor del piso actual a fin de que continúe desplazandose 
                                hacia arriba*/
                            }
                            else /*Si 'j' no es igual al valor del piso actual, se imprimirán la figura únicamente de las paredes
                            del ascensor*/
                            {
                                printf("|   |\n");
                            }

                            if (piso_actual == piso_deseado){ /*Si el ascensor llegó a su destino, entonces dejará de ejecutarse
                            el "bucle while para subir el ascensor" */

                                vflag_ascensor_subir = 0; /*Asignación del valor de 0 a la bandera de confirmación*/
                            }
                        }

                        for(int b=0; b<10; b++)
                        {
                            Sleep(200); /*Función de delay, que da la impresión de desplazamiento del carácter del ascensor */
                        }

                    }
                }
                else /*Si el piso_actual es mayor al piso deseado*/
                {
                    while (vflag_ascensor_bajar == 1) /*Bucle while para bajar el ascensor*/
                    {
                        int respaldo = piso_actual; /*Definición de variable de respaldo que tiene asignada el valor
                        de la variable 'piso_actual' para generar el desplazamiento del carácter del ascensor*/

                        system("cls"); /*Limpíeza de cadena de carácteres en la pantalla*/

                        for (int k = 9; k >= 0; k--) /*Bucle que recorre desde 9 hasta 0, imprimiendo la posición del ascensor por cada
                        iteración*/
                        {

                            if (k == respaldo){ /*Si el valor de 'k' es igual al valor del piso actual 
                            (variable 'respaldo'), se colocará la figura del ascensor para representarlo*/

                                respaldo = piso_actual; /*Reasignación del valor de piso actual a 'respaldo'*/
                                printf("| %c |\n", 219);
                                piso_actual--; /*Se resta 1 a 'piso_actual' para ir desplazando hacia abajo el
                                caracter del ascensor*/

                            }
                            else /*Si 'k' es distinta de respaldo, se imprimirán las paredes del ascensor*/
                            {
                                printf("|   |\n");
                            }

                            if (piso_deseado == respaldo){ /*Si el ascensor llegó a su destino, entonces dejará de ejecutarse
                            el "bucle while para subir el ascensor" */

                                vflag_ascensor_bajar = 0; /*Asignación del valor de 0 a la bandera de confirmación*/ 
                                piso_actual = respaldo; /*Asignación de la variabble 'respaldo' a la variable 'piso_actual'*/
                            }
                            
                        }

                        for(int b=0; b<10; b++) 
                        {
                            Sleep(200); /*Función de delay, que da la impresión de desplazamiento del carácter del ascensor */
                        }
                    }                    
                }

                break;
            }
            
            case 3: /*Se conocerá el piso en el que se encuentra el usuario, posterior al desplazamiento*/
            {
                system("cls");
                switch (piso_actual) /*Tomando el valor de 'piso_actual', se dará a conocer el piso en el que
                encuentra el usuario*/

                {
                case 0: puts("Se encuentra en >> Planta Baja\n"); break;
                case 1: puts("Se encuentra en >> Primer Piso\n"); break;
                case 2: puts("Se encuentra en >> Segundo Piso\n"); break;
                case 3: puts("Se encuentra en >> Tercer Piso\n"); break;
                case 4: puts("Se encuentra en >> Cuarto Piso\n"); break;
                case 5: puts("Se encuentra en >> Quinto Piso\n"); break;
                case 6: puts("Se encuentra en >> Sexto Piso\n"); break;
                case 7: puts("Se encuentra en >> Septimo Piso\n"); break;
                case 8: puts("Se encuentra en >> Octavo Piso\n"); break;
                case 9: puts("Se encuentra en >> Noveno Piso\n"); break;
                default: puts("Error."); break;
                }
                break;
            }
            case 4: /*Cerrar el programa*/
            {
                vflag = 0; /*Asignación de 0 a la bandera 'vflag', para finalizar el programa*/
                break;
            }

            default: /*Caso default*/
            {
                printf("\nIngrese una opcion VALIDA\n");
                break;  
            }
        }
    }

    system("cls"); /*Limpíeza de cadena de carácteres en la pantalla*/
    printf("Gracias por usar nuestro servicio!");

    return 0;
}