#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valor;
    struct nodo2 * siguiente;
    struct nodo2 * anterior;
} nodo2;

typedef struct
{
    nodo2 * inicio;
    nodo2 * fin;
} Fila;

nodo2 * inicLista ();
nodo2 * crearNodo(int dato);
nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevo);
nodo2 * buscarUltimoListaDoble(nodo2 * lista);
nodo2 * archivoToListaDoble(char nombreArchivo[30], nodo2 * lista);
void agregarEnOrdenListaDoble(nodo2 ** lista, nodo2 * nuevo);
nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevo);
void pasarArregloToLista(int arreglo[], int v,  nodo2 ** lista);
void mostrarImparesRecursivo(nodo2 * lista);
void mostrarNodo(nodo2 * nodo);
void archivoToFila(char nombreArchivo[30], Fila * filita);
void inicFila(Fila * filita);
void agregarFila(Fila * filita, int dato);



int main()
{

    nodo2 * listaArchivo = inicLista();
    nodo2 * listaArreglo = inicLista();

    Fila filita;
    inicFila(&filita);


    printf(" Funcion de agregar al final y mostrar lista impares\n ");
    listaArchivo = archivoToListaDoble("numeros.dat",listaArchivo);

    mostrarImparesRecursivo(listaArchivo);


    printf("Funciones de Arreglo to Lista ordenada c/ puntero doble \n");

    int arreglo []={6,3,1,8,7,2,4,9,5,0};
    pasarArregloToLista(arreglo,10,&listaArreglo);
    mostrarListaDoble(listaArreglo);


    printf("Funciones de Fila: \n");
    archivoToFila("numeros.dat", &filita);
    mostrarFila(filita);


    return 0;
}

nodo2 * inicLista ()
{
    return NULL;
}

/// 1 . Crear Nodo
nodo2 * crearNodo(int dato)
{

    nodo2 * nuevo = (nodo2 *) malloc(sizeof(nodo2));

    nuevo->valor = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;

}


/// 2. Agregar al final
nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevo)
{
    nodo2 * ultimo = NULL;

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        ultimo = buscarUltimoListaDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return lista;

}

nodo2 * buscarUltimoListaDoble(nodo2 * lista)
{

    nodo2 * aux = lista;

    while(aux->siguiente)
    {
        aux = aux->siguiente;
    }

    return aux;

}
/// 3. Archivo To Lista Doble
nodo2 * archivoToListaDoble(char nombreArchivo[30], nodo2 * lista)
{
    FILE * archi = fopen(nombreArchivo, "rb");
    int aux;
    if(archi)
    {
        while(fread(&aux,sizeof(int), 1, archi) > 0)
        {
            lista = agregarAlFinal(lista, crearNodo(aux));
        }
        fclose(archi);
    }

    return lista;
}

/// 4. Agregar en orden

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevo)
{

    if(lista)
    {
        lista->anterior = nuevo;
    }
    nuevo->siguiente = lista;

    return nuevo;

}

void agregarEnOrdenListaDoble(nodo2 ** lista, nodo2 * nuevo)
{

    if(!(*lista))
    {
        (*lista) = nuevo;
    }
    else
    {
        nodo2 * aux = (*lista);

        if(nuevo->valor < aux->valor)
        {
            (*lista) = agregarAlPrincipio(aux,nuevo);
        }
        else
        {
            nodo2 * seg = (*lista);

            while(seg && aux->valor < nuevo->valor)
            {
                aux = seg;
                seg = seg->siguiente;
            }

            aux->siguiente = nuevo;
            nuevo->anterior = aux;
            nuevo->siguiente = seg;

            if(seg)
            {
                seg->anterior = nuevo;
            }

        }

    }

}



/// 5. Pasar del arreglo a la lista
void pasarArregloToLista(int arreglo[], int v,  nodo2 ** lista)
{

    for(int i = 0; i < v; i++)
    {
        agregarEnOrdenListaDoble(lista,crearNodo(arreglo[i]));
    }

}

/// 6. Mostrar impares de forma recursiva
void mostrarImparesRecursivo(nodo2 * lista)
{
    if(lista)
    {
        if(lista->valor %2 != 0)
        {
            mostrarNodo(lista);
        }
        mostrarImparesRecursivo(lista->siguiente);
    }

}

void mostrarNodo(nodo2 * nodo)
{

    printf("ANTE: %p -  ACT NUM: %d - SIG: %p\n",nodo->anterior, nodo->valor, nodo->siguiente);
}


/// 7.

void archivoToFila(char nombreArchivo[30], Fila * filita)
{
    FILE * archi = fopen(nombreArchivo, "rb");
    int aux;
    if(archi)
    {
        while(fread(&aux,sizeof(int), 1, archi) > 0)
        {
            agregarFila(filita,aux);
        }
        fclose(archi);
    }
}

void inicFila(Fila * filita)
{

    filita->inicio = inicLista();
    filita->fin = inicLista();
}

void agregarFila(Fila * filita, int dato)
{
    nodo2 * nuevo = crearNodo(dato);
    filita->fin = agregarAlFinal(filita->fin,nuevo);

    if(filita->inicio == NULL)
    {
        filita->inicio = filita->fin;
    }

    filita->fin = nuevo;

}

void mostrarFila(Fila filita){
    mostrarListaDoble(filita.inicio);
}


void mostrarListaDoble(nodo2 * lista){

    if(lista){
        mostrarNodo(lista);
        mostrarListaDoble(lista->siguiente);
    }
}





