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

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
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
                break;
            case 4:
                graficarPersona(persona, cantidad);

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
