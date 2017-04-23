#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define cantidad 20
#include <string.h>


int main()
{
    Epersona persona[cantidad];


    char seguir='s';
    int opcion=0;
    int dni[cantidad], estado[cantidad]= {0}, i, j;
    int auxInt, flagEncontro=0;
    char nombres[cantidad][50], auxString[20];
    int edad[cantidad];


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            altaPersona(persona, cantidad);
                break;
            case 2:
            bajaPersona(persona, cantidad);
                break;
            case 3:
            imprimirPersonas(persona, cantidad);
            printf("DNI\tnombre\tedad\n");
            for(i=0; i<cantidad; i++)
            {
                if(estado[i]!=0)
                    printf("%d\t%s\t%.2f\n", dni[i],nombres[i],edad[i]);
            }
                break;
            case 4:

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
