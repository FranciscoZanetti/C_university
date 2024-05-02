#include "semaforos.h"
#include "definiciones1.h"
#include "funciones1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ReservasResult{
    int vuelo;
    char destino[20];
    int pasajeros;
    struct ReservasResult *sig;
}Result;


int escribirArchivo(Registro *p, char *nombre){
    
    int result;
    FILE *wfp = NULL;

	/* Guardo en "nombreCompleto" el producto + .dat */

	/* int longitud = sizeof(producto) + 5;
	char nombre[longitud]; */
	char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".dat");

    printf("\nempiezo a escribir archivo\n");

    wfp=fopen(nombreCompleto, "wb");
    if(wfp == NULL){
        result = 1;
    }
    else{
        while (p->vuelo != 0){
            fwrite(p, sizeof(Registro), 1, wfp);
            printf("\n1 registro escrito:\n");
            printf("%d\t%s\t%s\n", p->vuelo, p->destino, p->nombre);
            p = p->sig;
        }
        result = 0;
    }
    fclose(wfp);
    memset(nombreCompleto, 0, strlen(nombreCompleto));
    printf("\ntermino de escribir archivo\n");
    return result;
}


void liberarLista(Registro* cabeza){
    Registro* nodoActual = cabeza;
    Registro* nodoSiguiente = NULL;

    while (nodoActual != NULL) {
        nodoSiguiente = nodoActual->sig; /* Guarda el siguiente nodo */
        free(nodoActual); /* Libera el nodo actual */
        nodoActual = nodoSiguiente; /* Avanza al siguiente nodo */
    }
}


/* Muestra los productos de la lista */
void mostrar(Registro *p){
    
    Registro *q = p;
    Result *r = NULL;
    Result *s = NULL;
    int checker;
    r = (Result *)malloc(sizeof(Result));
    s = r;

    printf("\nempiezo mostrar\n");

    while (q->sig != NULL){
        checker = 0;
        if (r->sig == NULL){    /* si no hay nada cargado en Result */
            s->vuelo = q->vuelo;
            strcpy(s->destino, q->destino);
            s->pasajeros = 1;
            s->sig = (Result *)malloc(sizeof(Result));
            s->sig->vuelo = 0;
        }
        else{ /* si por lo menos hay un vuelo cargado en Result */
            while (s->sig != NULL){ /* recorro los Result */
                if (s->vuelo == q->vuelo){  /* si los vuelos coinciden le agrego un pasajero */
                    s->pasajeros ++;
                    checker = 1;
                }
                s = s->sig;
            }
            if (checker == 0){  /* si no hubieron coincidencias agrego el vuelo nuevo a Result */
                s->vuelo = q->vuelo;
                strcpy(s->destino, q->destino);
                s->pasajeros = 1;
                s->sig = (Result *)malloc(sizeof(Result));
                s->sig->vuelo = 0;
            }
        }
        s = r;
        q = q->sig;
    }
    
    printf("VUELO\tDESTINO\tPASAJEROS\n");
    while (r->sig != NULL){
        printf("%d\t%s\t%d\n", r->vuelo, r->destino, r->pasajeros);
        r = r->sig;
    }

    free(q);
    free(s);
    /* liberarLista(r); */
    printf("\ntermino mostrar\n");
}


Registro* leerArchivo(char *nombre){
    
    Registro *primero = NULL;
    Registro *ultimo = NULL;
    Registro *nodo = NULL;
    /* Registro *q = p; */
    /* q->sig = NULL; */
    FILE *rfp = NULL;
    
    char nombreCompleto[30];
	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ".dat");

    printf("\nempiezo leerarchivo\n");

    rfp=fopen(nombreCompleto, "wb");

    primero = (Registro *)malloc(sizeof(Registro));
    primero->vuelo = 1;
    if (rfp != NULL){
        while(!feof(rfp)){
            nodo = NULL;
            nodo = (Registro *)malloc(sizeof(Registro));
            if (fread(nodo, sizeof(Registro), 1, rfp) != 1) {
                free(nodo); /* Liberar el nodo no utilizado */
                break;
            }
            nodo->sig = (Registro *)malloc(sizeof(Registro));
            if (primero == NULL){
                primero = nodo;
                ultimo = primero;
            }
            else{
                ultimo->sig = nodo;
                ultimo = ultimo->sig;
            }
        }
    }

    fclose(rfp);
    printf("\ntermino leerarchivo\n");
    return primero;
}

