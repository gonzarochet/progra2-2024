#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int valor;
    struct nodo * siguiente;

} nodo;

nodo * crearNodo(int dato);
nodo * borrar(nodo * lista, int pos);

int main()
{
    nodo * lista;

    insertarAlPrincipio(&lista, crearNodo(2));
    insertarAlPrincipio(&lista, crearNodo(3));
    insertarAlPrincipio(&lista, crearNodo(4));


    int suma =  sumaValoresMayoresListaRecursiva(lista, 0);

    printf("%d \n",suma);


    mostrarLista(lista);


    lista = borrar(lista,0);
    //lista = borrar(lista,1);


    printf("\n \n");

    mostrarLista(lista);



    return 0;
}

/// Punto 1 Y 9
int sumaValoresMayoresListaRecursiva(nodo * lista, int limite)
{
    int suma;

    if(!lista)
    {
        suma = 0;
    }
    else
    {
        if(lista->valor >= limite)
        {
            suma = lista->valor + sumaValoresMayoresListaRecursiva(lista->siguiente, limite);
        }
        else
        {
            suma = 0 + sumaValoresMayoresListaRecursiva(lista->siguiente, limite);

        }
    }

    return suma;
}

int sumaValoresMayoresListaRecursiva(nodo * lista, int limite)
{
    int suma;

    if(!lista)
    {
        suma = 0;
    }
    else if(lista->valor >= limite)
    {
        suma = lista->valor + sumaValoresMayoresListaRecursiva(lista->siguiente, limite);
    }
    else
    {
        suma = 0 + sumaValoresMayoresListaRecursiva(lista->siguiente, limite);

    }
}

return suma;
}

/// Punto 2:
void insertarAlPrincipio(nodo ** lista, nodo * nuevo)
{

    if(*lista)
    {
        nuevo->siguiente = (*lista);
    }

    (*lista) = nuevo;
}


nodo * crearNodo(int dato)
{

    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->valor = dato;
    nuevo->siguiente = NULL;

    return nuevo;

}

void mostrarLista(nodo * lista)
{

    while(lista)
    {
        printf("VALOR: %d, POS: %p SIG: %p \n",lista->valor, lista, lista->siguiente);
        lista = lista->siguiente;
    }

}

nodo * borrar(nodo * lista, int pos)
{

    nodo * aBorrar = NULL;
    nodo * seg = NULL;
    nodo * ante = NULL;


    if(lista && pos >= 0)
    {

        if(pos == 0 )
        {
            aBorrar = lista;
            lista = lista->siguiente;
            free(aBorrar);
        }
        else
        {
            int i = 1;
            ante = lista;
            seg = lista->siguiente;

            while(seg && i < pos)
            {
                ante = seg;
                seg = seg->siguiente;
            }

            if(seg)
            {
                aBorrar = seg;
                ante->siguiente = seg->siguiente;
                free(aBorrar);
            }


        }

    }

    return lista;


}

/// PUNTO 4
nodo* agregarOrdenadoRec(nodo* lista, nodo* nuevo)
{

    if (lista == NULL || nuevo->valor < lista->valor)
    {
        nuevo->sig = lista;
        lista = nuevo;
    }
    else
    {
        lista->sig = agregarOrdenadoRec(lista->sig, nuevo);
    }

    return lista;
}


/// PUNTO 8

/*
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

    }

    return lista;

} */
