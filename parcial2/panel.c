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


int main(){
    int id_cola_mensajes, id_semaforo, i, respuesta;
    Formula formulas[FORMULAS];
    Mensaje mensaje;

    mensaje.evt = NADA;

    formulas[0].id = MS;
    memset(formulas[0].presidente, 0, sizeof(formulas[0].presidente));
    strcpy(formulas[0].presidente, "MS");
    memset(formulas[0].vice, 0, sizeof(formulas[0].vice));
    strcpy(formulas[0].vice, "A");
    formulas[0].votos = 0;

    formulas[1].id = MI;
    memset(formulas[1].presidente, 0, sizeof(formulas[1].presidente));
    strcpy(formulas[1].presidente, "MI");
    memset(formulas[1].vice, 0, sizeof(formulas[1].vice));
    strcpy(formulas[1].vice, "V");
    formulas[1].votos = 0;

    printf("\nFORMULAS:");
    for (i=0; i<FORMULAS; i++){
        printf("\nid: %d\tpresidente: %s\tvice: %s\tvotos: %d", formulas[i].id, formulas[i].presidente, formulas[i].vice, formulas[i].votos);
    }
    printf("\n");

    id_cola_mensajes = creo_id_cola_mensajes(CLAVE);
    borrar_mensajes(id_cola_mensajes);

    id_semaforo = creo_semaforo();
    inicia_semaforo(id_semaforo, 1);

    while (mensaje.evt != FIN){

        usleep(INTERVALO * 1000);

        espera_semaforo(id_semaforo);
            respuesta = recibir_mensaje_no_bloqueante(id_cola_mensajes, MSG_PANEL, &mensaje);
        levanta_semaforo(id_semaforo);

        if (respuesta > 0){

            if (mensaje.evt != FIN){

                for (i=0; i<FORMULAS; i++){
                    if (mensaje.evt == formulas[i].id){
                        formulas[i].votos += 1;
                    }
                }

                printf("\nBOCA DE URNA:");
                for (i=0; i<FORMULAS; i++){
                    printf("\nid: %d\tpresidente: %s\tvice: %s\tvotos: %d", formulas[i].id, formulas[i].presidente, formulas[i].vice, formulas[i].votos);
                }
                printf("\n");

            }

        }

    }

    printf("\nRESULTADOS:");
    for (i=0; i<FORMULAS; i++){
        printf("\nid: %d\tpresidente: %s\tvice: %s\tvotos: %d", formulas[i].id, formulas[i].presidente, formulas[i].vice, formulas[i].votos);
        memset(formulas[0].presidente, 0, sizeof(formulas[0].presidente));
        memset(formulas[0].vice, 0, sizeof(formulas[0].vice));
    }
    printf("\n");

    borrar_mensajes(id_cola_mensajes);
    msgctl (id_cola_mensajes, IPC_RMID, NULL);

    return 0;
}