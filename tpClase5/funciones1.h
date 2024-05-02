#ifndef _FUNCIONES1
#define _FUNCIONES1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LoteRegistro{
    int vuelo;
    char destino[20];
    char nombre[30];
    struct LoteRegistro *sig;
}Registro;


int escribirArchivo(Registro *p, char *nombre);
void liberarLista(Registro* cabeza);
void mostrar(Registro *p);
Registro* leerArchivo(char *nombre);

#endif