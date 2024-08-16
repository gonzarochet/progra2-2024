#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "alumno.h"
#include "pilaAlumnos.h"

#define DIM 10


void intercambio(int * a, int * b);
void intercambioCaracteres(char *a, char *b);
void invertirArreglo(char arregloChar[], int v);
int buscaPosicionMayorElemento(int arregloEntero[], int v);
int esCapicua(char palabra[]);


int main()
{
    printf("Hello world!\n");

    int alfa = 20;
    int beta = 50;


    stAlumno aux;

    aux = cargaUnAlumno();

    muestraUnAlumno(aux);

    PilaAlumnos p;
    inicPilaAlumnos(&p);

    apilarPilaAlumnos(&p,aux);

    muestraUnAlumno(topePilaAlumnos(&p));

    printf("Si llegue aca es porque funciona\n");



    //printf("Antes Alfa : %d - Beta: %d \n",alfa, beta);

    // intercambio(&alfa,&beta);

    // printf("Despues Alfa : %d - Beta: %d",alfa, beta);

//
//    char arreglo [DIM] = {'a','b','c', 'd', 'e', 'f'};
//    int validos = 6;
//
//    invertirArreglo(arreglo,validos);
//
//    for(int i = 0; i<validos; i++)
//    {
//        printf("%c | ", arreglo[i]);
//    }
//
//    int enteros[DIM] = {10,21,32,23,14,5};
//    int v = 6;
//
//    int posMayor = buscaPosicionMayorElemento(enteros,v);
//
//    printf("\n El mayor elemento es: %d , y la posicion es %d \n", enteros[posMayor], posMayor);
//
//    int flag = esCapicua("neuqueno");
//
//    printf("es capicua ( 0 no - 1 si) : %d\n", flag);




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


/// 6. Dada una cadena de caracteres, hacer una función que determine si dicha cadena es palíndromo
/// La función recibe como parámetro la cadena y retorna 1 o 0 según sea la respuesta.
int esCapicua(char palabra[])
{


    int cantCaracteres = strlen(palabra); // los válidos
    int posInic = 0;
    int posFin = cantCaracteres - 1;
    int flag = 1;

   printf("La cantidad de caracteres es %d de la palabra %s \n",cantCaracteres, palabra);

    while(posInic <= posFin && flag==1) // flag
    {
        if(palabra[posInic] == palabra[posFin])
        {
            posInic++;
            posFin--;
        }
        else
        {
            flag = 0;
        }
    }

    return flag;

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

/// 8. Intercarlar dos arreglos ordenados de menor a mayor en uno nuevo
/// recibo por parámetro.
int intercalarArreglos(int a[],int vA, int b[], int vB, int c[])
{

    int iA = 0;
    int iB = 0;
    int iC = 0;


    while(iA < vA && iB < vB)
    {

        if(a[iA]<= b[iB])
        {
            c[iC] = a[iA];
            iA++;

        }else{

            c[iC] = b[iB];
            iB++;

        }

         iC++;
    }


    while(iA < vA){
        c[iC] = a[iA];
        iA++;
        iC++;
    }

    while(iB < vB){
        c[iC] = b[iB];
        iB++;
        iC++;
    }


    return iC;

}


