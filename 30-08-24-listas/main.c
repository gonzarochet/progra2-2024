#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "nodoSimple.h"
#include "pilaAlumnos.h"
#include "nodoDoble.h"
#include "filaAlumnos.h"

#define AR_ARCHIVO "alumnos.dat"

void cargarAlumnosArchivo(char nombreArchivo[]);
nodoSimple *  archivoToLista(char nombreArchivo[], nodoSimple * lista);
nodoDoble * listaSimpleADoble(nodoSimple * origen, nodoDoble * destino);

int main()
{
//    nodoSimple * lista = inicLista();
//    nodoDoble * listaDoble = inicListaDoble();
//
//    //cargarAlumnosArchivo(AR_ARCHIVO);
//
//    lista = archivoToLista(AR_ARCHIVO,lista);
//
//    listaDoble = listaSimpleADoble(lista, listaDoble);
//
//    printf("\n Lista Doble: \n");
//    muestraListaDoble(listaDoble);
//
//
//    system("pause");
//
//    //muestraLista(lista);
//
//    listaDoble = borrarNodoDniDoble(listaDoble,"27458662");
//
//    printf("\n Lista Doble despues: \n");
//    muestraListaDoble(listaDoble);



//
//    Pila pilita;
//
//    inicPilaAlumno(&pilita);
//    apilarPilaAlumno(&pilita,cargaUnAlumno());
//    //apilarPilaAlumno(&pilita,cargaUnAlumno());
//    apilarPilaAlumno(&pilita,cargaUnAlumno());
//
//    printf("Mostrar desde la Pila \n");
//    mostrarPilaAlumnos(&pilita);
//
//    printf("Tope pila: \n");
//    muestraUnAlumno(topePilaAlumno(&pilita));


    Fila filita;

    inicFila(&filita);


    agregarFila(&filita, cargaUnAlumno());
    agregarFila(&filita, cargaUnAlumno());


    muestraFila(&filita);












    return 0;
}

void cargarAlumnosArchivo(char nombreArchivo[])
{


    FILE * buffer = fopen(nombreArchivo,"ab");
    stAlumno aux;
    char opcion = 0;
    int i = 0;


    if(buffer)
    {
        do
        {
            printf("Alumno %d\n", i);
            aux = cargaUnAlumno();
            fwrite(&aux,sizeof(stAlumno),1,buffer);
            i++;

            printf("Desea seguir cargando? ESC para salir \n");
            opcion = getch();
        }
        while(opcion != 27);
        fclose(buffer);

    }
}

//void mostrarDesdeArchivo(char nombreArchivo[]){
//
//    FILE * buffer = fopen(nombreArchivo,"rb");
//    stAlumno aux;
//
//    if(buffer){
//
//    }
//
//
//}



nodoSimple *  archivoToLista(char nombreArchivo[], nodoSimple * lista)
{

    FILE * buffer = fopen(nombreArchivo, "rb");
    stAlumno aux;


    if(buffer)
    {
        while(fread(&aux, sizeof(stAlumno), 1, buffer) > 0)
        {
            lista = agregarEnOrdenDNI(lista,crearNodo(aux));
        }
        fclose(buffer);
    }

    return lista;

}

nodoDoble * listaSimpleADoble(nodoSimple * origen, nodoDoble * destino)
{
    nodoSimple * aux = origen;

    while(aux)
    {
        destino = agregarAlFinalDoble(destino, crearNodoDoble(aux->dato));
        aux = aux->sig;
    }

    return destino;

}

/*
1. Recorrer una lista y mostrarla en forma invertida.

2. Sumar los elementos de una lista.

3. Mostrar los elementos de una lista ubicados en una posición par.

4. Borrar un nodo de una lista simple (buscado por un dato específico).



5. Insertar un nodo o dato en una lista simplemente enlazada en forma recursiva (manteniendo el orden de forma creciente).

6. Invertir una lista simple cambiando los vínculos.

7. Si no se hizo de forma recursiva en la guía anterior (guía 4.2 de Listas Dobles): Crear una función recursiva que determine si una lista doblemente vinculada es capicúa. (NO usar contador)

*/


nodo * borrarNodoR( nodo * lista, int dato)
{
    nodo * aBorrar =NULL;

    if(lista!=NULL)
    {
        if(lista->dato==dato)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente=borrarNodoR(lista->siguiente,dato);
        }
    }
    return lista;
}


nodo* insertarEnOrdenR(nodo * lista, nodo * nuevo)
{

    if(lista == NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato < lista->dato)
        {
            nuevo->siguiente = lista;
            lista = nuevo;
        }
        else
        {
            lista->siguiente = insertarEnOrdenR(lista->siguiente, nuevo);
        }
    }
    return lista;
}



int esCapicuaRecursivo(nodoDoble *inicio, nodoDoble *final) {
    int resultado;

    if (inicio == NULL || final == NULL) {
        resultado = 1;  // Lista vacía es capicúa
    } else if (inicio == final || inicio->sig == final) {
        resultado = 1;  // Si los punteros se cruzan o llegan al mismo nodo
    } else if (inicio->dato != final->dato) {
        resultado = 0;  // Si los extremos no coinciden, no es capicúa
    } else {
        resultado = esCapicuaRecursivo(inicio->sig, final->prev);  // Avanzar recursivamente
    }

    return resultado;
}



