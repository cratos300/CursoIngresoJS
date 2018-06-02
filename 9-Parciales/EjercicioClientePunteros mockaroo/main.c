#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void cargar(Cliente* array[],int cantidad);
void mostrar(Cliente* array[],int cantidad);
void modificar(Cliente* array[], int cantidad);


int main()
{
    Cliente* arrayPunteroClientes[50];
    cargar(arrayPunteroClientes,10);
    mostrar(arrayPunteroClientes,10);
    modificar(arrayPunteroClientes, 10);
    mostrar(arrayPunteroClientes,10);
    return 0;
}

void cargar(Cliente* array[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        array[i] = cliente_newP("32911995", "20-32911995-6", "Sebastian", "Pasquini", i, -1);
    }
}

void mostrar(Cliente* array[],int cantidad)
{
    int i;
    char dni[10];
    char cuit[50];
    char nombre[50];
    char apellido[50];
    float altura;
    int id;
    for(i=0; i<cantidad; i++)
    {
        cliente_getDni(array[i], dni);
        cliente_getCuit(array[i], cuit);
        cliente_getNombre(array[i], nombre);
        cliente_getApellido(array[i], apellido);
        cliente_getAltura(array[i], &altura);
        cliente_getId(array[i],&id);
        printf("\nDni: %s\nCuit: %s\nNombre: %s\nApellido: %s\nAltura: %f\nId: %d\n",
               dni, cuit, nombre, apellido, altura, id);
    }
}

void modificar(Cliente* array[], int cantidad)
{
    int i;
    Cliente* auxiliarCliente;
    for(i = 5; i < 10; i++)
    {
        auxiliarCliente = cliente_getById(array, cantidad, i);
        if(auxiliarCliente != NULL)
        {
            cliente_setAltura(auxiliarCliente, 88);
        }
    }
}

