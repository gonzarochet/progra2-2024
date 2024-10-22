
nodoAlumno * inicListaAlumno()
{
    return NULL;
}

nodoAlumno * crearNodoAlumno(stAlumno alumno)
{
    nodoAlumno * nuevo = (nodoAlumno * )malloc(sizeof(nodoAlumno));
    nuevo->alumno = alumno;
    nuevo->sig = NULL;
    return nuevo;
}
