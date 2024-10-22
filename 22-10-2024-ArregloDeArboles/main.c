#include <stdio.h>
#include <stdlib.h>


#include "alumno.h"
#include "materia.h"
#include "arbolAlumno.h"


typedef struct
{
    stMateria materia;
    nodoArbol* arbol;
} stCelda;

int main()
{
    printf("Hello world!\n");
    return 0;
}


int alta(stCelda ada[], int v, stMateria materia, stAlumno alumno){

    int pos = buscaPosMateria(ada,v,materia.id);

    if(pos == -1){
        v = agregarMateria(ada,v, materia);
        pos = v-1;
    }

    ada[pos].arbol = insertarNodo(ada[pos].arbol, alumno);

    return v;
}


int buscaPosMateria(stCelda ada[], int v, int idMateria)
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


int agregarMateria(stCelda ada[], int v, stMateria mat)
{
    /// 1. Agregar el dato a la estructura principal
    ada[v].materia = mat;
    /// 2. Inicializar la estructura secundaria
    ada[v].arbol = inicArbol();
    /// 3. Incrementa válidos.
    v++;
    return v;
}



