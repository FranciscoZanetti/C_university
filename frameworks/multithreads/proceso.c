#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "global.h"
#include "thread.h"
#include "../colaMensajes.h"

int main(int argc, char *argv[]){
    int id_cola_mensajes;
    int i, ctl = 0;
    int cantidad = 1;
    tpeaje *datos_thread = NULL;
    pthread_t *idHilo = NULL;
    pthread_attr_t atributos;

    srand(time(NULL));

    if (argc > 1){
        cantidad = atoi(argv[1]);
    }

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE_COLA);

    idHilo = (pthread_t *)malloc(sizeof(pthread_t)*cantidad);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    datos_thread = (tpeaje *)malloc(sizeof(tpeaje)*cantidad);

    /* si hace falta mutex... */
    pthread_mutex_init(&mutex, NULL);

    for (i=0; i<cantidad; i++){
        datos_thread[i].nro_vias = i;
        datos_thread[i].id_cola_mensajes = id_cola_mensajes;

        pthread_create(&idHilo[i], &atributos, ThreadVia, &datos_thread[i]);
    }

    /* si hace falta mutex... */
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
    sleep(1);

    return 0;
}
