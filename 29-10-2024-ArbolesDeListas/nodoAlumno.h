#ifndef NODOALUMNO_H_INCLUDED
#define NODOALUMNO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "materia.h"
#include "nodoArbol.h"

typedef struct{
    stMateria materia;
    struct nodoMateria * sig;
    nodoArbol * arbol;
}nodoMateria;


nodoMateria * inicListaMateria();
nodoMateria * crearNodoMateria(stAlumno alumno);
void mostrarListaMateria(nodoMateria * lista);



#endif // NODOALUMNO_H_INCLUDED
