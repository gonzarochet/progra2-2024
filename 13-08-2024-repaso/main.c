#include <stdio.h>
#include <stdlib.h>

#define DIM 10


void intercambio(int * a, int * b);
void intercambioCaracteres(char *a, char *b);
void invertirArreglo(char arregloChar[], int v);
int buscaPosicionMayorElemento(int arregloEntero[], int v);


int main()
{
    printf("Hello world!\n");

    int alfa = 20;
    int beta = 50;

    //printf("Antes Alfa : %d - Beta: %d \n",alfa, beta);

    // intercambio(&alfa,&beta);

    // printf("Despues Alfa : %d - Beta: %d",alfa, beta);


    char arreglo [DIM] = {'a','b','c', 'd', 'e', 'f'};
    int validos = 6;

    invertirArreglo(arreglo,validos);

    for(int i = 0; i<validos; i++)
    {
        printf("%c | ", arreglo[i]);
    }

    int enteros[DIM] = {10,21,32,23,14,5};
    int v = 6;

    int posMayor = buscaPosicionMayorElemento(enteros,v);

    printf("\n El mayor elemento es: %d , y la posicion es %d", enteros[posMayor], posMayor);




    return 0;
}

///  2 . Invertir el contenido de un arreglo de caracteres
void intercambioCaracteres(char *a, char *b)
{

    char aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}


void invertirArreglo(char arregloChar[], int v)
{

    int inic = 0;
    int fin = v-1;

    while(inic <= fin)
    {
        intercambioCaracteres(&arregloChar[inic], &arregloChar[fin]);
        inic++;
        fin--;
    }

}

/// 4. Hacer una función que retorne la posición del
/// valor máximo de un arreglo de números enteros.

int buscaPosicionMayorElemento(int arregloEntero[], int v)
{
    int posMayor = -1;

    if(v > 0)
    {
        posMayor = 0;

        for(int i = 1; i < v; i++)
        {
            if(arregloEntero[i] > arregloEntero[posMayor])
            {
                posMayor = i;
            }
        }
    }


    return posMayor;

}

/// 7. Hacer una función que intercambie el contenido
/// de dos variables. (pasaje de parámetros por referencia)

void intercambio(int * a, int * b)
{
    int aux = 0;

    aux = &a;
    *a = *b;
    *b = aux;
}
