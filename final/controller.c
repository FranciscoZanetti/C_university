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


int main(int argc, char *argv[]){
    int id_cola_mensajes, id_semaforo, id_memoria, i, estado, recibidos = 0, prendas, contador_enviadas = 0, contador_recibidas = 0;
    Memoria *memoria_inicio = NULL;
    Mensaje mensaje;
    Mensaje ropa[10];

    memoria_inicio = (Memoria*)creo_memoria(sizeof(Memoria), &id_memoria, CLAVE);

    id_semaforo = creo_semaforo();
    inicia_semaforo(id_semaforo, 1);
    id_cola_mensajes = creo_id_cola_mensajes(CLAVE);
    borrar_mensajes(id_cola_mensajes);

    espera_semaforo(id_semaforo);
        memoria_inicio->inicio_controller = EVT_INIT;
        printf("\nestableci init controller\n");
    levanta_semaforo(id_semaforo);

    while (1){
        espera_semaforo(id_semaforo);
            estado = memoria_inicio->inicio_lavarropas;
        levanta_semaforo(id_semaforo);
        if (estado == EVT_INIT){
            break;
        }
    }

    printf("\nINICIO\n");

    srand(time(NULL));

    prendas = 10;
    
    ropa[0].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[0].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[0].tiempo = 0;
    ropa[0].precio = 0;
    ropa[1].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[1].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[1].tiempo = 0;
    ropa[1].precio = 0;
    ropa[2].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[2].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[2].tiempo = 0;
    ropa[2].precio = 0;
    ropa[3].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[3].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[3].tiempo = 0;
    ropa[3].precio = 0;
    ropa[4].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[4].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[4].tiempo = 0;
    ropa[4].precio = 0;
    ropa[5].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[5].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[5].tiempo = 0;
    ropa[5].precio = 0;
    ropa[6].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[6].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[6].tiempo = 0;
    ropa[6].precio = 0;
    ropa[7].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[7].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[7].tiempo = 0;
    ropa[7].precio = 0;
    ropa[8].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[8].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[8].tiempo = 0;
    ropa[8].precio = 0;
    ropa[9].tipo_material = ROPA_NYLON + (rand() % (ROPA_ALGODON - ROPA_NYLON + 1));
    ropa[9].tipo_color =  ROPA_BLANCA + (rand() % (ROPA_COLOR - ROPA_BLANCA + 1));
    ropa[9].tiempo = 0;
    ropa[9].precio = 0;

    espera_semaforo(id_semaforo);
        for (i=0; i<LAVARROPAS; i++){
            enviar_mensaje(id_cola_mensajes, MSG_LAVARROPAS+i, MSG_CONTROLLER, EVT_INICIO_LAVADO, ropa[contador_enviadas].tipo_material, ropa[contador_enviadas].tipo_color, 0, 0);
            contador_enviadas++;
            printf("\nCONTADOR ENVIADAS= %d", contador_enviadas);
            printf("\nCONTADOR RECIBIDAS= %d", contador_recibidas);
            printf("\nPRENDAS = %d\n", prendas);
        }
    levanta_semaforo(id_semaforo);

    while (contador_recibidas < prendas){
        usleep(100 * 1000);
        recibidos = 0;
        espera_semaforo(id_semaforo);
            recibidos = recibir_mensaje_no_bloqueante(id_cola_mensajes, MSG_CONTROLLER, &mensaje);
            if (recibidos > 0){
                if (mensaje.evt == EVT_FIN_LAVADO){
                    printf("\nLavado: %d", contador_recibidas+1);
                    printf("\nMaterial: %d\tColor: %d\tTiempo: %d\tPrecio: %d\n", mensaje.tipo_material, mensaje.tipo_color, mensaje.tiempo, mensaje.precio);
                    contador_recibidas++;
                    if (contador_enviadas < prendas){
                        enviar_mensaje(id_cola_mensajes, mensaje.src, MSG_CONTROLLER, EVT_INICIO_LAVADO, ropa[contador_enviadas].tipo_material, ropa[contador_enviadas].tipo_color, 0, 0);
                        contador_enviadas++;
                    }
                    printf("\nCONTADOR = %d", contador_enviadas);
                    printf("\nCONTADOR = %d", contador_recibidas);
                    printf("\nPRENDAS = %d\n", prendas);
                }
            }
        levanta_semaforo(id_semaforo);
    }

    espera_semaforo(id_semaforo);
        for (i=0; i<LAVARROPAS; i++){
            enviar_mensaje(id_cola_mensajes, MSG_LAVARROPAS+i, MSG_CONTROLLER, EVT_FIN, 0, 0, 0, 0);
        }
    levanta_semaforo(id_semaforo);

    sleep(3);

    espera_semaforo(id_semaforo);
        memoria_inicio->estado = EVT_FIN;
    levanta_semaforo(id_semaforo);

    printf("\nFIN LAVADOS\n");
    
    borrar_mensajes(id_cola_mensajes);
    msgctl (id_cola_mensajes, IPC_RMID, NULL);

    usleep(500 * 1000);

    shmdt((char *)memoria_inicio);
    shmctl(id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

    return 0;
}
