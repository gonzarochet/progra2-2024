#ifndef NODOMATERIA_H_INCLUDED
#define NODOMATERIA_H_INCLUDED

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
nodoMateria * crearNodoMateria(stMateria mat);


#endif // NODOMATERIA_H_INCLUDED
