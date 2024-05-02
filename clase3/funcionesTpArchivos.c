#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesTpArchivos.h"


void convertirAMayusculas(char *cadena){
	while(*cadena != '\0'){
		*cadena = toupper(*cadena);
		cadena ++;
	}
}


/* Cuenta las lineas que tiene el archivo. */
int contarUnidades(char *nombre){
	FILE *auxfp;
	char aux[30];
	int cont = 0;
	int result;
	if ((auxfp=fopen(nombre, "r")) == NULL){
		result = -1;
	}
	else{
		while (!feof(auxfp)){
			fscanf(auxfp, "%[^\n]\n", aux);
			memset(aux, '\0', sizeof(aux));
			cont++;
		}
		result = cont;
		fclose(auxfp);
	}
	return result;
}


/* Devuelve:
 0 si es exitoso
1 si hay errores en el manejo de archivos
2 si ya hay un archivo del mismo producto creado */
int producir(char *producto){
	int result, i;

	/* Guardo en "nombre" el producto + .txt */
	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombre[30];
	strcpy(nombre, producto);
	strcat(nombre, ".txt");

	if ((rfp=fopen(nombre, "r")) == NULL){
		if ((wfp=fopen(nombre, "w")) == NULL){
			fclose(rfp);
			result = 1;
		}
		else{
			convertirAMayusculas(producto);
			for (i=0; i<10; i++){
				fprintf(wfp, "%s-%02d\n", producto, i);
			}
			fclose(wfp);
			result = 0;
		}
	}
	else{
		fclose(rfp);
		result = 2;
	}
	memset(nombre, 0, sizeof(nombre));
	return result;
}


/* Devuelve:
0 si es exitoso
1 si hay errores en el manejo de archivos
2 si el archivo tiene menos lineas que unidades pedidas */
void consumir(Result *primerop, char *producto, int unidades){

	int lineas, cont, max;
	char cadena[30];
	/* Guardo en "nombre" el producto + .txt */
	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombre[30];


	strcpy(nombre, producto);
	strcat(nombre, ".txt");

	if ((rfp=fopen(nombre, "r")) == NULL){
		primerop->result = 1;
	}
	else{
		lineas = contarUnidades(nombre);
		if (lineas == -1){	/* Verifica si devuelve error contarUnidades() */
			primerop->result = 1;
		}
		else{

			/* Si hay suficientes unidades */
			if (lineas >= unidades){
				Result *rp = primerop;	/* Puntero auxiliar para cargar la lista */
				FILE *auxp;	/* Puntero auxiliar para el archivo temporal */
				if ((auxp=fopen("temp.txt", "w")) == NULL){
					primerop->result = 1;
				}
				else{
					cont = 0;
					max = lineas - unidades;
					while (!feof(rfp)){

						/* Paso linea al archivo temporal */
						if (cont < max){
							fscanf(rfp, "%[^\n]\n", cadena);
							fprintf(auxp, "%s\n", cadena);
							memset(cadena, '\0', sizeof(cadena));
						}

						/* Paso linea a Result para consumir */
						else{
							fscanf(rfp, "%[^\n]\n", rp->producto);
							rp->sig = (Result *)malloc(sizeof(Result));
							rp = rp->sig;
						}
						cont ++;
					}
					remove(nombre);
					rename("temp.txt", nombre);

					/* Si me quedo sin unidades elimino el archivo de producto */
					if (lineas == unidades){
						remove(nombre);
					}

					memset(nombre, 0, sizeof(nombre));
					free(rp);
					fclose(auxp);
					primerop->result = 0;
				}
			}

			/* Si no hay suficientes unidades */
			else{
				primerop->result = 2;
			}
		}
		fclose(rfp);
	}
}
