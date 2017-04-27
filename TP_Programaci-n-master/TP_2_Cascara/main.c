#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define cantidad 20


int main()
{
    Epersona persona[cantidad];

    char seguir='s';
    int opcion=0;

//    inicilizarArray(persona[cantidad]);

    while(seguir=='s')
    {

        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
    while(opcion <=0 || opcion >=6)
    {
        printf("\nError, seleccione opciones entre el 1 y el 5 \n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
    }

        switch(opcion)
        {
            case 1:
          altaPersona(persona, cantidad);

                break;
            case 2:
            bajaPersona(persona, cantidad);
                break;
            case 3:
//                imprimirPersonas(persona, cantidad);

                break;
            case 4:
  //              graficarPersona(persona, cantidad);

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
