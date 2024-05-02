#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "definiciones.h"
#include "funciones.h"
#include "semaforos.h"

/*typedef struct Alumno{
    int legajo;
    int materias;
    char nombre[20];
    char apellido[20];
    struct Alumno *sig;
    int result;
}Alumno;*/


int main(int argc, char *argv[]){
    int id_semaforo, resultadoEscritura, tipo;
    FILE *inicio = NULL;
    Alumno *alumnos = NULL;
    char archivo[20];

    if (argc == 2){

        tipo = atoi(argv[1]);
        
        if (tipo != 1 && tipo != 2){
            printf("\nMal uso de argumentos.\n");
        }
        else{

            id_semaforo = creo_semaforo();
            memset(archivo, 0, sizeof(archivo));

            while(1){

                inicio = fopen(INICIO, "r");
                if (inicio == NULL){
                    printf("\nEsperando al proceso principal...\n");
                    sleep(5);
                }
                else{

                    fclose(inicio);

                    while(1){

                        alumnos = (Alumno *)malloc(sizeof(Alumno));
                        alumnos->sig = NULL;

                        inicio = fopen(INICIO, "r");
                        if (inicio == NULL){
                            printf("\nProceso terminado.\n");
                            free(alumnos);
                            exit(0);
                        }
                        else{

                            if (tipo == 1){
                                strcpy(archivo, ARCHIVOINICIALES);
                            }
                            else{
                                strcpy(archivo, ARCHIVOAVALIDAR);
                            }

                            espera_semaforo(id_semaforo);

                                leerArchivo(alumnos, archivo);

                            levanta_semaforo(id_semaforo);

                            printf("\nAlumnos inscriptos:\n");

                            if (alumnos->sig != NULL){

                                mostrar(alumnos);

                            }

                            usleep(ESPERA * 1000);

                        }

                        liberarLista(alumnos);
                        fclose(inicio);

                    }

                    break;

                }

            }

        }


    }
    else{
        printf("\nMal uso de argumentos.\n");
    }

    return 0;

}
