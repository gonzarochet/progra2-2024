#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char dni[20];
    int edad;
    char genero;  // ‘m’ o ‘f’;
    float nomina;
    int baja; // 0 no, 1 sí;
} stEmpleado;

typedef struct
{
    stEmpleado dato;
    struct nodoEmpleado * siguiente;
} nodoEmpleado;


nodoEmpleado * inicLista();
nodoEmpleado* crearNodo(stEmpleado empleado);
nodoEmpleado* agregarAlFinal(nodoEmpleado* lista, nodoEmpleado* nuevoNodo);
nodoEmpleado* cargarEmpleadosDesdeArchivo(nodoEmpleado* lista, char nombreArchivo[]);



void mostrarEmpleado(stEmpleado empleado);
void mostrarNodo(nodoEmpleado * e);
void mostrarListaRecusiva(nodoEmpleado * lista);


int cantEmpleados (nodoEmpleado * lista);
int cantEmpleadosSalarioDigno(nodoEmpleado * lista, float canastaBasica);
float sumarSalarios(nodoEmpleado* lista);
void mostrarResultados(nodoEmpleado* lista, float canastaBasica);


nodoEmpleado* buscarMayorSueldo(nodoEmpleado* lista);
stEmpleado borrarNodo(nodoEmpleado ** lista, char dni[]);
nodoEmpleado* agregarAlPrincipio(nodoEmpleado* lista, nodoEmpleado* nuevoNodo);
nodoEmpleado* obtenerMejoresSueldos(nodoEmpleado* listaOriginal);


int main()
{

    nodoEmpleado* lista = inicLista();

    lista = cargarEmpleadosDesdeArchivo(lista,"empleados.dat");

    mostrarListaRecusiva(lista);

    mostrarResultados(lista, 304170);

    nodoEmpleado * listaMejoresSueldos = inicLista();

    listaMejoresSueldos = obtenerMejoresSueldos(lista);


    printf("\n<<<<<<<<<< MEJORES SUELDOS EMPLEADOS >>>>>>>>>>> \n");
    mostrarListaRecusiva(listaMejoresSueldos);


    return 0;
}

nodoEmpleado * inicLista()
{
    return NULL;
}


/* 1.a Función para crear un nodo */
nodoEmpleado* crearNodo(stEmpleado empleado)
{
    nodoEmpleado* nuevoNodo = (nodoEmpleado*) malloc(sizeof(nodoEmpleado));
    nuevoNodo->dato = empleado;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}


/* 1.b Función para agregar un nodo al final de una lista de forma recursiva */
nodoEmpleado* agregarAlFinal(nodoEmpleado* lista, nodoEmpleado* nuevoNodo)
{


    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        lista->siguiente = agregarAlFinal(lista->siguiente, nuevoNodo);

    }

    return lista;

}

/* 1.c Función para cargar la lista desde el archivo secuencial: */
nodoEmpleado* cargarEmpleadosDesdeArchivo(nodoEmpleado* lista, char nombreArchivo[])
{

    FILE* archi = fopen(nombreArchivo, "rb");

    stEmpleado empleado;

    if (archi)
    {

        while (fread(&empleado, sizeof(stEmpleado), 1, archi) )
        {
            lista = agregarAlFinal(lista, crearNodo(empleado));
        }

        fclose(archi);

    }

    return lista;
}


/* 2.  Mostrar la lista */
void mostrarEmpleado(stEmpleado empleado)
{
    printf("ID: %d\n", empleado.id);
    printf("Nombre: %s %s\n", empleado.nombre, empleado.apellido);
    printf("DNI: %s\n", empleado.dni);
    printf("Edad: %d\n", empleado.edad);
    printf("Género: %c\n", empleado.genero == 'm' ? 'Masculino' : 'Femenino');
    printf("Sueldo: %.2f\n", empleado.nomina);
    printf("Baja: %s\n", empleado.baja == 1 ? "Sí" : "No");
}


void mostrarNodo(nodoEmpleado * e)
{

    printf("\n-------------------");
    mostrarEmpleado(e->dato);
    printf("\n SIG:...........%p", e->siguiente);

}

void mostrarListaRecusiva(nodoEmpleado * lista)
{

    if(lista)
    {
        mostrarNodo(lista);
        mostrarListaRecusiva(lista->siguiente);
    }
}

/* 3.a Función para contar empleados de forma recursiva: */
int cantEmpleados (nodoEmpleado * lista)
{

    int rta = 0;

    if(lista)
    {
        rta = 1 + cantEmpleados(lista->siguiente);
    }

    return rta;

}


/* 3.b Funcion para contar empleados con salario digno */
int cantEmpleadosSalarioDigno(nodoEmpleado * lista, float canastaBasica)
{

    int cant = 0;

    if(lista)
    {
        if(lista->dato.nomina >= canastaBasica)
        {
            cant = 1 + cantEmpleadosSalarioDigno(lista->siguiente, canastaBasica);
        }
        else
        {

            cant = 0 + cantEmpleadosSalarioDigno(lista->siguiente, canastaBasica);
        }
    }
    return cant;

}


/* 3.c Funcion para sumar todos los salarios */
float sumarSalarios(nodoEmpleado* lista)
{

    float suma = 0;

    if (lista)
    {
        suma = lista->dato.nomina + sumarSalarios(lista->siguiente);
    }

    return suma;
}

/* 3.d Subprograma que muestra los resultados: */

void mostrarResultados(nodoEmpleado* lista, float canastaBasica)
{
    int totalEmpleados = cantEmpleados(lista);
    int empleadosDignos = cantEmpleadosSalarioDigno(lista, canastaBasica);
    float sumaSalarios = sumarSalarios(lista);
    float promedio = sumaSalarios / totalEmpleados;

    printf("Cantidad total de empleados: %d\n", totalEmpleados);
    printf("Cantidad de empleados con salario digno: %d\n", empleadosDignos);
    printf("Promedio de salario de la empresa: $%.2f\n", promedio);
}


/* 4.a Funcion que busca empleado con mayor sueldo */
nodoEmpleado* buscarMayorSueldo(nodoEmpleado* lista)
{
    nodoEmpleado* mayor = lista;
    while (lista != NULL)
    {
        if (lista->dato.nomina > mayor->dato.nomina)
        {
            mayor = lista;
        }
        lista = lista->siguiente;
    }
    return mayor;

}

/* 4.b  Función para eliminar un nodo de la lista por DNI: */
stEmpleado borrarNodo(nodoEmpleado ** lista, char dni[])
{
    nodoEmpleado * aux =  NULL;
    nodoEmpleado * ante = NULL;
    nodoEmpleado * seg = NULL;

    stEmpleado empleado;
    itoa(-1, empleado.dni,10);

    if(*lista)
    {
        if(atoi((*lista)->dato.dni) == atoi(dni))
        {

            aux = (*lista);
            empleado = aux->dato;
            (*lista) = (*lista)->siguiente;
            free(aux);
        }
        else
        {
            ante = (*lista);
            seg = (*lista)->siguiente;

            while(seg && atoi(seg->dato.dni) != atoi(dni))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            if(seg)
            {
                ante->siguiente= seg->siguiente;
                empleado = seg->dato;
                free(seg);
            }
        }
    }
    return empleado;
}


/* 4.c Subprograma para obtener los 10 mejores sueldos: */

nodoEmpleado* agregarAlPrincipio(nodoEmpleado* lista, nodoEmpleado* nuevoNodo)
{
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

nodoEmpleado* obtenerMejoresSueldos(nodoEmpleado* listaOriginal)
{
    nodoEmpleado* listaMejoresSueldos = inicLista();
    int i = 0;

    while(i < 10 && listaOriginal)
    {
        nodoEmpleado* mayor = buscarMayorSueldo(listaOriginal);
        stEmpleado empleadoEliminado = borrarNodo(&listaOriginal, mayor->dato.dni);
        listaMejoresSueldos = agregarAlPrincipio(listaMejoresSueldos, crearNodo(empleadoEliminado));
        i++;
    }
    return listaMejoresSueldos;
}















