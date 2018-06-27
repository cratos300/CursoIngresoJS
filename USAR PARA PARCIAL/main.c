#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/
int menu();

int main()
{
    Employee* auxEmpleado;
    ArrayList* lista = al_newArrayList();
    ArrayList* copia;
    int cant;
    int aux;
    FILE *archivo;
    char auxcad[20];
    int auxint;

    if(lista==NULL || archivo == NULL)
    {
        printf("Error al verificar lo nulo");
        exit(-1);
    }
    char seguir = 's';

    do
    {
        switch(menu())
        {

        case 1:
            fflush(stdin);
            printf("Ingrese el nombre del archivo");
            gets(auxcad);
            archivo = fopen(auxcad,"r");
            if(archivo==NULL)
            {
                printf("Error al leer el archivo\n");
                system("pause");
                break;
            }
            cant = parsearArchivo(lista,archivo);
            if(cant==-1)
            {
                printf("Error es nulo");
            }
            else
            {
                printf("Archivo parseado correctamente\n");
            }
            system("pause");
            break;
        case 2:
            ListarClientes(lista);
            printf("\n\n");
            system("pause");

            break;

        case 3:

            aux = lista->sort(lista,employee_compareNameyApe,1);
            if(aux == -1)
            {
                printf("Error no se pudo ordenar");
            }
            else
            {
                printf("Lista ordenada correctamente\n");
            }

            //DepurarArchivos(lista,listaNegra,depurada);

            system("pause");
            break;

        case 4:
             aux = lista->sort(lista,employee_comparemail,0);
            if(aux == -1)
            {
                printf("Error no se pudo ordenar");
            }
            else
            {
                printf("Lista ordenada correctamente\n");
            }
            system("pause");

            break;

        case 5:
            AgregarCliente(lista);

            system("pause");

            break;

        case 6:
            copia = lista->clone(lista);

            auxint = lista->containsAll(copia,lista);
            if(auxint == 1)
            {
                printf("Copia Correcta");
            }
            if(auxint == 0)
                printf("Copia incorrecta");

                ListarClientes(copia);


            system("pause");

            break;

        case 7:
            lista->clear(lista);
            system("pause");
            break;

            case 8:
                 ListarClientes(copia);
            system("pause");
            break;

            case 9:
            system("pause");
            break;

            case 10:
            system("pause");
            break;

            case 11:
            seguir = 'n';
            break;

        }
    }
    while(seguir == 's');


    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. Cargar datos desde data.csv\n");
    printf("2. Listar Clientes\n");
    printf("3. Ordenar por nombre y apellido\n");
    printf("4. Ordenar por mail\n");
    printf("5. Agregar un Cliente\n");
    printf("6. Elimina un Cliente\n");
    printf("7. Modificar Cliente (Nombre, Apellido y Mail)\n");
    printf("8. Listar Clientes\n");
    printf("9. Guardar datos en data.csv (modo texto)\n");
    printf("10. Guardar datos en data.bin (modo binario)\n");
    printf("11. salir \n");
    printf("Indique su Opcion\n");
    scanf("%d", &opcion);

    return opcion;
}



