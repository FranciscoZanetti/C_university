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

void *threadVotantes(void *parametro){
    int idHilo, id_cola_mensajes, id_semaforo, voto, votos = 0;
    int *estado;

    DatosThread *datosThread = (DatosThread*) parametro;
    idHilo = datosThread->idHilo;
    id_cola_mensajes = datosThread->id_cola_mensajes;
    id_semaforo = datosThread->id_semaforo;
    estado = datosThread->estado;

    while (votos < PADRON){

        voto = MS + (rand() % (MI - MS + 1));
        espera_semaforo(id_semaforo);
            enviar_mensaje(id_cola_mensajes, MSG_PANEL, MSG_VOTANTE, voto);
        levanta_semaforo(id_semaforo);

        votos += 1;

        printf("\nVotos emitidos: %d", votos);

        usleep(INTERVALO * 1000);
        usleep(INTERVALO * 1000);
        usleep(INTERVALO * 1000);
        usleep(INTERVALO * 1000);

    }

    espera_semaforo(id_semaforo);
        enviar_mensaje(id_cola_mensajes, MSG_PANEL, MSG_VOTANTE, FIN);
    levanta_semaforo(id_semaforo);

    printf("\nVoto el padron completo.");
    printf("\n");

    pthread_mutex_lock(&mutex);
        estado[0] = FIN;
    pthread_mutex_unlock(&mutex);

    pthread_exit((void*)0);
}
