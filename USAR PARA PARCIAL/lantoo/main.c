#include <stdio.h>
#include <stdlib.h>
funcionRecorrer(char topo[],char h,char b);
int main()
{
    int dato;
    char topo[5] = {'h','i','i','d'};


     dato = funcionRecorrer(topo,'h','a');
    printf("%d",dato);
}
int funcionRecorrer(char topo[],char caracteraBuscar,char CaracterARemplazar)
{
    int cont = -1;
    int flag = 0;
    int i;
    for(i=0;i<5;i++)
    {
        if(topo[i] == caracteraBuscar)
        {
            topo[i] = CaracterARemplazar;
            if(flag == 0)
            {
                cont = cont +2;
                flag = 1;
            }
            else
            {
                cont = cont + 1;
                flag = 1;
            }

        }
    }
    return cont ;

}
