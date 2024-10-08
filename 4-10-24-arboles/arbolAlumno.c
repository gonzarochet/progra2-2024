#include "arbolAlumno.h"


nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(stAlumno dato)
{
    nodoArbol* nuevoNodo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;

}

nodoArbol * insertarNodo(nodoArbol * arbol, stAlumno dato)
{

    if(!arbol)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(atoi(dato.dni) < atoi(arbol->dato.dni))
        {

            arbol->izq = insertarNodo(arbol->izq, dato);
        }
        else
        {

            arbol->der = insertarNodo(arbol->der, dato);
        }
    }

    return arbol;
}


void mostrarPreOrdenArbol(nodoArbol * arbol)
{

    if(arbol)
    {
        muestraUnAlumno(arbol->dato);
        mostrarEnOrdenArbol(arbol->izq);
        mostrarEnOrdenArbol(arbol->der);
    }

}


void mostrarEnOrdenArbol(nodoArbol * arbol)
{

    if(arbol)
    {

        mostrarEnOrdenArbol(arbol->izq);
        muestraUnAlumno(arbol->dato);
        mostrarEnOrdenArbol(arbol->der);
    }

}


void mostrarPostOrdenArbol(nodoArbol * arbol)
{

    if(arbol)
    {
        mostrarEnOrdenArbol(arbol->izq);
        mostrarEnOrdenArbol(arbol->der);
        muestraUnAlumno(arbol->dato);
    }

}


/// 4. Busqueda

nodoArbol * busquedaPorDniArbol(nodoArbol * arbol, char dni[])
{

    nodoArbol * aBuscar = NULL;

    if(arbol)
    {

        if(atoi(arbol->dato.dni) == atoi(dni))
        {
            aBuscar = arbol;
        }
        else
        {

            if(atoi(arbol->dato.dni) > atoi(dni))
            {
                aBuscar = busquedaPorDniArbol(arbol->izq, dni);
            }
            else
            {
                aBuscar = busquedaPorDniArbol(arbol->der, dni);
            }
        }
    }

    return aBuscar;
}


/// 5. Busqueda por nombre

nodoArbol * busquedaPorNombreArbol(nodoArbol * arbol, char nombre[])
{
    nodoArbol * aBuscar = NULL;

    if(arbol)
    {
        if(strcmpi(arbol->dato.nombre, nombre) == 0)
        {
            aBuscar = arbol;
        }
        else
        {
            aBuscar = busquedaPorNombreArbol(arbol->izq, nombre);
            aBuscar = busquedaPorNombreArbol(arbol->der, nombre);
        }

    }
    return aBuscar;
}


/// 6. Altura del árbol

int alturaArbol(nodoArbol * arbol)
{
    int alturaDer = 0;
    int alturaIzq = 0;

    if(arbol)
    {
        if(arbol->izq){
            alturaIzq = 1 + alturaArbol(arbol->izq);
        }

        if(arbol->der){
            alturaDer = 1 + alturaArbol(arbol->der);
        }

    }

    return(alturaDer > alturaIzq) ? alturaDer : alturaIzq;


}

/// 7. Cantidad Nodos

int cantidadElementosArbol(nodoArbol * arbol)
{

    int cant = 0;

    if(arbol)
    {
        cant = 1 + cantidadElementosArbol(arbol->izq) + cantidadElementosArbol(arbol->der);
    }

    return cant;

}

int cantidadElementosArbolCondicion(nodoArbol * arbol, int condicion)
{

    int cant = 0;

    if(arbol)
    {

        if(arbol->dato.nota >= condicion)
        {
            cant+=1;
        }
        cant = cantidadElementosArbolCondicion(arbol->izq,condicion) + cantidadElementosArbolCondicion(arbol->der,condicion);

    }

    return cant;

}

/// 8. Cantidad de Nodos hojas
int cantidadNodosHojas(nodoArbol * arbol)
{

    int cant = 0;

    if(arbol)
    {
        if(esHoja(arbol))
        {
            cant+=1;
        }
        else
        {
            cant = cantidadNodosHojas(arbol->izq) + cantidadNodosHojas(arbol->der);
        }
    }
    return cant;

}

int esHoja(nodoArbol * nodo)
{
    return (nodo->izq == NULL && nodo->der == NULL) ? 1 : 0;
}








//nodoArbol * arregloToArbolBalanceado(int arreglo[], int inicio, int fin, nodoArbol * arbol)
//{
//
//    if(inicio <= fin){
//
//          int posMedio = floor((inicio + fin) / 2);
//          arbol = insertarNodo(arbol, arreglo[posMedio]);
//          arbol = arregloToArbolBalanceado(arreglo,inicio, posMedio -1, arbol);
////          arbol = arregloToArbolBalanceado(arreglo,posMedio +1, fin, arbol);
//    }
//
//    return arbol;
//
//}


//void dibujarArbol(nodoArbol* arbol, int nivel)
//{
//    if (arbol)
//    {
//        // Imprimir el subárbol derecho
//        dibujarArbol(arbol->der, nivel + 1);
//
//        // Imprimir espacios y conectores
//        for (int i = 0; i < nivel; i++)
//        {
//            if (i == nivel - 1)
//            {
//                printf("+--");
//            }
//            else
//            {
//                printf("     ");
//            }
//        }
//
//        // Imprimir el valor del nodo actual
//        printf("|%d|\n", arbol->dato);
//
//        // Imprimir el subárbol izquierdo
//        dibujarArbol(arbol->izq, nivel + 1);
//    }
//
//}


