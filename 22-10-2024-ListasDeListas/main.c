#include <stdio.h>
#include <stdlib.h>

#include "nodoAlumno.h"
#include "nodoMateria.h"



int main()
{
    printf("Hello world!\n");
    return 0;
}


nodoMateria * alta(nodoMateria * listaMaterias, stMateria materia, stAlumno alumno){

    nodoMateria * matABuscar = buscaMateriaPorId(listaMaterias, materia.idMateria);

    if(!matABuscar){

        matABuscar = crearNodoMateria(materia);
        listaMaterias = agregarAlFinalMateria(listaMaterias,matABuscar);
    }

    matABuscar.lista = agregarAlFinalAlumno(matABuscar.lista, crearNodoAlumno(alumno));

    return listaMaterias;

 }
