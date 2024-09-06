#ifndef FILAALUMNOS_H_INCLUDED
#define FILAALUMNOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "nodoDoble.h"


typedef struct
{
    nodoDoble * inicio;
    nodoDoble * fin;

} Fila;


void inicFila(Fila * filita);
void agregarFila(Fila * filita, stAlumno dato);










#endif // FILAALUMNOS_H_INCLUDED
