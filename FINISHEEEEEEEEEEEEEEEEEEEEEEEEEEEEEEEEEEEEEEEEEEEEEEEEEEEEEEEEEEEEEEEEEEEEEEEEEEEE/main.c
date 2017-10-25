#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 7
#include "funciones.h"
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3


//a = Senior
//b = SemiSenior
//c = Junior

int menu();

int main()
{
    eProgramador equipo[TAM];
    eEstacionamiento equipo2[TAM];
    int Totalito=0;
    int total = 0;
    int Acum1= 0 ;
    int Acum2 = 0;
    int Acum3 = 0;
    int Acum4 = 0;
    int uno = 0;
    int dos = 0;
    int tres = 0;
    int cuatro = 0;


    int salir = 1;

    InicializarVector(equipo,TAM);
    InicializarVector2(equipo2,TAM);
    hardcodearcliente(equipo, 5);
    hardcodearautomoviles(equipo2, 5);
    do
    {
        switch(menu())
        {


        case 1:

            system("cls");
            AltaProgramador(equipo,TAM);
            getch();



            break;

        case 2:
            system("cls");
            AltaDeEstacionamiento(equipo2,equipo,TAM,TAM);
            getche();
            break;





        case 3:
            system("cls");
            Totalito=BajaProgramador(equipo,equipo2,TAM,TAM,&Acum1,&Acum2,&Acum3,&Acum4);
            total = total + Totalito;
            uno = uno + Acum1;
            dos = dos + Acum2;
            tres = tres + Acum3;
            cuatro = cuatro + Acum4;
            printf("\nEl precio total de ALPHA_ROMEO ES: %d",uno);
            printf("\nEl precio total de FERRARI ES: %d",dos);
            printf("\nEl precio total de AUDI ES: %d",tres);
            printf("\nEl precio total de OTROS ES: %d",cuatro);
            printf("\n\nEl TOTAL DE TODAS LAS MARCAS ES: %d",total);
            Acum1 = 0;
            Acum2 = 0;
            Acum3 = 0;
            Acum4 = 0;

            getch();

            break;

        case 4:
            system("cls");
            ordenarAutomoviles(equipo2, TAM);
            mostrarProgramadores(equipo,TAM);
            RecorrerAmbasFunciones(equipo,equipo2,TAM,TAM);
            BuscarAudi(equipo2,equipo,TAM,TAM);
            getch();

            break;



        case 5:
            Modificar(equipo,TAM);
            break;
        case 6:
            salir = 0;
            break;
        }

    }
    while(salir);
    return 0;
}


int menu()
{
    int opcion;
    system("cls");
    printf("\n***Programadores***\n\n\n");
    printf("1- Alta del duenio\n");
    printf("2- Alta Estacionamiento\n");
    printf("3- Mostrar Automoviles\n");
    printf("4- Listado de Dueños\n");
    printf("5- Modificar Tarjeta\n");
    printf("6- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}


