#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"




/** \brief función para dar de alta a una persona
  * \param1 recibe un array de la estructura persona
  * \param2 recibe la cantidad definida
  * \return void
  *
  */

//funcion para dar de alta una persona

void altaPersona(Epersona persona[], int cantidad)
{
    system("clear");
    int flagEncontro=0;
    int i;
    int contadorHasta18=0;
    int contadorDe19a35=0;
    int contadorMayor35=0;
    int auxEdad;


    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 0) // si esta desocupada esa posicion
        {
            printf("Ingrese DNI\n");
            getchar();
            fflush(stdin);
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
           while(ValidarLetra(persona[i].edad)==1)
            {
                printf("Error, la edad debe ser numerica\n");
                printf("Ingrese edad de la persona\n");
                fflush(stdin);
                gets(persona[i].edad);
            }
            auxEdad= atoi(persona[i].edad);
            if(auxEdad <= contadorHasta18)
            {
                contadorHasta18++;
            }
            if(auxEdad <= contadorHasta18&& auxEdad<=contadorDe19a35)
            {
                contadorDe19a35++;
            }

            if(auxEdad > contadorMayor35)
            {
                contadorMayor35++;
            }
            flagEncontro = 1;

            break;
        }
    }
    if(flagEncontro == 0)
    {
        printf("No hay espacio suficiente\n");
    }

}

/** \brief función para dar de baja a una persona
  * \param1 recibe un array de la estructura persona
  * \param2 recibe la cantidad definida
  * \return void
  *
  */
// funcion que da de baja la persona

void bajaPersona(Epersona persona[], int cantidad)
{
    system("clear");

    int flagEncontro =0;
    int i;
    int auxiliar;
    char respuesta;
    printf("Ingrese DNI\n");
    scanf("%d",&auxiliar);
    system("clear");

    for(i=0; i<cantidad; i++)
    {
       if(auxiliar == atoi(persona[i].dni)&& (persona[i].estado==1))
        {
            printf("DNI   \tnombre\tedad\n");
            printf("%s\t%s\t%s\n",persona[i].dni, persona[i].nombre, persona[i].edad);
            printf("Estas seguro de eliminar este dato s/n\n");
            scanf("%s",&respuesta);
            system("clear");
            if(respuesta == 's')
            {
                persona[i].estado = 0;
                printf("Se ha eliminado correctamente\n");

            }
            if(respuesta == 'n')
            {
             printf("Accion cancelada por el usuario\n");
            }
            flagEncontro = 1;
            break;
            }
    }
    if(flagEncontro ==0)
    printf("El DNI no existe\n");


}

/** \brief función para imprimir lista ordenada por nombres de las personas
  * \param1 recibe un array de la estructura persona
  * \param2 recibe la cantidad definida
  * \return void
  *
  */
// imprimir las personas ordenadas por Nombre o por DNI

void imprimirPersonas(Epersona persona[], int cantidad)
{
    system("clear");
    Epersona personaAux;
    int i, j;
    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                personaAux = persona[i];
                persona[i] = persona[j];
                persona[j] =  personaAux;
            }
            if(strcmp(persona[i].nombre, persona[j].nombre) ==0 )
            {
                if(persona[i].dni > persona[j].dni)
                {
                    personaAux = persona[i];
                    persona[i] = persona[j];
                    persona[j] =  personaAux;
                }
            }

        }

    }

   for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 1)
        {
            printf("DNI   \tnombre\tedad\n");
            printf("%s\t%s\t%s\n",persona[i].dni,persona[i].nombre,persona[i].edad);
        }
    }

}

/** \brief función para mostrar graficamente la cantidad de personas
	ordenadas por edades, (hasta 18 años, entre 19 y 35 años y
	mayor a 35
  * \param1 recibe un array de la estructura persona
  * \param2 recibe la cantidad definida
  * \return void
  *
  */
//imprimir el grafico de barras separados por edades

/*void graficarPersona(Epersona persona[], int cantidad)
{

    int contadorHasta18 =0;
    int contadorDe19a35=0;
    int contadorMayor35=0;
    int i;
    int flag=0;
    int mayor;
    int auxiliar;

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

    for(i=0; i<cantidad; i++)
    {
        printf("%02d|",i);
        if(atoi(persona[i].edad) <=18)
        {
            printf("*");
            contadorHasta18++;
        }
        else
        {
            if(atoi(persona[i].edad >=19) && atoi(persona[i].edad <=35))
            {
                printf("\t*");
                contadorDe19a35++;
                flag=1;
            }
            if(atoi(persona[i].edad) >=35)
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


}*/

/** \brief función para validar que lo ingresado sean numeros
  * \param1 recibe un array de char
  * \return true o false (1 o 0)
  *
  */
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

/** \brief función para validar que lo ingresado sea letras
  * \param1 recibe un array de char
  * \return true o false (1 o 0)
  *
  */
//Validar letras
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

/** \brief función que inicializa los estados en 0
  * \param1 recibe un array de la estructura persona
  * \param2 recibe la cantidad definida
  * \return void
  *
  */
//funcion que inicializa los estados en 0
void inicilizarArray(Epersona personas[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {

        personas[i].estado=0;

    }

}





