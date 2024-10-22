#ifndef NODOMATERIA_H_INCLUDED
#define NODOMATERIA_H_INCLUDED

#include "nodoAlumno.h"


typedef struct
{
    int idMateria;
    char nombreMateria[50];
} stMateria;


typedef struct{

    stMateria materia;
    struct nodoMateria * sig;
    nodoAlumno * lista;
}nodoMateria;


nodoMateria * inicListaMateria();
nodoMateria * crearNodoMateria(stMateria mat);


#endif // NODOMATERIA_H_INCLUDED
