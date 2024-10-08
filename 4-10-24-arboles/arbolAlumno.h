#ifndef ARBOLALUMNO_H_INCLUDED
#define ARBOLALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


typedef struct
{

    stAlumno dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stAlumno dato);
nodoArbol * insertarNodo(nodoArbol * arbol, stAlumno dato);
void mostrarPreOrdenArbol(nodoArbol * arbol);
void mostrarEnOrdenArbol(nodoArbol * arbol);
void mostrarPostOrdenArbol(nodoArbol * arbol);
nodoArbol * busquedaPorDniArbol(nodoArbol * arbol, char dni[]);
nodoArbol * busquedaPorNombreArbol(nodoArbol * arbol, char nombre[]);

#endif // ARBOLALUMNO_H_INCLUDED
