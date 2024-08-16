#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
      char nombre[30];
      char genero;
      int edad;
      int nota;
}stAlumno;

stAlumno cargaUnAlumno();
void muestraUnAlumno(stAlumno a);


#endif // ALUMNO_H_INCLUDED
