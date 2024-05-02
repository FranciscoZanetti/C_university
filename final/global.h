#ifndef GLOBAL_H
#define GLOBAL_H

#include <pthread.h>

#define CLAVE 33
#define CLAVE2 44
#define INTERVALO 400
#define EVENTOS 4
#define PRECIO_COMUN 0
#define PRECIO_COLOR 1
#define PRECIO_NYLON 5
#define PRECIO_ALGODON 7
#define TIEMPO_NYLON 450
#define TIEMPO_ALGODON 600
#define LAVARROPAS 4

typedef struct tipo_mensaje{
    long dest;
    int src;
    int evt;
    int tipo_material;
    int tipo_color;
    int tiempo;
    int precio;
}Mensaje;

typedef struct tipo_memoria{
    int estado;
    int inicio_controller;
    int inicio_lavarropas;
}Memoria;

typedef struct tipo_datosThread{
    int idHilo;
    int id_cola_mensajes;
    int id_semaforo;
    int numero_lavarropas;
    /*struct tipo_memoria *memoria_lavarropas;*/ /* puntero  memoria compartida */
}DatosThread;

typedef enum{
	MSG_NADIE,
    MSG_CONTROLLER,
    MSG_LAVARROPAS
}Destinos;

typedef enum{
    EVT_NADA,
    EVT_INIT,
    EVT_INICIO_LAVADO,
    EVT_FIN_LAVADO,
    EVT_FIN
}Eventos;

typedef enum{
    ROPA_NYLON,
    ROPA_ALGODON
}TipoMaterial;

typedef enum{
    ROPA_BLANCA,
    ROPA_OSCURA,
    ROPA_COLOR
}TipoColor;

extern pthread_mutex_t mutex;

#endif
