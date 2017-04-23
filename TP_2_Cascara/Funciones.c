#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int validarTipoDato();// pendiente por hacer
int validarDocumento();//pendiente por hacer

//funcion para dar de alta una persona

void altaPersona(Epersona persona[], int tam)
{

	int flagEncontro=0 , i, valido;

	for(i=0; i < tam; i++)
	{
		if(persona[i].estado == 0) // si esta desocupada esa posicion
		{
            printf("Ingrese DNI\n");
			scanf("%d", &persona[i].dni);
            persona[i].estado = 1;
			printf("Ingrese el nombre de la persona\n");// ingreso nombre, edad, etc.
			scanf("%s", persona[i].nombre);
			printf("Ingrese edad\n");
			scanf("%d", &persona[i].edad);

			flagEncontro = 1;
			break;
		}
	}
	if(flagEncontro == 0){
	printf("No hay espacio suficiente\n");
	}
}

//funcion que inicializa el Array

void inicilizarArray(Epersona personas[], int tam)
{
	int i;


    for(i=0; i<tam; i++)
    {
        personas[i].estado = 0;
    }

}

// funcion que da de baja la persona

void bajaPersona (Epersona persona[], int tam)
{

	int flagEncontro=0;
	int auxiliarDni;
	char respuesta;
	int i;

	printf("Ingrese DNI\n");
	scanf("%d", &auxiliarDni);
	for(i=1 ;i<tam; i++)
	{
		if(persona[i].estado ==1)
		{
			if(auxiliarDni== persona[i].dni)
			{
				printf("%d\t%s\n%d\n",persona[i].dni, persona[i].nombre, persona[i].edad);
				printf("Esta seguro que desea eliminar este dato s/n\n");
				scanf("%s",respuesta);

				if(respuesta == 's')
				{
                    printf("La persona a sido eliminada correctamente");
                    system("pause");
					persona[i].estado = 0;
				}
				else
				{
					printf("Accion cancelada por el usuario!!!");
				}

				flagEncontro=1;
				break;
			}


		}
	}
	if(flagEncontro==0)
    {

        printf("La persona no existe!!!\n");



    }
}

void imprimirPersonas(Epersona persona[], int tam)
{
    Epersona personaAux;
    int i, j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre) > 0)
            {
                personaAux = persona[i];
                persona[i] = persona[j];
                persona[j] =  personaAux;
            }
            else
            {
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
    }
}


