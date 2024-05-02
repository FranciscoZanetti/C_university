#ifndef _ARCHIVOSFRAMEWORK_H
#define _ARCHIVOSFRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "definiciones.h"

/* "API" de resultados */
typedef struct fileReadResult{
	char cadena[30];
	int result;
	struct fileReadResult *sig;
}rfResult;

int generarNumeroAleatorio(int minimo, int maximo);
void mostrar(Menu *p);
void liberarLista(Menu *cabeza);
void convertirAMayusculas(char *cadena);
int contarUnidades(char *nombre);
int escribirArchivoAlFinal(char *nombre, Menu menu);
int escribirArchivo(char *nombre, Menu menu);
int escribirArchivoAlFinalPuntero(char *nombre, Menu *menu);
int escribirArchivoPuntero(char *nombre, Menu *menu);
void leerArchivo(Menu *primerop, char *nombre);
void consumir(Result *primerop, char *producto, int unidades);
int producir(char *producto);
void compararYRealizarAccion(Medicamento *solicitud, Medicamento *historico);

#endif
