#include "pilaAlumnos.h"

void inicPilaAlumno(Pila * p)
{
    (*p) = inicLista();
}

void apilarPilaAlumno(Pila * p, stAlumno a){

    (*p) = agregarAlFinal((*p), crearNodo(a));
}

stAlumno topePilaAlumno(Pila * p){

    nodoSimple * aux = buscarUltimo((*p));
    return aux->dato;

   // return buscarUltimo((*p))->dato;
}


stAlumno desapilarPilaAlumno(Pila * p){

    nodoSimple * aux =  buscarUltimo((*p));
    stAlumno alum = aux->dato;
    (*p) = borrarUltimoNodo((*p));

    return alum;

}
int pilaVaciaAlumno(Pila * p){

    int flag = 1;

    if((*p) != NULL){
        flag = 0;
    }

    return flag;

}


void mostrarPilaAlumnos(Pila * p){
    muestraLista((*p));
}
