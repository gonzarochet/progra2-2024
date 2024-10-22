#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

typedef struct
{
    int idMateria;
    char nombreMateria[50];
} stMateria;

void muestraUnaMateria(stMateria m);
stMateria getMateria();


#endif // MATERIA_H_INCLUDED
