#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char dni[10];
    char cuit[50];
    char nombre[50];
    char apellido[50];
    float altura;
    int id;
}Cliente;


Cliente* cliente_new();
Cliente* cliente_newP(char* dni, char* cuit, char* nombre, char* apellido, float altura, int id);
void cliente_delete(Cliente* this);
int cliente_setAltura(Cliente* this, float altura);
int cliente_getAltura(Cliente* this, float* altura);
int cliente_setCuit(Cliente* this, char* cuit);
int cliente_getCuit(Cliente* this, char* cuit);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_setDni(Cliente* this, char* dni);
int cliente_getDni(Cliente* this, char* dni);
int cliente_setNewId(Cliente* this);
int cliente_getId(Cliente* this, int* id);


