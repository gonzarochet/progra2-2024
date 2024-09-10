#include "recursividad.h"
/// 4. Borrar un nodo de una lista simple (buscado por un dato específico).

nodoSimple * borrarNodoRecursivo(nodoSimple * lista, char dniABorrar[])
{
    nodoSimple * aBorrar = NULL;

    if(lista)
    {

        if(strcmp(lista->dato.dni, dniABorrar) == 0)
        {
            aBorrar = lista;
            lista = lista->sig;
            free(aBorrar);
        }
        else
        {
            lista->sig = borrarNodoRecursivo(lista->sig, dniABorrar);
        }
    }

    return lista;


}
 /*

  5. Insertar un nodo o dato en una lista simplemente
    enlazada en forma recursiva (manteniendo el orden de forma creciente).

*/


nodoSimple * insertarEnOrdenRecursivo(nodoSimple * lista, nodoSimple * nuevo)
{

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.dni) < atoi(lista->dato.dni))
        {
            nuevo->sig = lista;
            lista = nuevo;
        }
        else
        {
            lista->sig = insertarEnOrdenRecursivo(lista->sig, nuevo);

        }
    }

    return lista;

}


/// 6. Invertir una lista simple cambiando los vínculos.

nodoSimple * invertirElementosListaRecursivo(nodoSimple * lista)
{
    nodoSimple * principioNuevo = NULL;

    if(lista->sig)
    {
        principioNuevo = invertirElementosListaRecursivo(lista->sig);
        nodoSimple * aux = lista->sig;
        aux->sig = lista;
        lista->sig = NULL;
    }
    else
    {
        principioNuevo = lista;
    }
    return principioNuevo;
}


 /// 7. Crear una función recursiva que determine si una lista doblemente vinculada es capicúa. (NO usar contador)
int esCapicuaRecursivoDoble(nodoDoble * inicio, nodoDoble * fin)
{

    int rta = 1;

    if(inicio && fin && inicio != fin) // contemplo el caso de que la lista sea impar.
    {
        if(inicio->dato.edad == fin->dato.edad)
        {

            if(!inicio->sig == fin) // contemplo el caso de que la lista sea par.
            {
                rta = esCapicuaRecursivoDoble(inicio->sig, fin->ante);
            }
        }
        else
        {
            rta = 0;
        }
    }

    return rta;

}
