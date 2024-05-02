#ifndef _MEMORIACOMPARTIDA_H
#define _MEMORIACOMPARTIDA_H

#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

void* creo_memoria(int size, int* r_id_memoria, int clave_base);


#endif