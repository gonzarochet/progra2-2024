#include "nodoSimple.h"

nodoSimple * inicLista()
{
    return NULL;
}

nodoSimple * crearNodo(stAlumno alumno)
{
    nodoSimple * nuevo = (nodoSimple * )malloc(sizeof(nodoSimple));
    nuevo->dato = alumno;
    nuevo->sig = NULL;
    return nuevo;
}

nodoSimple * agregarPrincipio(nodoSimple * lista, nodoSimple * nuevoNodo)
{
    nuevoNodo->sig = lista;
    return nuevoNodo;
}

void muestraNodo(nodoSimple * nodo)
{
    printf("\n Nodo: %p", nodo);
    muestraUnAlumno(nodo->dato);
    printf("\n Nodo->sig: %p", nodo->sig);

}

void muestraLista(nodoSimple * lista)
{
    while(lista)
    {
        muestraNodo(lista);
        lista = lista->sig;
    }

}

void muestraListaRecursiva(nodoSimple * lista)
{
    if(lista)
    {
        muestraNodo(lista);
        muestraLista(lista->sig);
    }

}

nodoSimple* buscarUltimo(nodoSimple* lista)
{
    nodoSimple * seg = lista;
    while(seg->sig != NULL)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoSimple * borrarUltimoNodo(nodoSimple * lista)
{

    if(lista)
    {
        nodoSimple* seg = lista;
        nodoSimple * ante = NULL;

        while(seg->sig)
        {
            ante = seg;
            seg = seg->sig;
        }

        ante->sig = NULL;
        free(seg);
    }

    return lista;
}

nodoSimple* agregarAlFinal(nodoSimple* lista, nodoSimple* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoSimple* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}


nodoSimple * agregarEnOrdenDNI(nodoSimple * lista, nodoSimple * nuevo)
{

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoSimple * aux = lista; // ante
        if(atoi(aux->dato.dni) > atoi(nuevo->dato.dni))
        {
            lista = agregarPrincipio(aux,nuevo);
        }
        else
        {
            nodoSimple * seg = lista;

            while(seg && atoi(aux->dato.dni) < atoi(nuevo->dato.dni))
            {
                aux = seg;
                seg = seg->sig;
            }

            aux->sig = nuevo;
            nuevo->sig = seg;


        }

    }

    return lista;


}

///  4. Hacer una funci�n que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
///  Se deben redireccionar los punteros, no se deben crear nuevos nodos.

nodoSimple * intercalarListasOrden(nodoSimple * listaA, nodoSimple * listaB)
{

    nodoSimple * listaResultante = inicLista();
    nodoSimple * aux = NULL;

    while(listaA && listaB)
    {
        if(listaA->dato.dni < listaB->dato.dni)
        {
            aux = listaA;
            listaA = listaA->sig;
        }
        else
        {
            aux = listaB;
            listaB = listaB->sig;
        }

        aux->sig = NULL;
        agregarAlFinal(listaResultante,aux);
    }

    if(listaA)
    {
        agregarAlFinal(listaResultante,listaA);
    }
    else if(listaB)
    {
        agregarAlFinal(listaResultante,listaB);
    }
    return listaResultante;

}

/// 5. Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)
nodoSimple* invertirElementosLista(nodoSimple* lista)
{
    if (lista)
    {
        nodoSimple* anterior = NULL;
        nodoSimple* actual = lista;
        nodoSimple* siguiente = NULL;

        while (actual)
        {
            siguiente = actual->sig; // Guarda el siguiente nodo
            actual->sig = anterior; // Cambia el puntero al siguiente nodo

            // Mueve los punteros a la siguiente posición
            anterior = actual;
            actual = siguiente;
        }

        lista =  anterior; // El �ltimo nodo se convierte en la nueva cabeza de la lista invertida
    }

    return lista;  // Devuelve NULL si la lista original estaba vacia



}

nodoSimple * borrarNodoDni(nodoSimple * lista, char dniBuscar[])
{

    nodoSimple * aux =  NULL;
    nodoSimple * ante = NULL;
    nodoSimple * seg = NULL;

    int flag = 0;


    if(lista)
    {
        if(strcmp(lista->dato.dni,dniBuscar) == 0)
        {
            aux = lista;
            lista = lista->sig;
            free(aux);
        }
        else
        {
            ante = lista;
            seg = lista->sig;

            while(seg && flag == 0)
            {
                if(strcmp(seg->dato.dni,dniBuscar) == 0)
                {
                    ante->sig = seg->sig;
                    free(seg);
                    flag = 1;
                }
                else
                {
                    ante = seg;
                    seg = seg->sig;
                }

            }
        }

    }

    return lista;

}


nodoSimple * cargaRandomLista(nodoSimple * lista)
{

    for(int i = 0; i < 4; i++)
    {
        stAlumno dato = cargaRandomAlumno();
        lista = agregarPrincipio(lista, crearNodo(dato));
    }

    return lista;


}


/// ¿porque no funciona?...
nodoSimple * invertirElementosListaRecursivo2(nodoSimple * lista)
{
    nodoSimple * principioNuevo = NULL;

    if(lista->sig)
    {
        principioNuevo = invertirElementosListaRecursivo2(lista->sig);
        principioNuevo->sig = lista;
        lista->sig = NULL;

    }
    else
    {
        principioNuevo = lista;
    }
    return principioNuevo;
}















