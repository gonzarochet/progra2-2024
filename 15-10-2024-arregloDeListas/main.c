#include <stdio.h>
#include <stdlib.h>

#include "materia.h"
#include "alumno.h"
#include "nodoSimple.h"


typedef struct
{
    stMateria materia;
    nodoSimple * listaAlumnos;
} stCelda;

typedef struct
{
    char nombre[60];
    char genero;
    int edad;
    int nota;
    char dni[10];
    int idMateria;
    char nombreMateria[50];
} stRegistroAlumMateria;


int main()
{
    stCelda ADL[10];
    int vAdl = 0;

    vAdl = archivoToADL("registro.dat",adl,vAdl);


    return 0;
}


int buscaPosMateria(stCelda adl[], int v, int idMateria)
{

    int rta = -1;
    int i = 0;

    while(i < v && rta == -1)
    {

        if(adl[i].materia.idMateria == idMateria)
        {
            rta = i;
        }
        i++;
    }

    return rta;
}


int agregarMateria(stCelda adl[], int v, stMateria mat)
{

    /// 1. Agregar el dato a la estructura principal
    adl[v] = mat;
    /// 2. Inicializar la estructura secundaria
    adl[v].listaAlumnos = inicLista();
    /// 3. Incrementa válidos.
    v++;

    return v;
}



int alta(stCelda adl[], int v, stMateria materia, stAlumno alumno)
{

    int pos = buscaPosMateria(adl,v,materia.idMateria);

    if(pos == -1)
    {
        validos = agregarMateria(adl,v, materia);
        pos = v-1;
    }

    adl[pos].listaAlumnos = agregarAlFinal(adl[pos].listaAlumnos,crearNodo(alumno));

    return v;

}


stAlumno refactorizacionAlumno(stRegistroAlumMateria reg){

    stAlumno aux;

    strcmp(aux.dni, reg.dni);
    strcmp(aux.nombre, reg.nombre);
    aux.genero = reg.genero;
    aux.edad = reg.edad;
    aux.nota = reg.nota;

    return aux;
}


stMateria refactorizacionMateria(stRegistroAlumMateria reg){

    stMateria aux;

    strcmp(aux.nombreMateria, reg.nombreMateria);
    aux.idMateria = reg.idMateria;

    return aux;
}


int archivoToADL(char nombreArchivo[], stCelda adl[], int v)
{

    FILE * archi = fopen(nombreArchivo, "rb");
    stRegistroAlumMateria aux;

    if(archi)
    {
        while(fread(&aux, sizeof(stRegistroAlumMateria),1,archi)>0){
            stAlumno alumno = refactorizacionAlumno(aux);
            stMateria materia = refactorizacionMateria(materia);
            v = alta(adl,v,materia,alumno);
        }

        fclose(archi);
    }

    return v;
}
