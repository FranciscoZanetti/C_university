#ifndef _ARCHIVOSFRAMEWORK_H
#define _ARCHIVOSFRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "definiciones.h"

/* "API" de resultados */


int escribirArchivoAlFinal(char *nombre, Alumno alumno);
void leerArchivo(Alumno *primerop, char *nombre);
void mostrar(Alumno *p);
void liberarLista(Alumno *cabeza);


#endif
