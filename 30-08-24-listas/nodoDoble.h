#ifndef NODODOBLE_H_INCLUDED
#define NODODOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

typedef struct{

    stAlumno dato;
    struct nodoDoble * sig;
    struct nodoDoble * ante;

}nodoDoble;


/// 1. Inicializa la lista.
/// 2. Crear Nodo Doble.
/// 3. Agregar Nodo al Principio de una lista.
/// 4. Agregar un Nodo en Orden por DNI en lista doble.
/// 5. Agregar un Nodo al Final de la lista.
/// 6. Muestra un Nodo Y Muestra una lista de Nodos Dobles.
/// 7. Ve el primer nodo de una lista DOBLE.
stAlumno verPrimeroListaDoble(nodoDoble * lista);
/// 8. Busca un nodo por DNI en una lista DOBLE.
/// 10. Borrar el Primer Nodo de una lista.
nodoDoble * borrarPrimerNodoListaDoble(nodoDoble * lista);
/// 11. Borrar un Nodo definido por DNI de una lista.
/// 12. Borrar el Último Nodo de una lista.
/// 13. Borrar una Lista de Nodos Dobles COMPLETA.

#endif // NODODOBLE_H_INCLUDED
