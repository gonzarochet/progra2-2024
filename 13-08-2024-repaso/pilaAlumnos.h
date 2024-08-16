#ifndef PILAALUMNOS_H_INCLUDED
#define PILAALUMNOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

typedef struct {
    stAlumno * valores;  // stAlumno valores[50]
    int validos;
    int dim;
}PilaAlumnos;

void inicPilaAlumnos(PilaAlumnos * p);
void apilarPilaAlumnos(PilaAlumnos * p, stAlumno dato);
stAlumno desapilarPilaAlumnos(PilaAlumnos  * p);
stAlumno topePilaAlumnos(PilaAlumnos * p);
int estaLaPilaVaciaAlumnos(PilaAlumnos * p);
int estaLaPilaVaciaAlumnosTernarioPro(PilaAlumnos * p);
int estaLaPilaVaciaAlumnosPro(PilaAlumnos * p);

#endif // PILAALUMNOS_H_INCLUDED
