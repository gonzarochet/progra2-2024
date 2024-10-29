#ifndef NODOARBOLMATERIA_H_INCLUDED
#define NODOARBOLMATERIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "materia.h"
#include "nodoAlumno.h"

typedef struct{

    stAlumno alumno
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

#endif // NODOARBOLMATERIA_H_INCLUDED
