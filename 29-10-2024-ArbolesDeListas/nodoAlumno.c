#include "nodoAlumno.h"

nodoMateria * inicListaMateria()
{
    return NULL;
}

nodoMateria * crearNodoMateria(stMateria materia)
{
    nodoMateria * nuevo = (nodoMateria *)malloc(sizeof(nodoMateria));
    nuevo->materia = materia;
    nuevo->sig = NULL;
    nuevo->arbol = inicArbol();
    return nuevo;
}

nodoMateria* buscarUltimo(nodoMateria* lista)
{
    nodoMateria * seg = lista;
    while(seg->sig != NULL)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoMateria* agregarAlFinalAlumno(nodoMateria* lista, nodoMateria* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoMateria* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }

    return lista;
}


void muestraUnAlumno(stAlumno a)
{

    printf("\n-----------------------\n");
    printf("Nombre: ..............%s\n",a.nombre);
    printf("Genero: ..............%c\n",a.genero);
    printf("DNI: ..............%s\n",a.dni);
    printf("Edad: ................%d\n",a.edad);
    printf("Nota: ................%d\n",a.nota);
    printf("\n-----------------------\n");
}



void mostrarListaAlumnos(nodoMateria * lista){

     while(lista)
    {
        muestranodoMateria(lista);
        lista = lista->sig;
    }


}

void muestranodoMateria(nodoMateria * nodo)
{
    printf("\n Nodo: %p", nodo);
    muestraUnAlumno(nodo->alumno);
    printf("\n Nodo->sig: %p", nodo->sig);

}
