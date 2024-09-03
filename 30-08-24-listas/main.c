#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "nodoSimple.h"
#include "pilaAlumnos.h"

#define AR_ARCHIVO "alumnos.dat"

void cargarAlumnosArchivo(char nombreArchivo[]);
nodoSimple *  archivoToLista(char nombreArchivo[], nodoSimple * lista);

int main()
{
//    nodoSimple * lista = inicLista();
//
//    //cargarAlumnosArchivo(AR_ARCHIVO);
//
//    lista = archivoToLista(AR_ARCHIVO,lista);
//
//    muestraLista(lista);

//    lista = invertirElementosListaRecursivo(lista);
//
//    printf("\n Lista Despues: \n");
//    muestraLista(lista);


    Pila pilita;

    inicPilaAlumno(&pilita);
    apilarPilaAlumno(&pilita,cargaUnAlumno());
    //apilarPilaAlumno(&pilita,cargaUnAlumno());
    apilarPilaAlumno(&pilita,cargaUnAlumno());

    printf("Mostrar desde la Pila \n");
    mostrarPilaAlumnos(&pilita);

    printf("Tope pila: \n");
    muestraUnAlumno(topePilaAlumno(&pilita));












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



nodoSimple *  archivoToLista(char nombreArchivo[], nodoSimple * lista){

    FILE * buffer = fopen(nombreArchivo, "rb");
    stAlumno aux;


    if(buffer){
        while(fread(&aux, sizeof(stAlumno), 1, buffer) > 0){
            lista = agregarEnOrdenDNI(lista,crearNodo(aux));
        }
        fclose(buffer);
    }

    return lista;

}
