#include <stdio.h>
#include <stdlib.h>

#include "materia.h"
#include "alumno.h"
#include "nodoArbol.h"
#include "nodoMateria.h"


typedef struct
{
    char nombre[70];
    char genero;
    int edad;
    int nota;
    char dni[10];
    int idMateria;
    char nombreMateria[50];
} stRegistroAlumMateria;

nodoMateria * alta(nodoMateria * lda, stMateria materia, stAlumno alumno);
nodoMateria *  archivoToLDA(char nombreArchivo[], nodoMateria * lda);

stAlumno refactorizacionAlumno(stRegistroAlumMateria reg);
stMateria refactorizacionMateria(stRegistroAlumMateria reg);


int main()
{

    nodoMateria * lda = inicListaMateria();

    lda = archivoToLDA("registro.dat",lda);

    mostrarLDA(lda);

    return 0;
}


nodoMateria * alta(nodoMateria * lda, stMateria materia, stAlumno alumno){

    nodoMateria * matABuscar = buscaMateriaPorId(lda, materia.idMateria);

    if(!matABuscar){

        matABuscar = crearNodoMateria(materia);
        lda = agregarAlFinalMateria(lda,matABuscar);
    }

    matABuscar->arbol = insertarEnArbol(matABuscar->arbol, crearNodoAlumnoArbol(alumno));

    return lda;

}


nodoMateria *  archivoToLDA(char nombreArchivo[], nodoMateria * lda)
{

    FILE * archi = fopen(nombreArchivo, "rb");
    stRegistroAlumMateria aux;

    if(archi)
    {
        while(fread(&aux, sizeof(stRegistroAlumMateria),1,archi)>0)
        {
            stAlumno alumno = refactorizacionAlumno(aux);
            stMateria materia = refactorizacionMateria(aux);
            lda = alta(lda,materia,alumno);

        }

        fclose(archi);
    }

    return lda;

}


void mostrarLDA(nodoMateria * lda)
{
   while(lda){
        muestraUnaMateria(lda->materia);
        printf("\n LISTA ALUMNOS \n");
        mostrarArbolAlumnos(lda->arbol);
        lda = lda->sig;
   }


}

stAlumno refactorizacionAlumno(stRegistroAlumMateria reg)
{

    stAlumno aux;

    strcpy(aux.dni, reg.dni);
    strcpy(aux.nombre, reg.nombre);
    aux.genero = reg.genero;
    aux.edad = reg.edad;
    aux.nota = reg.nota;

    return aux;
}


stMateria refactorizacionMateria(stRegistroAlumMateria reg)
{

    stMateria aux;

    strcpy(aux.nombreMateria, reg.nombreMateria);
    aux.idMateria = reg.idMateria;

    return aux;
}

