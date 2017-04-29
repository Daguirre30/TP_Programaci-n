#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    char edad[4];
    int estado;
    char dni[9];

}Epersona;


void altaPersona (Epersona persona[], int cantidad);
void bajaPersona (Epersona persona[], int cantidad);
void imprimirPersonas(Epersona persona[], int cantidad);
void graficarPersona (Epersona persona[], int cantidad);
int ValidarNumero(char str[]);
int ValidarLetra(char str[]);
int validarUnicidad(char str[]);










#endif // FUNCIONES_H_INCLUDED
