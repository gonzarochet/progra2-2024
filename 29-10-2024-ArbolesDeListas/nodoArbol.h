#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#include "alumno.h"

typedef struct{
    stAlumno alumno;
    struct nodoArbol * der;
    struct nodoArbol * izq;
}nodoArbol;


nodoArbol * inicArbol();
nodoArbol * crearNodoAlumnoArbol(stAlumno alum);
nodoArbol * insertarEnArbol(nodoArbol * arbol, nodoArbol * nuevo);



#endif // NODOARBOL_H_INCLUDED
