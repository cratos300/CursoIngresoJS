#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"


int parsearArchivo(ArrayList *lista, FILE *archivo)
{
    char  auxid[20];
    char auxnombre[50];
    char auxapellido[50];
    char auxemail[50];
    char auxgenero[3];
    char auxprofesion[50];
    char auxusuario[50];
    char auxnacionalidad[50];

    Employee* Nuevo_Empleado;
    int retornar = -1;
    if(lista == NULL && archivo == NULL)
    {
        printf("Error");
        exit(-1);
    }
    fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxid,auxnombre,auxapellido,auxemail,auxgenero,auxprofesion,auxusuario,auxnacionalidad);
    while(!feof(archivo))
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxid,auxnombre,auxapellido,auxemail,auxgenero,auxprofesion,auxusuario,auxnacionalidad);
        Nuevo_Empleado = employee_new();
        Nuevo_Empleado->id = atoi(auxid);;
        strcpy(Nuevo_Empleado->nombre,auxnombre);
        strcpy(Nuevo_Empleado->apellido,auxapellido);
        strcpy(Nuevo_Empleado->email,auxemail);
        Nuevo_Empleado->genero = auxgenero[0];
        strcpy(Nuevo_Empleado->profesion,auxprofesion);
        strcpy(Nuevo_Empleado->usuario,auxusuario);
        strcpy(Nuevo_Empleado->nacionalidad,auxnacionalidad);
        lista->add(lista,Nuevo_Empleado);
        retornar = 0;
    }
    return retornar;
}

void ListarClientes(ArrayList *lista)
{
    int i;
    Employee *AuxEmpleado;
    int cont = 0;
    for(i=0; i<lista->len(lista); i++)
    {
        if(cont==10)
        {
            system("pause");
        }
        AuxEmpleado = (Employee*)lista->get(lista,i);
        employee_print(AuxEmpleado);
        cont ++;
    }
}
void AgregarCliente(ArrayList *lista)
{
    Employee *auxCliente;

    long int  auxid;
    char auxnombre[50];
    char auxapellido[50];
    char auxemail[50];
    char auxgenero;
    char auxprofesion[50];
    char auxusuario[50];
    char auxnacionalidad[50];

    fflush(stdin);
    printf("Ingrese su numero de dni");
    scanf("%ld",&auxid);
    fflush(stdin);
    printf("Ingrese su nombre");
    gets(auxnombre);
    fflush(stdin);
    printf("Ingrese su apellido");
    gets(auxapellido);
    fflush(stdin);
    printf("Ingrese su numero de email");
    gets(auxemail);
    fflush(stdin);
    printf("Ingrese su genero");
    scanf("%c",&auxgenero);
    fflush(stdin);
    printf("Ingrese su profesion");
    gets(auxprofesion);
    fflush(stdin);
    printf("Ingrese su nombre de usuario");
    gets(auxusuario);
    fflush(stdin);
    printf("Ingrese su nacionalidad");
    gets(auxnacionalidad);

    auxCliente = employee_new();

    auxCliente->id = auxid;
    strcpy(auxCliente->nombre,auxnombre);
    strcpy(auxCliente->apellido,auxapellido);
    strcpy(auxCliente->email,auxemail);
    auxCliente->genero = auxgenero;
    strcpy(auxCliente->profesion,auxprofesion);
    strcpy(auxCliente->usuario,auxusuario);
    strcpy(auxCliente->nacionalidad,auxnacionalidad);

    lista->add(lista,auxCliente);
}

/*void DepurarArchivos(ArrayList* lista,ArrayList* listaNegra,ArrayList* depurada)
{

}*/
/*int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL){

    Employee* empA = (Employee*) pEmployeeA;
    Employee* empB = (Employee*) pEmployeeB;
    return strcmp(empA->name, empB->name);
    }
    return 0;
}
*/
int employee_compareNameyApe(void* pEmployeeA,void* pEmployeeB)
{
    int aux;
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {

        Employee* empA = (Employee*) pEmployeeA;
        Employee* empB = (Employee*) pEmployeeB;
        aux =  strcmp(empA->nombre, empB->nombre);
        if(aux == 0)
        {
            aux  = strcmp(empA->apellido, empB->apellido);
        }
    }
    return aux;
}
int employee_comparemail(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {

        Employee* empA = (Employee*) pEmployeeA;
        Employee* empB = (Employee*) pEmployeeB;
        return strcmp(empA->email, empB->email);

    }
}


void employee_print(Employee* this)
{
    if(this != NULL)
    {
        printf("%d%10s%10s\t%10s%c%10s%10s%10s\n", this->id,this->nombre,this->apellido,this->email,this->genero,this->profesion,this->usuario,this->nacionalidad);
    }
}


Employee* employee_new(void)
{
    Employee* returnAux;
    returnAux = (Employee*)malloc(sizeof(Employee));
    if(returnAux !=NULL)
    {
        strcpy(returnAux->nombre,"");
        strcpy(returnAux->apellido,"");
        strcpy(returnAux->email,"");
        returnAux->genero = ' ';
        strcpy(returnAux->profesion,"");
        strcpy(returnAux->usuario,"");
        strcpy(returnAux->nacionalidad,"");


    }
    return returnAux;
}

/*void employee_delete(Employee* this)
{
    if(this != NULL){
        this->isEmpty = 1;
    }

}
*/
/*
int employee_setId(Employee* this, int dni)
{
 if(this != NULL){
       if(dni > 0 && dni < 99999999){
        this->dni = dni;
        return 0;
       }
    }
    return -1;

}
*/

/*
int employee_getId(Employee* this)
{
    int id = -1;
     if(this != NULL){
            id = this->id;
     }
    return id;

}
*/

/*void guardarArchivoTXT(ArrayList* this)
{
    ePersona* lista = newPersona();
    FILE* f = crearArchivoTXT("listab.txt");

    if(this != NULL && lista != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            fprintf(f, "DNI,Nombre,Edad,Altura\n");
            for(int i=0; i<this->len(this); i++)
            {
                lista = this->get(this, i);
                fprintf(f, "%s,%s,%d,%.2f\n", lista->DNI, lista->nombre, lista->edad, lista->altura);
            }
        }
    }
}*/
/*void guardarArchivo(ArrayList* this)
{
    int i;
    ePersona* lista;
    FILE* f = crearArchivo("lista.bin");

    if(this != NULL)
    {
        if(f != NULL)
        {
            rewind(f);
            for (i=0; i < this->len(this); i++)
            {
                lista = (ePersona*)this->get(this, i);

                fwrite(lista, sizeof(ePersona), 1, f);
            }
            fclose(f);
        }
    }
}*/
/*void cargarArchivo(ArrayList* this)
{
    FILE* archivo = leerArchivo("lista.bin");
    ePersona aux;
    int validar;
    ePersona* lista;
    rewind(archivo);
    if(archivo != NULL)
    {
        while (!feof(archivo))
        {
            validar = fread(&aux, sizeof(ePersona), 1, archivo);
            lista = newPersona();
            if(validar == 1 && lista != NULL)
            {
                strcpy(lista->nombre, aux.nombre);
                strcpy(lista->DNI, aux.DNI);
                lista->edad = aux.edad;
                lista->altura = aux.altura;
                this->add(this, lista);
            }

            if(validar!=1)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro\n");
                    system("pause");
                    break;
                }
            }

        }
        printf("\nArchivo cargado.\n\n");
        system("pause");

        fclose(archivo);
    }
}*/
