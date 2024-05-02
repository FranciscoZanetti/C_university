#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funciones.h"


/*typedef struct Alumno{
    int legajo;
    int materias;
    char nombre[20];
    char apellido[20];
    struct Alumno *sig;
    int result;
}Alumno;*/


int escribirArchivoAlFinal(char *nombre, Alumno alumno){
    FILE *wfp = NULL;
    int result;

	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".txt");

    wfp=fopen(nombreCompleto, "a");
    if(wfp == NULL){
        result = 1;
    }
    else{
        fprintf(wfp, "%d\t%s\t%s\t%d\n", alumno.legajo, alumno.nombre, alumno.apellido, alumno.materias);
        fclose(wfp);
        result = 0;
    }
    memset(nombreCompleto, 0, sizeof(nombreCompleto));
    return result;
}


void leerArchivo(Alumno *primerop, char *nombre){
    FILE *rfp = NULL;
    Alumno *rp = NULL;
    int resultScan;

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
            resultScan = fscanf(rfp, "%d\t%s\t%s\t%d\n", &rp->legajo, rp->nombre, rp->apellido, &rp->materias);
            if (resultScan != EOF){
                rp->sig = (Alumno *)malloc(sizeof(Alumno));
                rp = rp->sig;
            }
        }
        rp->sig = NULL;
        memset(nombreCompleto, 0, sizeof(nombreCompleto));
        rp = NULL;
        fclose(rfp);
        primerop->result = 0;
    }
}


void mostrar(Alumno *p){
	if (p->sig != NULL){
        if (p->materias == 0){
            printf("\n%d\t%s\t%s\n", p->legajo, p->nombre, p->apellido);
        }
        else{
            printf("\n%d\t%s\t%s\t%d\n", p->legajo, p->nombre, p->apellido, p->materias);
        }
		mostrar(p->sig);
	}
}


void liberarLista(Alumno *cabeza){
    Alumno *aux = NULL;

    while (cabeza != NULL) {
        aux = cabeza;
        cabeza = cabeza->sig;
        free(aux);
    }
}
