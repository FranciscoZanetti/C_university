#ifndef _DEFINICIONES_H
#define _DEFINICIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TIPOA "A"
#define TIPOB "B"
#define TIPOC "C"
#define DESCA "Milanga"
#define DESCB "Ornitorrinco braseado"
#define DESCC "Pasto al pesto"
#define PRCA 1000
#define PRCB 2000
#define PRCC 3000
#define PRCPOSTRE 200
#define POSTRESI 1
#define POSTRENO 0
#define INICIO "inicio.txt"
#define ESPERA 100

/* "API" de resultados */
typedef struct MenuStruct{
	char tipo[2];
    char descripcion[30];
	int precio;
    int postre;
	int result;
	struct MenuStruct *sig;
}Menu;

#endif
