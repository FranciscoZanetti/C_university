#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>
#include "clave.h"
#include "global.h"
#include "mensajes.h"

int creo_id_cola_mensajes(int clave){
    int id_cola_mensajes = msgget(creo_clave(clave), 0600 | IPC_CREAT);
    if (id_cola_mensajes == -1)
    {
        printf("Error al obtener identificador para cola mensajes\n");
        exit(-1);
    }
    return id_cola_mensajes;
}

int enviar_mensaje(int id_cola_mensajes, long dest, int src, int evt, int tipo_material, int tipo_color, int tiempo, int precio){
    Mensaje msg;
    msg.dest = dest;
    msg.src = src;
    msg.evt = evt;
    msg.tipo_material = tipo_material;
    msg.tipo_color = tipo_color;
    msg.tiempo = tiempo;
    msg.precio = precio;
    return msgsnd(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.src) + sizeof(msg.evt) + sizeof(msg.tipo_material) + sizeof(msg.tipo_color) + sizeof(msg.tiempo) + sizeof(msg.precio), IPC_NOWAIT);
}

int recibir_mensaje_bloqueante(int id_cola_mensajes, long dest, Mensaje *rMsg){
    Mensaje msg;
    int res;
    res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.src) + sizeof(msg.evt) + sizeof(msg.tipo_material) + sizeof(msg.tipo_color) + sizeof(msg.tiempo) + sizeof(msg.precio), dest, 0);
    rMsg->dest = msg.dest;
    rMsg->src = msg.src;
    rMsg->evt = msg.evt;
    rMsg->tipo_material = msg.tipo_material;
    rMsg->tipo_color = msg.tipo_color;
    rMsg->tiempo = msg.tiempo;
    rMsg->precio = msg.precio;
    return res;
}

int recibir_mensaje_no_bloqueante(int id_cola_mensajes, long dest, Mensaje *rMsg){
    Mensaje msg;
    int res;
    res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.src) + sizeof(msg.evt) + sizeof(msg.tipo_material) + sizeof(msg.tipo_color) + sizeof(msg.tiempo) + sizeof(msg.precio), dest, IPC_NOWAIT);
    rMsg->dest = msg.dest;
    rMsg->src = msg.src;
    rMsg->evt = msg.evt;
    rMsg->tipo_material = msg.tipo_material;
    rMsg->tipo_color = msg.tipo_color;
    rMsg->tiempo = msg.tiempo;
    rMsg->precio = msg.precio;
    return res;
}

int borrar_mensajes(int id_cola_mensajes){
    Mensaje msg;
    int res;
    do{
        res = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.src) + sizeof(msg.evt) + sizeof(msg.tipo_material) + sizeof(msg.tipo_color) + sizeof(msg.tiempo) + sizeof(msg.precio), 0, IPC_NOWAIT);
    }while (res > 0);
    return res;
}
