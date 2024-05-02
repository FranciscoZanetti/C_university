#ifndef MENSAJES_H
#define MENSAJES_H

#include "global.h"

int creo_id_cola_mensajes(int clave);
int enviar_mensaje(int id_cola_mensajes, long dest, int src, int evt);
int recibir_mensaje_bloqueante(int id_cola_mensajes, long dest, Mensaje *rMsg);
int recibir_mensaje_no_bloqueante(int id_cola_mensajes, long dest, Mensaje *rMsg);
int borrar_mensajes(int id_cola_mensajes);

#endif
