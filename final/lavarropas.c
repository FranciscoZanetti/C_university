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
#include "memoriaCompartida.h"
#include "threads.h"


int main(int argc, char *argv[]){
    int id_cola_mensajes, id_semaforo, id_memoria, i, estado;
    Memoria *memoria_inicio = NULL;
    DatosThread *datosThread = NULL;
    pthread_t *idThread = NULL;
    pthread_attr_t atributos;

    memoria_inicio = (Memoria*)creo_memoria(sizeof(Memoria), &id_memoria, CLAVE);
    id_semaforo = creo_semaforo();
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE);

    espera_semaforo(id_semaforo);
        memoria_inicio->inicio_lavarropas = EVT_INIT;
        printf("\nestableci init lavarropas\n");
    levanta_semaforo(id_semaforo);

    while (1){
        espera_semaforo(id_semaforo);
            estado = memoria_inicio->inicio_controller;
        levanta_semaforo(id_semaforo);
        if (estado == EVT_INIT){
            break;
        }
    }

    printf("\nINICIO\n");
    
    pthread_mutex_init(&mutex, NULL);

    idThread = (pthread_t *)malloc(sizeof(pthread_t)*LAVARROPAS);
    datosThread = (DatosThread *)malloc(sizeof(DatosThread)*LAVARROPAS);
    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    for (i=0; i<LAVARROPAS; i++){
        datosThread[i].idHilo = idThread[i];
        datosThread[i].id_semaforo = id_semaforo;
        datosThread[i].id_cola_mensajes = id_cola_mensajes;
        datosThread[i].numero_lavarropas = MSG_LAVARROPAS+i;
        pthread_create(&idThread[i], &atributos, threadLavarropas, &datosThread[i]);
    }

    srand(time(NULL));

    while (estado != EVT_FIN){
        usleep(INTERVALO);
        pthread_mutex_lock(&mutex);
            estado = memoria_inicio->estado;
        pthread_mutex_unlock(&mutex);
    }

    printf("\nFIN LAVADOS\n");

    free(idThread);
    free(datosThread);

    sleep(3);

    shmdt((char *)memoria_inicio);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);
    
    /*borrar_mensajes(id_cola_mensajes);
    msgctl (id_cola_mensajes, IPC_RMID, NULL);*/

    return 0;
}
