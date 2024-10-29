#include "nodoArbol.h"


nodoArbol* inicArbol()
{
    return NULL;
}


nodoArbol * crearNodoAlumnoArbol(stAlumno alum)
{

    nodoArbol * nuevo = (nodoArbol *) malloc(sizeof(nodoArbol));
    nuevo->alumno = alum;
    nuevo->der = NULL;
    nuevo->izq = NULL;


    return nuevo;
}

nodoArbol * insertarEnArbol(nodoArbol * arbol, nodoArbol * nuevo)
{

    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(atoi(arbol->alumno.dni) < atoi(nuevo->alumno.dni))
        {
            arbol->der = insertarEnArbol(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertarEnArbol(arbol->izq, nuevo);
        }

    }

    return arbol;

}


void mostrarArbolAlumnos(nodoArbol * arbol){

    if(arbol){
        mostrarArbolAlumnos(arbol->izq);
        muestraUnAlumno(arbol->alumno);
        mostrarArbolAlumnos(arbol->der);
    }

}
