#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct {
      char nombre[30];
      char genero;
      int edad;
      int nota;
      char dni[10];
}stAlumno;

stAlumno cargaUnAlumno();
void muestraUnAlumno(stAlumno a);

#endif // ALUMNO_H_INCLUDED
