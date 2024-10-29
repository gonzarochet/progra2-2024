#ifndef NODOALUMNO_H_INCLUDED
#define NODOALUMNO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

typedef struct {
      char nombre[60];
      char genero;
      int edad;
      int nota;
      char dni[10];
}stAlumno;

typedef struct{
    stAlumno alumno;
    struct nodoAlumno * sig;
}nodoAlumno;


nodoAlumno * inicListaAlumno();
nodoAlumno * crearNodoAlumno(stAlumno alumno);
void mostrarListaAlumnos(nodoAlumno * lista);



#endif // NODOALUMNO_H_INCLUDED
