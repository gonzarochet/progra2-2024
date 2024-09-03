#include <stdio.h>
#include <stdlib.h>

#define AR_ARCHIVO "numeros.dat"

int main()
{
    int arreglo[10];
    cargaRandomArregloEnteros(arreglo);
    arrayToArchi(arreglo,10, AR_ARCHIVO);
    showArchi(AR_ARCHIVO);

    testArchi2(AR_ARCHIVO);

    printf("\n");
    showArchi(AR_ARCHIVO);


    return 0;
}

/// 1. Calcular el factorial de un n�mero en forma recursiva.
int factorial(int n)
{

    int rta;

    if(n == 1)
    {
        rta =  1;
    }
    else
    {
        rta =  factorial(n-1)* n;
    }

    return rta;
}

/// 2. Calcular la potencia de un numero en forma recursiva.
float potencia(int n, int exp)
{
    float rta;

    if(exp == 1)
    {
        rta = n;
    }
    else
    {
        rta =  (float)(n*(potencia(n,exp-1)));
    }

    return rta;

}

/// 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void mostrarArregloRecursivo(int a[], int v, int i)
{

    if(i<v)
    {
        printf("%d |", a[i]);
        mostrarArregloRecursivo(a,v, i+1);
    }
}
// version sin usar una variable auxiliar
void mostrarArregloRecursivoPro (int a[], int v)
{
    if(v>0)
    {
        mostrarArregloRecursivoPro(a,v-1);
        printf("%d |", a[v-1]);
    }
}


/// 4. Recorrer un arreglo comenzando desde la posici�n 0 y mostrar sus elementos en forma invertida (recursivo).
void mostrarArregloInvertidoRecursivo(int a[], int v, int i)
{

    if(i<v)
    {
        mostrarArregloRecursivo(a,v, i+1);
        printf("%d |", a[i]);
    }
}

void mostrarArregloInvertidoRecursivoPro(int a[],int v)
{
    if(v>0)
    {
        printf("%d |",a[v-1]);
        return mostrarArregloInvertidoRecursivoPro(a,v-1);
    }
}


/// 5. Determinar en forma recursiva si un arreglo es capicua.
int esCapicuaRecursivo (int a[], int i, int v)
{
    int flag = 1;

    if(i<v)
    {
        if(a[i] == a[v-1])
        {
            flag = esCapicuaRecursivo(a, i+1, v-1);
        }
        else
        {
            flag = 0;
        }

    }
    return flag;

}

/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
/// Implicita la condición de corte
int sumaElementosArregloRecursivo(int a[], int v, int i)
{

    int rta = 0;

    if(i<v)
    {
        rta = a[i] + sumaElementosArregloRecursivo(a,v,i+1);
    }

    return rta;

}

/// Explícita la condición de corte
int sumaElementosArregloRecursivoExplicita(int a[], int v, int i)
{
    int rta;

    if(i == v)
    {
        rta = 0;
    }
    else
    {
        rta = a[i] + sumaElementosArregloRecursivoExplicita(a,v,i+1);
    }

    return rta;

}

/// 6.5 Sumar de forma recursiva elementos de un arreglo de acuerdo a una condición

int sumaElementosArregloRecursivoCondicion(int a[], int v, int i, int cond)
{
    int rta;

    if(i == v)
    {
        rta = 0;
    }
    else
    {
        if(a[i] > cond)
        {
            rta = a[i] + sumaElementosArregloRecursivoCondicion(a,v,i+1,cond);
        }
        else
        {

            rta = 0 + sumaElementosArregloRecursivoCondicion(a,v,i+1,cond);
        }

    }

    return rta;

}


/// 7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscaMenorElemento(int a[],int v, int i, int pos)
{
    if(i==v)
    {
        pos = v-1;
    }
    else
    {
        pos = buscaMenorElemento(a,v,i+1,pos);
        if(a[i]<a[pos])
        {
            pos = i;
        }

    }
    return pos;

}

int buscaMenorElementoPosPro(int a[],int v)
{
    int posMenor;
    if(v==0)
    {
        posMenor = 0;
    }
    else
    {
        posMenor = buscaMenorElementoPosPro(a,v-1);
        if(a[v] < a[posMenor])
        {
            posMenor = v;
        }
    }

    return posMenor;
}

/// ARCHIVOS

/// 8. Buscar el menor elemento de un archivo de numeros enteros de forma recursiva. (desde el mismo archivo)

int menorEnArchivo (FILE * arch)
{

    int menor;
    int aux;

    if(fread(&aux,sizeof(int),1,arch)==0)
    {

        fseek(arch, -1*sizeof(int), SEEK_END);
        fread(&menor, sizeof(int),1,arch);
    }
    else
    {
        menor = menorEnArchivo(arch);

        if(aux<menor)
        {
            menor=aux;
        }
    }
    return menor;
}


/// 9. Invertir los elementos de un archivo de n�meros enteros de forma recursiva.

void invertirElementosArchivoRecursivo(FILE * buffer, FILE * buffer2, int posInicio, int posFinal)
{

    if(posInicio < posFinal)
    {
        int valueInit, valueEnd;

        // Mover el puntero al inicio y final respectivamente
        fseek(buffer,posInicio * sizeof(int), SEEK_SET);
        fseek(buffer2,posFinal * sizeof(int), SEEK_SET);

        // Leer los valores en esas posiciones
        fread(&valueInit, sizeof(int), 1, buffer);
        fread(&valueEnd, sizeof(int), 1, buffer2);

        // Volver a las posiciones para escribir los valores invertidos
        fseek(buffer, posInicio * sizeof(int), SEEK_SET);
        fwrite(&valueEnd, sizeof(int), 1, buffer);
        fseek(buffer2, posFinal * sizeof(int), SEEK_SET);
        fwrite(&valueInit, sizeof(int), 1, buffer2);

        // Llamada recursiva
        invertirElementosArchivoRecursivo(buffer, buffer2, posInicio + 1, posFinal - 1);

    }


}


void testArchi2(char nameFile[])
{
    FILE * buffer = fopen(nameFile,"rb+");
    FILE * buffer2 = fopen(nameFile,"rb+");

    invertirElementosArchivoRecursivo(buffer,buffer2,0,cantElementosArchivo(nameFile, sizeof(int)) -1 );

    fclose(buffer);
    fclose(buffer2);
}




/// EXTRA


int cantElementosArchivo(char nombreArchivo[], int tamanioEstructura){

    FILE * buffer = fopen(nombreArchivo,"rb");
    int cant = 0;

    if(buffer){
        fseek(buffer,0, SEEK_END);
        cant = ftell(buffer) / tamanioEstructura;
        fclose(buffer);
    }

    return cant;


}

void arrayToArchi(int array[], int v, char nombreArchivo[])
{

    FILE * buffer = fopen(nombreArchivo,"wb");

    if(buffer)
    {
        for(int i = 0; i<v; i++)
        {
            fwrite(&array[i],1,sizeof(int),buffer);
        }
        fclose(buffer);
    }

}


void showArchi(char nombreArchivo[])
{
    FILE * buffer = fopen(nombreArchivo,"rb");
    int value;
    if(buffer)
    {
        while(fread(&value,1,sizeof(int),buffer)>0)
        {
            printf(" %d -", value);
        }
        fclose(buffer);
    }

}


int cargaRandomArregloEnteros(int a[])
{
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 10 + 1;
    }

    return 10;

}














