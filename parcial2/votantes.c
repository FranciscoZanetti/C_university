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
#include "mensajes.h"
#include "semaforos.h"
#include "threadVotantes.h"
#include "memoriaCompartida.h"


int main(){
    int id_cola_mensajes, id_semaforo, id_memoria, done;
    int *estado = NULL;
    DatosThread *datosThread = NULL;
    pthread_t *idThread = NULL;
    pthread_attr_t atributos;
    Mensaje mensaje;

    mensaje.evt = NADA;

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE);
    id_semaforo = creo_semaforo();
    estado = (int *)creo_memoria(sizeof(int), &id_memoria, CLAVE);
    estado[0] = NADA;
    done = estado[0];

    pthread_mutex_init(&mutex, NULL);
    
    idThread = (pthread_t *)malloc(sizeof(pthread_t));
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    datosThread = (DatosThread *)malloc(sizeof(DatosThread));

    printf("\nDATOS THREAD");
    datosThread->idHilo = MSG_VOTANTE;
    datosThread->id_cola_mensajes = id_cola_mensajes;
    datosThread->id_semaforo = id_semaforo;
    datosThread->estado = estado;
    printf("\nidThread: %d\tid_cola_mensajes: %d\tid_semaforo: %d", datosThread->idHilo, datosThread->id_cola_mensajes, datosThread->id_semaforo);
    printf("\n");

    pthread_create(idThread, &atributos, threadVotantes, datosThread);

    srand(time(NULL));

    while (done != FIN){
        usleep(INTERVALO * 1000);
        pthread_mutex_lock(&mutex);
            done = estado[0];
        pthread_mutex_unlock(&mutex);
    }

    shmdt((char *)estado);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

    free(idThread);
    free(datosThread);
    
    borrar_mensajes(id_cola_mensajes);
    msgctl (id_cola_mensajes, IPC_RMID, NULL);

    return 0;
}
