#ifndef _FUNCIONESTPARCHIVOS_H
#define _FUNCIONESTPARCHIVOS_H

/* "API" de resultados */
typedef struct consumirResult{
	char producto[30];
	int result;
	struct consumirResult *sig;
}Result;

FILE *rfp;	/* Puntero para leer archivo */
FILE *wfp;	/* Puntero para escribir archivo */

int producir(char *producto);
void consumir(Result *primerop, char *producto, int unidades);

#endif
