#include "nodoMateria.h"

nodoMateria * inicListaMateria()
{
    return NULL;
}

nodoMateria * crearNodoMateria(stMateria mat)
{
    nodoMateria * nuevo = (nodoMateria*)malloc(sizeof(nodoMateria));
    nuevo->materia = mat;
    nuevo->sig = NULL;
    nuevo->arbol = inicArbol();
    return nuevo;
}



nodoMateria * buscaMateriaPorId(nodoMateria * lista, int idMateria){

    nodoMateria * aBuscar = NULL;

    nodoMateria * aux = lista;


    while(aux && !aBuscar){
            if(aux->materia.idMateria == idMateria){
                aBuscar = aux;
            }
            aux = aux->sig;
    }

    return aBuscar;

}



nodoMateria* buscarUltimaMateria(nodoMateria* lista)
{
    nodoMateria * seg = lista;
    while(seg->sig != NULL)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoMateria* agregarAlFinalMateria(nodoMateria* lista, nodoMateria* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoMateria* ultimo = buscarUltimaMateria(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}


void mostrarListaMateria(nodoMateria * lista){

     while(lista)
    {
        muestraNodoMateria(lista);
        lista = lista->sig;
    }


}

void muestraNodoMateria(nodoMateria * nodo)
{
    printf("\n Nodo: %p", nodo);
    muestraUnaMateria(nodo->materia);
    printf("\n Nodo->sig: %p", nodo->sig);

}


