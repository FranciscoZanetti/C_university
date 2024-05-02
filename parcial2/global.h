#ifndef GLOBAL_H
#define GLOBAL_H

#include <pthread.h>

#define CLAVE 33
#define FORMULAS 2
#define PADRON 100
#define INTERVALO 100

typedef struct tipo_mensaje{
    long dest;
    int src;
    int evt;
}Mensaje;

typedef struct tipo_datosThread{
    int idHilo;
    int id_cola_mensajes;
    int id_semaforo;
    int *estado; /* puntero  memoria compartida */
}DatosThread;

typedef struct tipo_formula{
    int id;
    char presidente[4];
    char vice[3];
    int votos;
}Formula;

typedef enum{
    MSG_NADIE,
    MSG_PANEL,
    MSG_VOTANTE
}Destinos;

typedef enum{
    NADA,
    MS,
    MI,
    FIN
}Eventos;

extern pthread_mutex_t mutex;

#endif
