#ifndef _SEMAFOROS
#define _SEMAFOROS

#include <sys/ipc.h>
#include <sys/sem.h>

#define ROJO 0
#define VERDE 1
#define CLAVE_BASE 33

key_t creo_clave(int r_clave);
int creo_semaforo();
void inicia_semaforo(int id_semaforo, int valor);
void levanta_semaforo(int id_semaforo);
void espera_semaforo(int id_semaforo);

#endif
