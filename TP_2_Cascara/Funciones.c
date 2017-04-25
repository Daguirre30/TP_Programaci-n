#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


//funcion para dar de alta una persona

void altaPersona(Epersona persona[], int cantidad)
{

    int flagEncontro=0, i;

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 0) // si esta desocupada esa posicion
        {
            printf("Ingrese DNI\n");
            scanf("%d", &persona[i].dni);
            persona[i].estado = 1;
            printf("Ingrese el nombre de la persona\n");// ingreso nombre, edad, etc.
            fflush(stdin);
            scanf("%s", persona[i].nombre);
            printf("Ingrese edad\n");
            scanf("%d", &persona[i].edad);
            fflush(stdin);
            flagEncontro = 1;

            break;
        }
    }
    if(flagEncontro == 0)
    {
        printf("No hay espacio suficiente\n");
    }
}

//funcion que inicializa el Array

void inicilizarArray(Epersona personas[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        personas[i].estado = 0;
    }

}
// funcion que da de baja la persona

void bajaPersona(Epersona persona[], int cantidad)
{
    int flagEncontro =0, i;
    int auxiliar;
    char respuesta;
    printf("Ingrese DNI\n");
    scanf("%d", &auxiliar);

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado==1)
        {
            if(auxiliar = persona[i].dni)
            {
                printf("DNI\tNombre\tEdad\n");
                printf("%d\t%s\t%d\n",persona[i].dni, persona[i].nombre, persona[i].edad);
                printf("Estas seguro de eliminar este dato s/n\n");

                respuesta = getche();
                fflush(stdin);
                if(respuesta == 's')
                {
                    persona[i].estado = 0;
                }
                else
                {
                    printf("Accion cancelada por el usuario\n");
                }

                flagEncontro = 1;
                break;
            }
        }
    }

    if(flagEncontro == 0)
    {
        printf("El dato no existe\n");
    }
}

// imprimir las personas ordenadas por Nombre o por DNI

void imprimirPersonas(Epersona persona[], int cantidad)
{
   Epersona personaAux;
    int i, j;
    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++){
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0){
                personaAux = persona[i];
                persona[i] = persona[j];
                persona[j] =  personaAux;
            }
            else{
                if(strcmp(persona[i].nombre, persona[j].nombre) ==0 ){
                    if(persona[i].dni > persona[j].dni){
                        personaAux = persona[i];
                        persona[i] = persona[j];
                        persona[j] =  personaAux;
                    }
                }
            }
        }

    }
    for(i=0; i<cantidad-1; i++)
    {
        if(persona[i].estado == 1)
        {
          printf("DNI\t    Nombre\tEdad\n");


          printf("%d\t    %s\t        %d\n",persona[i].dni, persona[i].nombre, persona[i].edad);
        }
    }
}

//imprimir el grafico de barras separados por edades

void graficarPersona(Epersona persona[], int cantidad)
{
    int contadorHasta18 =0;
    int contadorDe19a35=0;
    int contadorMayor35=0;
    int i;
    int flag=0;
    int mayor;

    if(contadorHasta18 >= contadorDe19a35 && contadorHasta18 >= contadorMayor35)
    {
        mayor = contadorHasta18;
    }
    else{
        if(contadorDe19a35 >= contadorHasta18 && contadorDe19a35 >= contadorMayor35)
        {
            mayor = contadorDe19a35;
        }
        else{
            mayor = contadorMayor35;
        }
    }

    for(i=mayor; i>cantidad; i--)
    {
        printf("%02d|",i);
        if(persona[i].edad <=18)
        {
            printf("*");
            contadorHasta18++;
        }
        else
        {
            if(persona[i].edad >=19 || persona[i].edad <=35)
            {
                printf("\t*");
                contadorDe19a35++;
                flag=1;
            }
            if(persona[i].edad >=35)
            {
                if(flag==1)
                {
                    printf("\t*");
                }
                if(flag == 0)
                {
                    printf("\t\t*");
                }
            }

        }
        printf("\n");
    }

    printf("--------------------");
    printf("\n  <18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", contadorHasta18, contadorDe19a35, contadorMayor35);

}



