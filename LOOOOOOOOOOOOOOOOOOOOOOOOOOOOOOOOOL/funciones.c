#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#include <ctype.h>

void mostrarProgramador(eProgramador lista)
{

    printf("%d \t %s \t %s \t\t %d \t\t %d\t\n",lista.id,lista.nombre,lista.apellido,lista.direccion,lista.numeroDeTarjeta);

}
void mostrarProgramadores(eProgramador lista[],int tam)
{
    int flag=0;
    int i;
    printf("ID \t NOMBRE \t APELLIDO\t DIRECCION\t NumTarjeta\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=0)
        {
            mostrarProgramador(lista[i]);
            flag=1;

        }

    }
    printf("----------------------------------------------------------------------------\n");
    if(flag==0)
    {
        printf("No hay  programadores para mostrar");
    }

}

void mostrarIngresoDeAutomovil(eEstacionamiento lista)
{


    char cat[11];

    if(lista.marca==1)
    {
        strcpy(cat, "ALPHA_ROMEO");
    }
    else if(lista.marca == 2)
    {
        strcpy(cat, "FERRARI");
    }
    else if(lista.marca == 3)
    {
        strcpy(cat, "AUDI");
    }
    else
    {
        strcpy(cat,"OTRO");
    }

    printf("%s \t\t %s \t\t %d \t\t %d \t\t \n\n",lista.patente,cat,lista.Identificador,lista.HorarioDeEntrada);

}




void mostrarIngresoDeAutomoviles(eEstacionamiento lista[],int tam)
{
    int flag=0;
    int i;
    printf("\nPATENTE\t MARCA \t IDENTIFICADOR\t HSDEENTRADA\t ESTADO\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=0)
        {
            mostrarIngresoDeAutomovil(lista[i]);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("No hay  Automoviles para mostrar para mostrar");
    }
}
void InicializarVector(eProgramador lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}
void InicializarVector2(eEstacionamiento lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}
int buscarLibre(eProgramador lista[],int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarLibre2(eEstacionamiento lista[],int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int BuscarProgramador2(eProgramador lista[],int dato,int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(dato==lista[i].id && lista[i].estado==1)
        {

            indice=i;
            break;
        }
    }
    return indice;
}
/*
int BuscarProgramadorEs(eEstacionamiento lista[],int dato,int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(dato==lista[i].Identificador && lista[i].estado==1)
        {
            printf("El id ya esta registrado");
            indice=i;
            break;
        }
    }
    return indice;
}
int BuscarProgramador(eEstacionamiento lista[],int dato,int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(dato==lista[i].Identificador && lista[i].estado==1)
        {
            printf("El id ya esta registrado");
            indice=i;
            break;
        }
    }
    return indice;
}*/
void AltaProgramador(eProgramador lista[], int tam)
{
    int x;
    int indice;
    int esta;
    int id;
    int a;
    char auxis[10];


    indice = buscarLibre(lista,tam);
    if(indice == -1)
    {
        printf("No hay lugar disponible");
    }
    else
    {
        do
        {
            printf("\nIngrese numero de id");
            fflush(stdin);
            scanf("%s",auxis);
            a=NumeroDigito(auxis);
        }
        while(a==0);
        id = atoi(auxis);


        esta=BuscarProgramador2(lista,id,tam);

        if(esta!=-1)
        {
            printf("Error, ese id ya esta registrado");
        }
        else
        {
            lista[indice].id = id;
            do
            {
            printf("Ingrese el nombre:");
            fflush(stdin);
            gets(lista[indice].nombre);
            x = validarLetra(lista[indice].nombre);
            }while(x==0);

            do
            {
              printf("Ingrese el apellido:");
              fflush(stdin);
              gets(lista[indice].apellido);
              x = validarLetra(lista[indice].apellido);
            }while(x == 0);

            printf("Ingrese el numero de direccion");
            fflush(stdin);
            scanf("%d",&lista[indice].direccion);
            do
            {
            printf("Ingrese el numero de tarjeta");
            fflush(stdin);
            scanf("%s",auxis);
            x=NumeroDigito(auxis);
            }while(x==0);
            lista[indice].numeroDeTarjeta = atoi(auxis);
            lista[indice].estado = 1;

        }



    }
}
int BajaProgramador(eProgramador lista[],eEstacionamiento listaEs[],int tamPro,int tamEst, int* Acum1,int* Acum2,int* Acum3,int* Acum4)
{
    int buscador;
    char patente[15];
    int auxID;
    int total=0;
    int datito;
    char respuesta;
    int horaSalida;
    char auxis[5];
    int i;
    int ab;

    printf("Ingrese el id del estacionamiento a eliminar");
    scanf("%d",&auxID);

    datito=BuscarProgramador2(lista,auxID,tamPro);

    if(datito != -1 )
    {
        printf("\nIngrese patente");
        fflush(stdin);
        gets(patente);

        buscador=buscarPatente(listaEs,patente,tamEst);
        if(buscador!= -1 && lista[datito].id == listaEs[buscador].Identificador)
        {
            printf("\nID \t NOMBRE \t APELLIDO \t DIRECCION \t NUMTARJETA\n");
            printf("%d \t %s \t\t %s \t \t %d \t\t %d \t\t%s\t\t%d\t\t\n",lista[datito].id,lista[datito].nombre,lista[datito].apellido,lista[datito].direccion,lista[datito].numeroDeTarjeta,listaEs[buscador].patente,listaEs[buscador].HorarioDeEntrada);
            fflush(stdin);
            printf("Estas seguro que desas eliminarlo?");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta == 's')
            {
                horaSalida = atoi(auxis);
                    printf("\ningrese el horario de salida");
                    fflush(stdin);
                    scanf("%d",&horaSalida);
                    horaSalida=funcionDoble(horaSalida,listaEs[buscador].HorarioDeEntrada);



                horaSalida = horaSalida  - listaEs[buscador].HorarioDeEntrada;

                if(listaEs[buscador].marca == 1)
                {

                    total =horaSalida*150;
                    printf("\n%d * 150\n",horaSalida);
                    *Acum1 = total;
                }
                else if(listaEs[buscador].marca == 2)
                {
                    total = horaSalida*175;
                    printf("\n%d * 175\n",horaSalida);
                    *Acum2 = total;
                }
                else if(listaEs[buscador].marca == 3)
                {
                    total = horaSalida*200;
                    printf("%d * 200\n",horaSalida);

                    *Acum3 = total;
                }
                else
                {
                    total = horaSalida*250;
                    printf("\n %d * 250\n",horaSalida);
                    *Acum4 = total;
                }

                listaEs[buscador].estado=0;
                printf("Baja correcta");


                for(i=0; i<tamEst; i++)
                {
                    if(listaEs[buscador].Identificador==lista[i].id)
                    {
                        printf("\nID   \tNombre    \tApellido       \tDireccion           \tTarjeta    \n");
                        printf("--------------------------------------------------------------------------------------------------------------\n");
                        mostrarProgramador(lista[i]);
                        printf("\nPatente   \tMarca   \tIdentificador \tHora Entrada \tPrecio\n");
                        printf("--------------------------------------------------------------------------------------------------------------\n");
                        mostrarIngresoDeAutomovil(listaEs[buscador]);
                        printf("\t\t\t\t\t\t\t\t $%d",total);


                    }

                }

            }
            else
            {
                printf("Accion cancelada");

            }
        }

        else
        {
            printf("La patente no coincide con el id");
        }
    }

    else
    {
        printf("Ese numero de id no existe!!!");
    }

    return total;

}
void Modificar(eProgramador lista[], int tam)
{
    int auxID;
    int datito;
    char respuesta;
    printf("Ingrese el id del cliente a modificar");
    scanf("%d",&auxID);
    datito=BuscarProgramador2(lista,auxID,tam);
    if(datito == -1)
    {
        printf("Ese numero de id no existe!!!\n");
        system("pause");

    }
    else
    {
        printf("ID\t\tNOMBRE\t\tAPELLIDO\t\tDIRECCION\t\tNUMTARJETA\n");
        printf("%d\t\t%s\t\t%s\t\t\t%d\t\t\t%d\n",lista[datito].id,lista[datito].nombre,lista[datito].apellido,lista[datito].direccion,lista[datito].numeroDeTarjeta);
        fflush(stdin);
        printf("Estas seguro que desas modificarlo?");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            printf("Ingrese el nuevo numero de tarjeta");
            scanf("%d",&lista[datito].numeroDeTarjeta);
            printf("Modificacion exitosa!!!\n");
            printf("ID\t\tNOMBRE\t\tAPELLIDO\t\tDIRECCION\t\tNUMTARJETA\n");
            printf("%d\t\t%s\t\t%s\t\t\t%d\t\t\t%d\n",lista[datito].id,lista[datito].nombre,lista[datito].apellido,lista[datito].direccion,lista[datito].numeroDeTarjeta);
            system("pause");
        }
        else
        {
            printf("Accion cancelada");

        }
    }
}
void AltaDeEstacionamiento(eEstacionamiento lista[],eProgramador listaPro[], int tamPro,int tamEst)
{

    int indice;
    int id;
    int topo;
    int devolver;
    char auxPatente[20];



    indice = buscarLibre2(lista,tamEst);
    if(indice == -1)
    {
        printf("No hay lugar disponible");
    }
    else
    {
        printf("Ingrese identificador numerico");
        fflush(stdin);
        scanf("%d",&lista[indice].Identificador);
        id = lista[indice].Identificador;
        topo = Verificar(listaPro,id,tamPro);
        if(topo != -1)
        {
            printf("Ingrese La patente");
            fflush(stdin);
            gets(auxPatente);
            devolver = buscarPatente(lista,auxPatente,tamEst);
            if(devolver!= -1)
            {
                printf("Error, esa patente es de otro auto");
            }
            else
            {
                strcpy(lista[indice].patente,auxPatente);
                printf("Ingrese la marca... 1..ALPHA ROMEO,2...FERRARI,3...AUDI,4....OTRO");
                fflush(stdin);
                scanf("%d",&lista[indice].marca);
                printf("Ingrese el horario de entrada");
                fflush(stdin);
                scanf("%d",&lista[indice].HorarioDeEntrada);
                lista[indice].HorarioDeEntrada=validarEntrada(lista[indice].HorarioDeEntrada);
                lista[indice].estado = 1;
            }
        }
        else
        {
            printf("El id que ingreaste No esta registrado,Registrate primero.");
        }





    }
}

int Verificar (eProgramador listaPRO[],int id,int tam)
{

    int indice=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listaPRO[i].id == id)
        {
            indice = i;
            break;

        }
    }
    return indice;
}

void RecorrerAmbasFunciones(eProgramador listaPro[],eEstacionamiento listaEst[],int tamPro,int tamEst)
{
    int i;
    int j;

    printf("\nPATENTE \t MARCA \t IDENTIFICACION \t HSENTRADA\n");
    printf("----- \t\t ----- \t ----------- \t\t ----------\n\n");
    for(i=0; i<tamEst; i++)
    {
        if(listaEst[i].estado == 1)
        {


            for(j=0; j<tamPro; j++)
            {

                if(listaPro[j].estado == 1)
                {

                    if(listaEst[i].Identificador == listaPro[j].id)
                    {
                        mostrarIngresoDeAutomovil(listaEst[i]);
                        mostrarIngresoDeAutomovileeeee(listaEst[i]);
                        mostrarProgramadorrrr(listaPro[j]);
                        printf("\n----------------------------------------------------------------------\n");


                    }

                }
            }

        }
    }



}

/*void ordenar (eProgramador listaPro, eEstacionamiento listaEst, int tamPro, int tamEsc)
{

    for(i=0;i<tamEsc-1;i++)
    {
        if(listaEst == 1)
        {
            for(j=i+1;j<tamPro;j++)
            {
                if(tamPro == 1)
                {
                    if(listaEst.Identificador == listaPro.id)
                    {

                    }
                }
            }
        }
    }
}*/
void mostrarIngresoDeAutomovileeeee(eEstacionamiento lista)
{


    char cat[11];

    if(lista.marca==1)
    {
        strcpy(cat, "ALPHA_ROMEO");
    }
    else if(lista.marca == 2)
    {
        strcpy(cat, "FERRARI");
    }
    else if(lista.marca == 3)
    {
        strcpy(cat, "AUDI");
    }
    else
    {
        strcpy(cat, "OTRO");
    }

    printf("%s---->",cat);
}
void mostrarProgramadorrrr(eProgramador lista)
{

    printf("%s\n",lista.nombre);

}
void ordenarAutomoviles(eEstacionamiento cars[], int tam)
{
    int i, j;

    eEstacionamiento aux;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (cars[i].HorarioDeEntrada > cars[j].HorarioDeEntrada)
            {
                aux = cars[i];
                cars[i] = cars[j];
                cars[j] = aux;
            }

            else

                if (cars[j].HorarioDeEntrada == cars[i].HorarioDeEntrada)
                {
                    if (strcmp(cars[i].patente, cars[j].patente) > 0)
                    {
                        aux = cars[i];
                        cars[i] = cars[j];
                        cars[j] = aux;
                    }
                }
        }
    }
}
void hardcodearcliente(eProgramador cars[],int tam)
{
    int idd [] = {1, 2, 3, 4, 101};
    char nombree[][10] =  {{"ROBERTO"},{"MATIAS"}, {"LUCAS"}, {"JULIAN"}, {"GERMAN"}};
    char apellidoo[][10] =  {{"GOMEZ"}, {"PEREZ"}, {"GIMENEZ"}, {"CARLOS"}, {"GIMENEZ"}};
    int direccionn[] = {20, 19, 12, 13, 13};
    int numeroTarjetaa[] = {23,24,54,45,54};
    int estadoo[] = {1,1,1,1,1};
    int i;

    for (i = 0; i < tam; i++)
    {
        cars[i].id = idd[i];
        strcpy(cars[i].nombre, nombree[i]);
        strcpy(cars[i].apellido, apellidoo[i]);
        cars[i].direccion = direccionn[i];
        cars[i].numeroDeTarjeta = numeroTarjetaa[i];
        cars[i].estado = estadoo[i];
    }

}
void hardcodearautomoviles(eEstacionamiento cars[],int tam)
{
    char patente[][10] =  {{"ABC123"}, {"DFG456"}, {"HIJ674"}, {"JRD842"}, {"KLM654"}};
    int marca[] =  {1, 3, 3, 3, 3};
    int dueno[] = {101, 101, 1, 2, 101};
    int horario[] = {1, 3, 4, 5, 6};
    int estadoo[] = {1,1,1,1,1};
    int i;

    for (i = 0; i < tam; i++)
    {
        strcpy(cars[i].patente, patente[i]);
        cars[i].Identificador = dueno[i];
        cars[i].marca = marca[i];
        cars[i].HorarioDeEntrada = horario[i];
        cars[i].estado = estadoo[i];
    }

}


void BuscarAudi(eEstacionamiento Est[], eProgramador Pro[],int tamEst, int tamPro)
{
    printf("\t\t\tLOS CLIENTES CON LA MARCA AUDI SON:");
    printf("\n\nNUM ID\t PATENTE\t NOMBRE");
    int i;
    int j;
    for(i=0; i<tamEst; i++)
    {
        if(Est[i].marca == 3 && Est[i].estado == 1)
        {
            printf("\n%d",Est[i].Identificador);
            printf("\t%s",Est[i].patente);
            for(j=0; j<tamPro; j++)
            {
                if(Est[i].Identificador == Pro[j].id && Pro[j].estado == 1)
                {

                    printf("\t\t%s",Pro[j].nombre);
                }
            }
        }
    }
}
int buscarPatente(eEstacionamiento listaAutomovil[], char coincidencia[], int tamAutomovil)
{
    int indice= -1;
    int i;

    for(i=0; i<tamAutomovil; i++)
    {
        if(strcmp(listaAutomovil[i].patente,coincidencia)==0 && listaAutomovil[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int NumeroDigito (char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("Ingrese numero NO LETRA");
            return 0;

        }
    }
    return 1;
}
int validarLetra (char palabra[])
{
    int i;
    for(i=0;i<strlen(palabra);i++)
    {
        if(!(isalpha(palabra[i])))
        {

            return 0;
        }
    }
    return 1;
}
int validarEntrada (int dato)
{
    while(dato <0 || dato >24)
    {
        printf("Reingrese horario mayor a 0 y menor a 24");
        scanf("%d",&dato);
    }
    return dato;
}
int validarDiaHora(int dato,int datito)
{
    while(dato<datito)
    {
        printf("Error no se puede quedas mas de 24 hs");
        scanf("%d",&dato);
    }
    return dato;
}
int funcionDoble(int dato,int datito)
{
    while(dato<0 || dato>24 || dato<datito)
    {
        printf("Error,ingrese un horario mayor a 0 y menor a 24, y una salida mayor a la entrada.");
        scanf("%d",&dato);
    }
    return dato;
}
