#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

stAlumno cargaUnAlumno()
{

    stAlumno aux;

    printf("Ingrese un nombre \n");
    fflush(stdin);
    gets(aux.nombre);

    printf("Ingrese un genero: \n");
    fflush(stdin);
    scanf("%c", &aux.genero);

    printf("Ingrese un DNI: \n");
    fflush(stdin);
    gets(aux.dni);

    printf("Ingrese la edad: \n");
    fflush(stdin);
    scanf("%d", &aux.edad);

    printf("Ingrese la nota: \n");
    fflush(stdin);
    scanf("%d", &aux.nota);


    return aux;
}


void muestraUnAlumno(stAlumno a){

    printf("\n-----------------------\n");
    printf("Nombre: ..............%s\n",a.nombre);
    printf("Genero: ..............%c\n",a.genero);
    printf("DNI: ..............%s\n",a.dni);
    printf("Edad: ................%d\n",a.edad);
    printf("Nota: ................%d\n",a.nota);
    printf("\n-----------------------\n");
}
