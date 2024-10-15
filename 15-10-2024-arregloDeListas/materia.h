#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

typedef struct
{
    int idMateria;
    char nombreMateria[50];
} stMateria;

void setNombreMateriaRandom(char nombre[]);
int getIdMateria(char nombre[]);
stMateria getMateriaRandom();


#endif // MATERIA_H_INCLUDED
