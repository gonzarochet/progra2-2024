#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct
{
    int dato;
    struct nodoSimple * sig;

} nodoSimple;



typedef struct
{

    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;

} nodoArbol;



nodoSimple* crearNodoLista(int dato)
{
    nodoSimple* nuevoNodo = (nodoSimple*) malloc(sizeof(nodoSimple));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    return nuevoNodo;

}

nodoArbol* crearNodoArbol(int dato)
{
    nodoArbol* nuevoNodo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;

}

nodoSimple* agregarAlPrincipio(nodoSimple* lista, nodoSimple* nuevoNodo)
{
    nuevoNodo->sig = lista;
    return nuevoNodo;
}


nodoSimple * cargaRandomLista(nodoSimple * lista)
{


    for(int i = 0; i < 10; i++)
    {
        int dato = rand() % 100 + 1;
        lista = agregarAlPrincipio(lista, crearNodoLista(dato));
    }

    return lista;


}


void mostrarLista(nodoSimple * lista){

    if(lista){
        printf(" -> %d ", lista->dato);
        mostrarLista(lista->sig);
    }

}



nodoArbol * insertarNodo(nodoArbol * arbol, int dato)
{

    if(!arbol)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato < arbol->dato)
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


nodoArbol * lista2Arbol (nodoSimple * lista, nodoArbol * arbol)
{

    if(lista)
    {
        arbol = insertarNodo(arbol,lista->dato);
        arbol = lista2Arbol(lista->sig, arbol);

    }
    return arbol;
}



void mostrarPreOrdenArbol(nodoArbol * arbol){

    if(arbol){
        printf("%d |", arbol->dato);
        mostrarEnOrdenArbol(arbol->izq);
        mostrarEnOrdenArbol(arbol->der);
    }

}

void mostrarEnOrdenArbol(nodoArbol * arbol){

    if(arbol){

        mostrarEnOrdenArbol(arbol->izq);
        printf("%d |", arbol->dato);
        mostrarEnOrdenArbol(arbol->der);
    }

}


void mostrarPostOrdenArbol(nodoArbol * arbol){

    if(arbol){
        mostrarEnOrdenArbol(arbol->izq);
        mostrarEnOrdenArbol(arbol->der);
        printf("%d |", arbol->dato);
    }

}



nodoArbol * arregloToArbolBalanceado(int arreglo[], int inicio, int fin, nodoArbol * arbol)
{

    if(inicio <= fin){

          int posMedio = floor((inicio + fin) / 2);
          arbol = insertarNodo(arbol, arreglo[posMedio]);
          arbol = arregloToArbolBalanceado(arreglo,inicio, posMedio -1, arbol);
          arbol = arregloToArbolBalanceado(arreglo,posMedio +1, fin, arbol);
    }

    return arbol;

}


void dibujarArbol(nodoArbol* arbol, int nivel)
{
    if (arbol)
    {
        // Imprimir el subárbol derecho
        dibujarArbol(arbol->der, nivel + 1);

        // Imprimir espacios y conectores
        for (int i = 0; i < nivel; i++)
        {
            if (i == nivel - 1)
            {
                printf("+--");
            }
            else
            {
                printf("     ");
            }
        }

        // Imprimir el valor del nodo actual
        printf("|%d|\n", arbol->dato);

        // Imprimir el subárbol izquierdo
        dibujarArbol(arbol->izq, nivel + 1);
    }

}



int main()
{

    srand(time(NULL));

    nodoSimple * lista = NULL;
    lista = cargaRandomLista(lista);

    printf("\n La Lista \n");
    mostrarLista(lista);

    nodoArbol * arbol = NULL;
    //arbol = lista2Arbol(lista, arbol);

    dibujarArbol(arbol,0);


    int arreglo[11] = {0,1,2,3,4,5,6,7,8,9,10};

    arbol = arregloToArbolBalanceado(arreglo,0,10,arbol);

    printf("\n EL Arbol Balanceado \n");
    dibujarArbol(arbol,0);






    return 0;
}










