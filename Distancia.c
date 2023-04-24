/*Implementación de librerías*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cuadrado (float x1, float y1, float x2, float y2) /*Función que determina la resta y cuadrado de 
dos puntos cartesianos (x1, y1) y (x2, y2)*/
{  
    /*Definición de variables*/
    float sumatotal;
    float power1, power2; /*Variable que almacenará el resultado de elevar al cuadrado la resta de 
    'x1' y 'x2', así como 'y1' y 'y2'*/

    if (x1 > x2){ /*Determina cúal es el número mayor entre 'x1' y 'x2' para realizar la resta y potencia*/
        power1 = pow(x1 - x2, 2);
    }
    else{
        power1 = pow(x2 - x1, 2);
    }

    if (y1 > y2){ /*Determina cúal es el número mayor entre 'y1' y 'y2' para realizar la resta y potencia*/
        power2 = pow(y1 - y2, 2);
    }
    else{
        power2 = pow(y2 - y1, 2); 
    }

    sumatotal = power1 + power2; /*Asignación de resultados*/
    
    return sumatotal; /*Regreso a la función 'calcular_distancia'*/
}

float raiz_cuadrada (float resultado_cuadrado) /*Función que determina la raíz del resultado obtenido en
la función 'cuadrado'*/
{   
    float raiz; /*Definición de variable que alamacenará el resultado de la raíz*/
    raiz = sqrt (resultado_cuadrado); /*Función que determina la raíz cuadrada*/

    return raiz; /*Regreso a la función 'calcular_distancia'*/
}

float calcular_distancia (float distancia) /*Función que determina la distancia cartesiana entre dos puntos*/
{
    /*Definición de variables*/

    float x1, x2, y1, y2; /*Variables para almacenar coordenadas*/
    float resultado_cuadrado; /*Variable que alamacenará el valor retornado por la función 'cuadrado'*/
    float resultado_raiz; /*Variable que alamacenará el valor retornado por la función 'raiz_cuadrada'*/
    
    printf("DISTANCIA ENTRE PUNTOS\n\n1. Ingrese las coordenadas de dos puntos (x, y)");
    printf("\nCoordenada en x1: ");
    scanf("%f", &x1); /*Asignación de valor a 'x1' */
    printf("Coordenada en y1: ");
    scanf("%f", &y1); /*Asignación de valor a 'y1' */

    printf("2. Ingrese las coordenadas de dos puntos (x, y)");
    printf("\nCoordenada en x2: ");
    scanf("%f", &x2); /*Asignación de valor a 'x2' */
    printf("Coordenada en y2: ");
    scanf("%f", &y2); /*Asignación de valor a 'y2' */

    resultado_cuadrado = cuadrado(x1,y1,x2,y2); /*Llamada a la función 'cuadrado'*/
    resultado_raiz = raiz_cuadrada(resultado_cuadrado); /*Llamada a la función 'raíz_cuadrada' con
     el argumento obtenido del valor retornado por 'cuadrado'*/

    return resultado_raiz; /*Regreso a la función 'main'*/
}

/*Función principal e inicio del programa*/
int main ()
{   
    /*Definición de variable que almacenará el resultado obtenido por la función 'calcular_distnacia'*/
    float distancia;

    distancia = calcular_distancia(distancia); /*Llamada a la función 'calcular_distancia'*/

    printf("\nRESULTADO. Distancia entre ambos puntos: %.2f", distancia); /*Impresión de resultados*/

    return 0; /*Fin del programa*/
}