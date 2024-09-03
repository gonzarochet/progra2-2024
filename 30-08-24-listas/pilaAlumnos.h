#ifndef PILAALUMNOS_H_INCLUDED
#define PILAALUMNOS_H_INCLUDED

#include "alumno.h"
#include "nodoSimple.h"

#define Pila nodoSimple*

void inicPilaAlumno(Pila * p); //void inicPila(nodoSimple ** p)
void apilarPilaAlumno(Pila * p, stAlumno a);
stAlumno topePilaAlumno(Pila * p);
stAlumno desapilarPilaAlumno(Pila * p);
int pilaVaciaAlumno(Pila * p);




#endif // PILAALUMNOS_H_INCLUDED
