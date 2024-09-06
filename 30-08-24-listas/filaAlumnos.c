#include "filaAlumnos.h"

void inicFila(Fila * filita){

    filita->inicio = inicListaDoble();
    filita->fin = inicListaDoble();
}

void agregarFila(Fila * filita, stAlumno dato)
{
    nodoDoble * nuevo = crearNodoDoble(dato);
    filita->fin = agregarAlFinalDoble(filita->fin,nuevo);

    if(filita->inicio == NULL){
            filita->inicio = filita->fin;
    }

    filita->fin = nuevo;

}


stAlumno verPrimeroFila(Fila * filita){

    stAlumno aux;

    if(filita->inicio){
        aux = verPrimeroListaDoble(filita->inicio);
    }
    return aux;

}


int filaVacia(Fila * fila){
    return (fila->inicio == NULL) ?  1 : 0;
}

void muestraFila(Fila * fila){
    muestraListaDoble(fila->inicio);
}


stAlumno extraerFila(Fila * filita){

    stAlumno aux;

    if(filita->inicio){

        aux = verPrimeroFila(filita->inicio);
        filita->inicio = borrarPrimerNodoListaDoble(filita->inicio);

        if(filita->inicio == NULL){

            filita->fin = inicListaDoble();
        }

    }

    return aux;

}
