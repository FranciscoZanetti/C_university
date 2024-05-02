#ifndef GLOBAL_H
#define GLOBAL_H

#define CLAVE_COLA 33

typedef struct tipo_peaje{
    int nro_vias;
    int id_cola_mensajes;
}tpeaje;

typedef enum{
    MSG_NADIE,
    MSG_AUTOS,
    MSG_VIAS,
}Destinos;

/* si hace falta mutex... */
pthread_mutex_t mutex;

#endif
