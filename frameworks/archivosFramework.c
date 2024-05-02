#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "archivosFramework.h"


int generarNumeroAleatorio(int minimo, int maximo){
    srand(time(NULL));	/* Inicializa la semilla del generador de números aleatorios */
    int numeroAleatorio = minimo + (rand() % (maximo - minimo + 1));	/* Genera un número aleatorio en el rango [min, max] */
	return numeroAleatorio;
}


void mostrar(Menu *p){
	if (p->sig != NULL){
		printf("\n%s\t%s\t%d\n", p->tipo, p->descripcion, p->precio);
		mostrar(p->sig);
	}
}


void liberarLista(Medicamento *cabeza){
    Medicamento *aux = NULL;

    while (cabeza != NULL) {
        printf("\nFLAG LIBERO NODO\n");
        aux = cabeza;
        cabeza = cabeza->sig;
        free(aux);
    }

    printf("\nFLAG LIBERE NODO\n");
}


void convertirAMayusculas(char *cadena){
	while(*cadena != '\0'){
		*cadena = toupper(*cadena);
		cadena ++;
	}
}


/* Cuenta las lineas que tiene el archivo. */
int contarUnidades(char *nombre){
	FILE *auxfp = NULL;
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


int escribirArchivoAlFinal(char *nombre, Medicamento medicamento){
    FILE *wfp = NULL;
    int result;

	/* Guardo en "nombreCompleto" el producto + .txt */

	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".txt");

    wfp=fopen(nombreCompleto, "a");
    if(wfp == NULL){
        result = 1;
    }
    else{
        fprintf(wfp, "%d\t%s\t%d\n", medicamento.tipo, medicamento.color, medicamento.cantidad);
        fclose(wfp);
        result = 0;
    }
    memset(nombreCompleto, 0, sizeof(nombreCompleto));
    return result;
}


int escribirArchivoAlFinal(char *nombre, Medicamento medicamento){
    FILE *wfp = NULL;
    int result;

	/* Guardo en "nombreCompleto" el producto + .txt */

	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".txt");

    wfp=fopen(nombreCompleto, "w");
    if(wfp == NULL){
        result = 1;
    }
    else{
        fprintf(wfp, "%d\t%s\t%d\n", medicamento.tipo, medicamento.color, medicamento.cantidad);
        fclose(wfp);
        result = 0;
    }
    memset(nombreCompleto, 0, sizeof(nombreCompleto));
    return result;
}


int escribirArchivoAlFinalPuntero(char *nombre, Medicamento *medicamento){
    FILE *wfp = NULL;
    int result;

	/* Guardo en "nombreCompleto" el producto + .txt */

	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".txt");

    wfp=fopen(nombreCompleto, "w");
    if(wfp == NULL){
        result = 1;
    }
    else{
        while (medicamento->sig != NULL){
            fprintf(wfp, "%d\t%s\t%d\n", medicamento->tipo, medicamento->color, medicamento->cantidad);
            medicamento = medicamento->sig;
        }
        fclose(wfp);
        result = 0;
    }
    memset(nombreCompleto, 0, sizeof(nombreCompleto));
    return result;
}


int escribirArchivoPuntero(char *nombre, Medicamento *medicamento){
    FILE *wfp = NULL;
    int result;

	/* Guardo en "nombreCompleto" el producto + .txt */

	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".txt");

    wfp=fopen(nombreCompleto, "w");
    if(wfp == NULL){
        result = 1;
    }
    else{
        while (medicamento->sig != NULL){
            fprintf(wfp, "%d\t%s\t%d\n", medicamento->tipo, medicamento->color, medicamento->cantidad);
            medicamento = medicamento->sig;
        }
        fclose(wfp);
        result = 0;
    }
    memset(nombreCompleto, 0, sizeof(nombreCompleto));
    return result;
}


void leerArchivo(Medicamento *primerop, char *nombre){
    FILE *rfp = NULL;
    Medicamento *rp = NULL;
    int resultScan;
    /* Guardo en "nombreCompleto" el producto + .txt */

	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".txt");

    rfp=fopen(nombreCompleto, "r");
    if (rfp == NULL){
        primerop->result = 1;
        primerop->sig = NULL;
    }
    else{
        rp = primerop;	/* Puntero auxiliar para cargar la lista */
        while (!feof(rfp)){
            resultScan = fscanf(rfp, "%d\t%s\t%d\n", &rp->tipo, rp->color, &rp->cantidad);
            if (resultScan != EOF){
                rp->sig = (Medicamento *)malloc(sizeof(Medicamento));
                rp = rp->sig;
            }
        }
        rp->sig = NULL;
        memset(nombreCompleto, 0, sizeof(nombreCompleto));
        /*free(rp);*/
        rp = NULL;
        fclose(rfp);
        primerop->result = 0;
    }
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


void compararYRealizarAccion(Medicamento *solicitud, Medicamento *historico){
    Medicamento *auxsolicitud = solicitud;
    Medicamento *auxhistorico = historico;

    while (auxhistorico->sig != NULL){

        auxsolicitud = solicitud;

        while (auxsolicitud->sig != NULL){
            
            if (auxhistorico->tipo == auxsolicitud->tipo){
                auxhistorico->cantidad = auxhistorico->cantidad + auxsolicitud->cantidad;
            }
            auxsolicitud = auxsolicitud->sig;

        }

        auxhistorico = auxhistorico->sig;
    }
}