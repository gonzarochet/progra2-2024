#include "materia.h"


void setNombreMateriaRandom(char nombre[])
{
    char arregloNombres[][50] = {"Matematica", "Programacion 1", "Programacion 2", "Base de Datos",
                                 "Arquitectura y Sist.Operativos"};

    strcpy(nombre, arregloNombres[randomRango(0,sizeof(arregloNombres)/30)]);
}

int getIdMateria(char nombre[])
{
    switch(nombre)
    {

    case "Matemática":
        return 1;
    case "Programacion 1":
        return 2;
    case "Programacion 2" :
        return 3;
    case "Base de Datos" :
        return 4;
    case "Arquitectura y Sist.Operativos":
        return 5;
    }

}

stMateria getMateriaRandom(){

    stMateria aux;
    setNombreMateriaRandom(aux.nombreMateria);
    aux.idMateria = getIdMateria(aux.nombreMateria);

    return aux;
}






