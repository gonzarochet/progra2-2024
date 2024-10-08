#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

stAlumno cargaUnAlumno()
{

    stAlumno aux;

    printf("Ingrese un nombre \n");
    fflush(stdin);
    gets(aux.nombre);

    printf("Ingrese un genero: \n");
    fflush(stdin);
    scanf("%c", &aux.genero);

    printf("Ingrese un DNI: \n");
    fflush(stdin);
    gets(aux.dni);

    printf("Ingrese la edad: \n");
    fflush(stdin);
    scanf("%d", &aux.edad);

    printf("Ingrese la nota: \n");
    fflush(stdin);
    scanf("%d", &aux.nota);


    return aux;
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

///  Funciones para generar un alumno random

int randomRango(int min, int max)
{
    return  min +  rand()% (max - min +1);
}



void setApellidoRandom(char apellido[])
{

    char arreglosApellido[][30] = {"Rojas", "Alvarez",
                                   "Pintos", "Gomez", "Garcia", "Romero", "Martínez"
                                   ,"García", "López", "Pérez", "González", "Rodríguez", "Fernández", "Sánchez", "Ramírez", "Mendoza", "Vásquez", "Morales", "Ortega",
                                   "Castro", "Guerrero", "Castillo", "Rivas", "Campos", "Jaramillo", "Jiménez", "Córdoba", "Salazar", "Torres", "Reyes", "Hernández", "Díaz", "Vega",
                                   "Zapata", "Álvarez", "Ramos", "Pineda", "Montero", "Márquez", "Herrera", "Serrano", "Suárez", "Bermúdez",
                                   "Ángulo", "Gómez", "Linares", "Ospina", "Arrieta", "Castaño", "Valencia", "Gaitán",
                                   "Gómez", "Peralta", "Téllez", "Bernal", "Naranjo"
                                  };

    strcpy(apellido,arreglosApellido[randomRango(0,sizeof(arreglosApellido)/30)]);
}


void setNombreRandom(char nombre[])
{
    char arregloNombres[][30] = {"Alejandro", "Bruno", "Carlos", "Daniel",
                                 "Eduardo", "Fernando", "Gabriel", "Hugo", "Ignacio", "Javier", "Alicia",
                                 "Beatriz", "Carla", "Diana", "Elena", "Fernanda", "Gabriela", "Helena",
                                 "Isabel", "Julieta"
                                };

    strcpy(nombre, arregloNombres[randomRango(0,sizeof(arregloNombres)/30)]);
}

void setDni(char dni[])
{
    int dniE =  randomRango(1000000,99999999);
    itoa(dniE,dni,10);
}

char getGenero()
{
    char array[3] = {'m','f', 'x'};
    return array [randomRango(0,2)];
}


stAlumno cargaRandomAlumno()
{

    stAlumno alumno;

    char apellidoAux[30];

    setNombreRandom(alumno.nombre);

    strcat(alumno.nombre, " ");
    setApellidoRandom(apellidoAux);
    strcat(alumno.nombre, apellidoAux);

    setDni(alumno.dni);
    alumno.genero = getGenero();
    alumno.nota = randomRango(1,10);


    return alumno;

}
