#ifndef _DEFINICIONES_H
#define _DEFINICIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define INICIO "inicio.txt"
#define ESPERA 500
#define ARCHIVOINICIALES "iniciales"
#define ARCHIVOAVALIDAR "a-validar"


typedef struct Alumno{
    int legajo;
    int materias;
    char nombre[20];
    char apellido[20];
    struct Alumno *sig;
    int result;
}Alumno;


#endif
