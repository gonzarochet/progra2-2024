#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "alumno.h"
#include "arbolAlumno.h"
#include "nodoSimple.h"


nodoArbol * lista2Arbol (nodoSimple * lista, nodoArbol * arbol);
nodoSimple * arbol2Lista(nodoArbol * arbol, nodoSimple * lista);


int main()
{
    nodoSimple * lista = NULL;
    lista = cargaRandomLista(lista);

    // printf("\n La Lista \n");
   // muestraLista(lista);

    nodoArbol * arbol = NULL;
    arbol = lista2Arbol(lista, arbol);

    printf("\n El árbol \n");
    mostrarPreOrdenArbol(arbol);


    int altura = alturaArbol(arbol);

    printf("La altura del arbol es %d", altura);


//    nodoSimple * lista2 = inicLista();
//
//    printf("\n La Lista ordenada después del árbol \n");
//    lista2 = arbol2Lista(arbol,lista2);
//
//    muestraLista(lista2);


    return 0;
}

/// 3.0 Lista a Arbol

nodoArbol * lista2Arbol (nodoSimple * lista, nodoArbol * arbol)
{

    if(lista)
    {
        arbol = insertarNodo(arbol,lista->dato);
        arbol = lista2Arbol(lista->sig, arbol);
    }
    return arbol;
}


/// 3.1 Arbol a Lista
nodoSimple * arbol2Lista(nodoArbol * arbol, nodoSimple * lista)
{

    if(arbol)
    {
        lista = agregarAlFinal(lista, crearNodo(arbol->dato));
        lista = arbol2Lista(arbol->izq, lista);
        lista = arbol2Lista(arbol->der, lista);
    }
    return lista;
}











