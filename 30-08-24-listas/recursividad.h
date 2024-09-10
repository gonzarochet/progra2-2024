#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "nodoSimple.h"
#include "nodoDoble.h"




nodoSimple * borrarNodoRecursivo(nodoSimple * lista, char dniABorrar[]);

nodoSimple * insertarEnOrdenRecursivo(nodoSimple * lista, nodoSimple * nuevo);

nodoSimple * invertirElementosListaRecursivo(nodoSimple * lista);

int esCapicuaRecursivoDoble(nodoDoble * inicio, nodoDoble * fin);






#endif // RECURSIVIDAD_H_INCLUDED
