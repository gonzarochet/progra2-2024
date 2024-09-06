#include "nodoDoble.h"

nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble(stAlumno alumno)
{

    nodoDoble * nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = alumno;
    nuevo->sig = NULL;
    nuevo->ante = NULL;

    return nuevo;

}

nodoDoble * agregarPrincipioDoble(nodoDoble * lista, nodoDoble * nuevo)
{

    nuevo->sig = lista;

    if(lista)
    {
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






nodoDoble * borrarNodoDniDoble(nodoDoble * lista, char dniBuscar[])
{

    nodoDoble * actual =  NULL;
    nodoDoble * ante = NULL;
    nodoDoble * seg = NULL;

    int flag = 0;


    if(lista)
    {
        if(strcmp(lista->dato.dni,dniBuscar) == 0)
        {
            actual = lista;
            lista = lista->sig;

            if(lista)
            {
                lista->ante = NULL;
            }

            free(actual);
        }
        else
        {
            seg = lista;

            while(seg && strcmp(seg->dato.dni, dniBuscar) != 0)
            {
                ante = seg;
                seg = seg->sig;
            }

            if(seg)
            {
                ante->sig = seg->sig;
                seg->ante = ante;
                free(seg);
            }

        }


//            ante = lista;
//            actual = lista;
//            seg = lista->sig;
//
//            while(seg && flag == 0)
//            {
//                if(strcmp(seg->dato.dni,dniBuscar) == 0)
//                {
//                    if(seg->sig)
//                    {
//                        ante->sig = seg->sig;
//                        actual = seg;
//                        seg = seg->sig;
//                        seg->ante = ante;
//                    }
//                    else
//                    {
//                        actual->sig = NULL;
//                    }
//
//                    free(actual);
//                    flag = 1;
//                }
//                else
//                {
//                    ante = actual;
//                    actual = seg;
//                    seg = seg->sig;
//                }
//
//            }
//        }

    }

    return lista;

}

void muestraNodoDoble(nodoDoble * nodo)
{
    muestraUnAlumno(nodo->dato);

}

void muestraListaDoble(nodoDoble * lista)
{

    while(lista)
    {
        muestraNodoDoble(lista);
        lista = lista->sig;
    }
}


stAlumno verPrimeroListaDoble(nodoDoble * lista)
{
    return lista->dato;
}


nodoDoble * borrarPrimerNodoListaDoble(nodoDoble * lista){

    nodoDoble * aux = NULL;

    if(lista){
        aux = lista;
        lista = lista->sig;

        if(lista){
            lista->ante = NULL;
        }

        free(aux);
    }

    return lista;


}





