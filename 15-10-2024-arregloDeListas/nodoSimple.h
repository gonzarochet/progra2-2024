#ifndef NODOSIMPLE_H_INCLUDED
#define NODOSIMPLE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string.h"
#include "alumno.h"


typedef struct
{
    stAlumno  dato;
    struct nodoSimple * sig;
} nodoSimple;

nodoSimple * inicLista();
nodoSimple * crearNodo(stAlumno alumno);
nodoSimple * agregarPrincipio(nodoSimple * lista, nodoSimple * nuevoNodo);
void muestraNodo(nodoSimple * nodo);
void muestraLista(nodoSimple * lista);
void muestraListaRecursiva(nodoSimple * lista);
nodoSimple* buscarUltimo(nodoSimple* lista);
nodoSimple* agregarAlFinal(nodoSimple* lista, nodoSimple* nuevo);
nodoSimple * agregarEnOrdenDNI(nodoSimple * lista, nodoSimple * nuevo);
nodoSimple* invertirElementosLista(nodoSimple* lista);
nodoSimple * cargaRandomLista(nodoSimple * lista);





#endif // NODOSIMPLE_H_INCLUDED
