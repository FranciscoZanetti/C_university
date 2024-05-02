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
#include "threads.h"


void *threadLavarropas(void *parametro){
    int idHilo, id_cola_mensajes, id_semaforo, numero_lavarropas, recibidos;
    DatosThread *datosThread = (DatosThread*) parametro;
    Mensaje mensaje;

    idHilo = datosThread->idHilo;
    id_cola_mensajes = datosThread->id_cola_mensajes;
    id_semaforo = datosThread->id_semaforo;
    numero_lavarropas = datosThread->numero_lavarropas;

    mensaje.evt = EVT_INIT;

    do{
        usleep(500 * 1000);
        pthread_mutex_lock(&mutex);
            espera_semaforo(id_semaforo);
                recibidos = recibir_mensaje_no_bloqueante(id_cola_mensajes, numero_lavarropas, &mensaje);
            levanta_semaforo(id_semaforo);

            if (recibidos > 0){
                if (mensaje.evt == EVT_INICIO_LAVADO){
                    if (mensaje.tipo_material == ROPA_NYLON){
                        mensaje.tiempo = TIEMPO_NYLON;
                        mensaje.precio = PRECIO_NYLON;
                    }
                    if (mensaje.tipo_material == ROPA_ALGODON){
                        mensaje.tiempo = TIEMPO_ALGODON;
                        mensaje.precio = PRECIO_ALGODON;
                    }
                    if (mensaje.tipo_color == ROPA_COLOR){
                        mensaje.precio += PRECIO_COLOR;
                    }

                    usleep(mensaje.tiempo * 1000);

                    espera_semaforo(id_semaforo);
                        enviar_mensaje(id_cola_mensajes, MSG_CONTROLLER, numero_lavarropas, EVT_FIN_LAVADO, mensaje.tipo_material, mensaje.tipo_color, mensaje.tiempo, mensaje.precio);
                    levanta_semaforo(id_semaforo);

                    printf("\nLavarropas %d lavo:\n", numero_lavarropas);
                    printf("Material: %d\tColor: %d\tTiempo: %d\tPrecio: %d", mensaje.tipo_material, mensaje.tipo_color, mensaje.tiempo, mensaje.precio);
                }
            }
        pthread_mutex_unlock(&mutex);
    }while (mensaje.evt != EVT_FIN);

    pthread_exit((void*)0);
}
