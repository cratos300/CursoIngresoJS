#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidAltura(float altura);
int isValidCuit(char* cuit);
int isValidNombre(char* nombre);
int isValidApellido(char* apellido);
int isValidDni(char* dni);
static int ultimoId = -1;

Cliente* cliente_new()
{
    return malloc(sizeof(Cliente));
}

Cliente* cliente_newP(char* dni, char* cuit, char* nombre, char* apellido, float altura, int id)
{
    Cliente* this = cliente_new();
    if( !cliente_setDni(this, dni)
    &&  !cliente_setCuit(this, cuit)
    &&  !cliente_setNombre(this, nombre)
    &&  !cliente_setApellido(this, apellido)
    &&  !cliente_setAltura(this, altura)
    &&  !cliente_setNewId(this))
    {
        return this;
    }
    cliente_delete(this);
    return NULL;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setAltura(Cliente* this, float altura)
{
    int retorno = -1;
    if (this != NULL && isValidAltura(altura))
    {
        this->altura = altura;
        retorno = 0;
    }
    return retorno;
}

int cliente_getAltura(Cliente* this, float* altura)
{
    int retorno = -1;
    if (this != NULL && altura != NULL)
    {
        *altura = this->altura;
        retorno = 0;
    }
    return retorno;
}

int isValidAltura(float altura)
{
    return 1;
}



int cliente_setCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if (this != NULL && cuit!= NULL && isValidCuit(cuit))
    {
        strcpy(this->cuit, cuit);
        retorno = 0;
    }
    return retorno;
}

int cliente_getCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if (this != NULL && cuit != NULL && isValidCuit(cuit))
    {
        strcpy(cuit, this->cuit);
        retorno = 0;
    }
    return retorno;
}

int isValidCuit(char* cuit)
{
    return 1;
}



int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if (this != NULL && nombre!= NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if (this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int isValidNombre(char* nombre)
{
    return 1;
}




int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if (this != NULL && apellido!= NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if (this != NULL && apellido != NULL && isValidApellido(apellido))
    {
        strcpy(apellido, this->apellido);
        retorno = 0;
    }
    return retorno;
}

int isValidApellido(char* apellido)
{
    return 1;
}




int cliente_setDni(Cliente* this, char* dni)
{
    int retorno = -1;
    if (this != NULL && dni != NULL && isValidDni(dni))
    {
        strcpy(this->dni, dni);
        retorno = 0;
    }
    return retorno;
}

int cliente_getDni(Cliente* this, char* dni)
{
    int retorno = -1;
    if (this != NULL && dni != NULL)
    {
        strcpy(dni, this->dni);
        retorno = 0;
    }
    return retorno;
}




int isValidDni(char* dni)
{
    return 1;
}

int cliente_setNewId(Cliente* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        ultimoId++;
        this->id = ultimoId;
        retorno = 0;
    }
    return retorno;
}


int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}



Cliente* cliente_getById(Cliente* array[], int cantidad, int id)
{
    Cliente* retorno = NULL;
    int i;
    int auxiliarId;
    for(i = 0; i < cantidad; i++)
    {
        cliente_getId(array[i], &auxiliarId);
        if(auxiliarId == id)
        {
            retorno = array[i];
            break;
        }
    }
    return retorno;
}
