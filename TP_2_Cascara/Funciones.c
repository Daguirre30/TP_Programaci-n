#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"







//funcion para dar de alta una persona

void altaPersona(Epersona persona[], int cantidad)
{
    fflush(stdin);
    system("clear");

    int flagEncontro=0, i;


    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 0) // si esta desocupada esa posicion
        {
            printf("Ingrese DNI\n");
            getchar();
            gets(persona[i].dni);

            while(strlen(persona[i].dni)>=9)
            {
                printf("Error, el DNI debe ser menor a 9\n");
                printf("Ingrese DNI\n");
                fflush(stdin);
                gets(persona[i].dni);
            }
            while(ValidarNumero(persona[i].dni)==0)
            {
                printf("Error, el DNI debe ser numerico\n");
                printf("Ingrese DNI\n");
                fflush(stdin);
                gets(persona[i].dni);
            }
            persona[i].estado = 1;
            printf("Ingrese nombre de la persona\n");// ingreso nombre, edad, etc.
            gets(persona[i].nombre);
             while(strlen(persona[i].nombre)>=51)
            {
                printf("Error, el nombre  debe ser menor a 50\n");
                printf("Ingrese nombre de la persona\n");
                fflush(stdin);
                gets(persona[i].nombre);
            }
            while(ValidarLetra(persona[i].nombre)==0)
            {
                printf("Error, el nombre  debe ser solo letra\n");
                printf("Ingrese nombre de la persona\n");
                fflush(stdin);
                gets(persona[i].nombre);
            }
            fflush(stdin);
            printf("Ingrese edad\n");
            gets(persona[i].edad);
            while(persona[i].edad <= 0 && persona[i].edad >=100)
            {
                printf("Error, la edad debe no puede ser menor a 0 ni mayor a 100\n");
                printf("Ingrese edad\n");
                fflush(stdin);
                gets(persona[i].edad);
            }
            fflush(stdin);
            flagEncontro = 1;

            break;
        }
    }
    if(flagEncontro == 0)
    {
        printf("No hay espacio suficiente\n");
    }
    system("clear");
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
    fflush(stdin);
    system("clear");
    int flagEncontro =0, i;
    char auxiliar;
    char respuesta;
    printf("Ingrese DNI\n");
    fflush(stdin);
    scanf("%s",auxiliar);

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado==1)
        {
            if(auxiliar = persona[i].dni)
            {
                printf("DNI\tNombre\tEdad\n");
                fflush(stdin);
                printf("%s\t%s\t%s\n",persona[i].dni, persona[i].nombre, persona[i].edad);
                printf("Estas seguro de eliminar este dato s/n\n");
                getchar();
                scanf("%s",respuesta);
                //respuesta = getche();
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
    system("clear");
}

// imprimir las personas ordenadas por Nombre o por DNI

void imprimirPersonas(Epersona persona[], int cantidad)
{

    system("clear");
    Epersona personaAux;
    int i, j;
    printf("DNI\t\tNombre\t\tEdad");
    fflush(stdin);
    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++){ fflush(stdin);
               if(strcmp(persona[i].nombre, persona[j].nombre) > 0){
                personaAux = persona[i];
                persona[i] = persona[j];
                persona[j] =  personaAux;
            }
            else{
            fflush(stdin);
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

   for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 1)
        {


          printf("%s\t%s\t%s\n",persona[i].dni,persona[i].nombre,persona[i].edad);
        }
    }

}

//imprimir el grafico de barras separados por edades

void graficarPersona(Epersona persona[], int cantidad)
{

    system("clear");
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
//validar Numeros
int ValidarNumero(char str[])
{
 int i=0;

    while(str[i] != '\0')
    {
        if(str[i]<'0' || str[i] >'9')
        {
            return 0;
        }
        i++;
    }
    return 1;


}

ValidarLetra(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        if((str[i] <'a' || str[i] >'z') && (str[i] !=' ') && (str[i] <'A' || str[i] >'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;

}





