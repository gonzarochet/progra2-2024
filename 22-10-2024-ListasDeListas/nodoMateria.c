
nodoMateria * inicListaMateria()
{
    return NULL;
}

nodoMateria * crearNodoMateria(stMateria mat)
{
    nodoMateria * nuevo = (nodoMateria*)malloc(sizeof(nodoMateria));
    nuevo->materia = mat;
    nuevo->sig = NULL;
    nuevo->lista = inicListaAlumno();
    return nuevo;
}
