#include "semaforos.h"
#include "definiciones1.h"
#include "funciones1.h"
/* #include "/home/labo3/Documents/frameworks/archivosFramework.h" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int result, id_semaforo;
    Registro *p = NULL;
    Registro *q = NULL;
	id_semaforo =  creo_semaforo();

    inicia_semaforo(id_semaforo, 1);

    while (1){
        p = (Registro *)malloc(sizeof(Registro));
        q = p;

        printf("Ingrese los datos del vuelo (0 para terminar)\n");
        printf("Vuelo: ");
        scanf("%d", &q->vuelo);
        q->sig = NULL;

        while (q->vuelo !=0){
            while ((q->vuelo < 1000 || q->vuelo > 1010) && (q->vuelo != 0)){
                printf("Error (Rango valido 1000-1010). Vuelo: ");
                scanf("%d", &q->vuelo);
            }
            
            if (q->vuelo != 0){
                printf("\nCiudad: ");
                scanf("%s", q->destino);
                printf("\nNombre: ");
                scanf("%s", q->nombre);
                q->sig = (Registro *)malloc(sizeof(Registro));
                q = q->sig;

                printf("Ingrese los datos del vuelo (0 para terminar)\n");
                printf("Vuelo: ");
                scanf("%d", &q->vuelo);
            }

            q->sig = NULL;
        }

        espera_semaforo(id_semaforo);
            printf("\ncarga1 entra a semaforo\n");
            result = escribirArchivo(p, NOMBRE_ARCHIVO);

        levanta_semaforo(id_semaforo);
        printf("\ncarga1 sale de semaforo semaforo\n");
        if (result == 1){
            printf("\nNo se pudo escribir el archivo\n");
        }
        liberarLista(p);
    }

    return 0;
}