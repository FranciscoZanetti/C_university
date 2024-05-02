#include "semaforos.h"
#include "definiciones1.h"
#include "funciones1.h"
/* #include "/home/labo3/Documents/frameworks/archivosFramework.h" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){
    int id_semaforo;
    FILE *rfp = NULL;
    Registro *p = NULL;

    int numero = 0;
    char nuevoNombre[12];
    char nombre[9];
    memset(nombre, 0, sizeof(nombre));
    strcpy(nombre, NOMBRE_ARCHIVO);
    strcat(nombre, ".dat");

    id_semaforo =  creo_semaforo();

    while (1){

        p = (Registro *)malloc(sizeof(Registro));
        printf("\nreserva1 esperando usleep\n");
        usleep(ESPERA*1000);
        printf("\nreserva1 termina de esperar usleep\n");
        espera_semaforo(id_semaforo);
            printf("\nreserva1 entra a semaforo\n");
            p = leerArchivo(NOMBRE_ARCHIVO);

            if (p->vuelo == 1){
                printf("No hay archivo'lote.dat'.\n");
            }
            else{
                mostrar(p);
                while (1){
                    memset(nuevoNombre, 0, sizeof(nuevoNombre));
                    sprintf(nuevoNombre, "%s%03d.dat", NOMBRE_ARCHIVO, numero);
                    rfp = fopen(nuevoNombre, "wb");
                    if (rfp == NULL){
                        rename(nombre, nuevoNombre);
                    }
                    else{
                        numero ++;
                    }
                }
            }
        
        levanta_semaforo(id_semaforo);
        printf("\nreserva1 sale de semaforo semaforo\n");
        liberarLista(p);

    }

    return 0;
}