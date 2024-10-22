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
    char nombre[70];
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

    //cargarArchivoRegistro("registro.dat");

    //mostrarArchivo("registro.dat");




    vAdl = archivoToADL("registro.dat",ADL,vAdl);
   printf("la cantidad de datos del archivo al adl es %d", vAdl);

    mostrarAdl(ADL, vAdl);


    return 0;
}


void mostrarRegistro(stRegistroAlumMateria r)
{
    printf("\n-----------------------\n");
    printf("Nombre: ..............%s\n",r.nombre);
    printf("Genero: ..............%c\n",r.genero);
    printf("DNI: .................%s\n",r.dni);
    printf("Edad: ................%d\n",r.edad);
    printf("Nota: ................%d\n",r.nota);
    printf("Id Materia............%d\n",r.idMateria);
    printf("Nombre Materia: ......%s\n",r.nombreMateria);
    printf("\n-----------------------\n");

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
    adl[v].materia = mat;
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
        v = agregarMateria(adl,v, materia);
        pos = v-1;
    }

    adl[pos].listaAlumnos = agregarAlFinal(adl[pos].listaAlumnos,crearNodo(alumno));

    return v;

}


stAlumno refactorizacionAlumno(stRegistroAlumMateria reg)
{

    stAlumno aux;

    strcmp(aux.dni, reg.dni);
    strcmp(aux.nombre, reg.nombre);
    aux.genero = reg.genero;
    aux.edad = reg.edad;
    aux.nota = reg.nota;

    return aux;
}


stMateria refactorizacionMateria(stRegistroAlumMateria reg)
{

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
        while(fread(&aux, sizeof(stRegistroAlumMateria),1,archi)>0)
        {
            mostrarRegistro(aux);
            stAlumno alumno = refactorizacionAlumno(aux);
            stMateria materia = refactorizacionMateria(aux);
            v = alta(adl,v,materia,alumno);
        }

        fclose(archi);
    }

    return v;
}


void mostrarAdl(stCelda adl[], int v)
{
    for(int i = 0; i < v; i++)
    {
        muestraUnaMateria(adl[i].materia);
        printf("\n LISTA ALUMNOS \n");
        muestraLista(adl[i].listaAlumnos);
    }
}


int existeDni(FILE * buffer, char dni[])
{

    int flag = 0;

    if(buffer)
    {

        fseek(buffer,0,SEEK_SET);
        stRegistroAlumMateria aux;
        while(flag != 1 && fread(&aux,sizeof(stRegistroAlumMateria), 1, buffer) > 0)
        {
            if(strcmp(dni,aux.dni) == 0)
            {
                flag = 1;
            }
        }
    }

    return flag;


}

stRegistroAlumMateria crearRegistro()
{

    stRegistroAlumMateria aux;
    stAlumno alumnoAux;
    stMateria materiaAux;

    alumnoAux = cargaRandomAlumno();
    materiaAux = getMateria();

    strcpy(aux.nombre,alumnoAux.nombre);
    strcpy(aux.dni,alumnoAux.dni);

    aux.genero = alumnoAux.genero;
    aux.nota = alumnoAux.nota;

    strcpy(aux.nombreMateria,materiaAux.nombreMateria);
    aux.idMateria = materiaAux.idMateria;

    return aux;

}


void cargarArchivoRegistro(char nombreArchivo[])
{

    FILE * archi = fopen(nombreArchivo,"a+b");

    if(archi)
    {
        for(int i = 0; i < 50; i++)
        {
            stRegistroAlumMateria aux = crearRegistro();
            //if(!existeDni(archi,aux.dni))
            fwrite(&aux,sizeof(stRegistroAlumMateria),1,archi);
        }
        fclose(archi);

    }

}



void mostrarArchivo(char nombreArchivo[]){

    FILE * archi = fopen(nombreArchivo, "rb");

    stRegistroAlumMateria aux;

    if(archi){
        while(fread(&aux,sizeof(stRegistroAlumMateria),1,archi)){
            mostrarRegistro(aux);
        }
        fclose(archi);
    }


}
