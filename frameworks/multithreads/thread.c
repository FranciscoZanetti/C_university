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
#include "../colaMensajes.h"

void *ThreadVia(void *parametro){
    int nro_via;
    int id_cola_mensajes;
    int done = 0;

    mensaje msg;

    tpeaje *datos_thread = (tpeaje*) parametro;
    nro_via = datos_thread->nro_vias;
    id_cola_mensajes = datos_thread->id_cola_mensajes;

    while (done == 0){
        recibir_mensaje(id_cola_mensajes, MSG_VIAS+nro_via, &msg);
    }

    

    pthread_exit((void*)0);
}
