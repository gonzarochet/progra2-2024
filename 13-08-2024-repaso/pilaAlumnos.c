#include "pilaAlumnos.h"



void inicPilaAlumnos(PilaAlumnos * p)
{

    p->dim = 50;  /// (*p).dim
    p->valores = (stAlumno*) malloc(sizeof(stAlumno) * (p->dim));
    p->validos = 0;

}


/// version regular.
void apilarPilaAlumnos(PilaAlumnos * p, stAlumno dato)
{

    if(p->validos < p->dim)
    {
        p->valores[p->validos] = dato;
        p->validos++;
    }
    else
    {
        printf("Ocurrio un error\n");

    }

}

/// version pro
int apilarPilaAlumnosPro(PilaAlumnos * p, stAlumno dato)
{
    int flag = 1;

    if(p->validos == p->dim)
    {
        int newDim = p->dim * 2;

        stAlumno * aux = (stAlumno *) realloc(p->valores, sizeof(stAlumno)* newDim);
        if(aux)
        {
            p->valores = aux;
        }
        else
        {
            flag = 0;
            //fprintf(stderr,"Memory reallocation failed\n");
        }
    }
    if(flag)
    {
        p->valores[p->validos] = dato;
        p->validos++;
    }

}

stAlumno desapilarPilaAlumnos(PilaAlumnos  * p){

    stAlumno dato = p->valores[p->validos -1];
    p->validos--;
    return dato;
}

stAlumno topePilaAlumnos(PilaAlumnos * p){
    return p->valores[p->validos -1];
}


int estaLaPilaVaciaAlumnos(PilaAlumnos * p){

    int flag = 1;

    if(p->validos > 0){
        flag = 0;
    }

    return flag;
}

int estaLaPilaVaciaAlumnosTernarioPro(PilaAlumnos * p){
    return (p->validos > 0) ? 0  : 1 ;
}

int estaLaPilaVaciaAlumnosPro(PilaAlumnos * p){
    return (p->validos == 0);
}


/// funcion leer.
/// funcion mostrar.









