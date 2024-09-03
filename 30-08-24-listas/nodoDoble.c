#include "nodoDoble.h"

nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble(){

    nodoDoble * nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = alumno;
    nuevo->sig = NULL;
    nuevo->ante = NULL;

    return nuevo;

}

nodoDoble * agregarPrincipioDoble(nodoDoble * lista, nodoDoble * nuevo){

    nuevo->sig = lista;

    if(lista){
        lista->ante = nuevo;

    }

    return nuevo;

}

nodoDoble* buscarUltimoDoble(nodoDoble* lista)
{
    nodoDoble * seg = lista;
    while(seg->sig != NULL)
    {
        seg = seg->sig;
    }
    return seg;
}


nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoDoble* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }

    return lista;
}
