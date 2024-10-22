#include "materia.h"

stMateria getMateria()
{

    stMateria aux;
    int num = randomRango(1,5);
    aux.idMateria = num;

    switch(num)
    {

    case 1:
        strcpy(aux.nombreMateria, "Matematica");
        return aux;
    case 2:
        strcpy(aux.nombreMateria, "Programacion 1");
        return aux;
    case 3:
        strcpy(aux.nombreMateria, "Programacion 2");
        return aux;
    case 4:
        strcpy(aux.nombreMateria, "Base de Datos");
        return aux;
    case 5:
        strcpy(aux.nombreMateria, "Arquitectura y Sist.Operativos");
        return aux;
    }

}


void muestraUnaMateria(stMateria m){
    printf("\n INFO MATERIA-----------------------\n");
    printf("Id Materia....................%d\n",m.idMateria);
    printf("Nombre Materia: ..............%s\n",m.nombreMateria);
    printf("\n-----------------------\n");
}








