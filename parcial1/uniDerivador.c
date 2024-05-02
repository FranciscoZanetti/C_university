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


int main(){
    int id_semaforo, resultadoScanf, resultadoEscritura, opcion, tipo;
    char archivo[20];
    FILE *inicio = NULL;
    Alumno alumno;
    Alumno *alumnos;

    inicio = fopen(INICIO, "w");
    if (inicio == NULL){
        printf("\nNo se pudo iniciar el proceso.\n");
    }
    else{

        id_semaforo = creo_semaforo();
        inicia_semaforo(id_semaforo, 1);

        do{

            memset(archivo, 0, sizeof(archivo));
            alumnos = NULL;
            alumnos = (Alumno *)malloc(sizeof(Alumno));
            alumnos->sig = NULL;

            do{
                printf("\nSeleccione la operacion a realizar:");
                printf("\n1 - Cargar alumno");
                printf("\n2 - Leer alumnos inscriptos");
                printf("\n0 - terminar\n");
                scanf("%d", &opcion);
            } while(opcion != 0 && opcion != 1 && opcion != 2);

            if (opcion != 0){

                if (opcion == 1){
                    printf("\nIngrese el legajo: ");
                    scanf("%d", &alumno.legajo);

                    printf("\nIngrese nombre (apellido luego): ");
                    scanf("%s", alumno.nombre);
                    printf("\nIngrese apellido: ");
                    scanf("%s", alumno.apellido);

                    do{

                        printf("\nIngrese el tipo de alumno:");
                        printf("\n1 - inicial");
                        printf("\n2 - con materias a validar");
                        scanf("%d", &tipo);

                    } while(tipo != 1 && tipo != 2);

                    if (tipo == 1){
                        alumno.materias = 0;
                        strcpy(archivo, ARCHIVOINICIALES);
                    }
                    else{

                        strcpy(archivo, ARCHIVOAVALIDAR);
                        printf("\nIngrese el numero de materias a validar: ");
                        scanf("%d", &alumno.materias);

                    }

                    espera_semaforo(id_semaforo);

                        resultadoEscritura = escribirArchivoAlFinal(archivo, alumno);

                    levanta_semaforo(id_semaforo);

                    if (resultadoEscritura != 0){
                        printf("\nError de escritura.\n");
                    }
                    else{
                        printf("\nAlumno inscripto.\n");
                    }
                    
                }
                else{

                    do{
                        printf("\nIngrese tipo de alumno a leer: ");
                        printf("\n1 - iniciales");
                        printf("\n2 - con materias a vallidar\n");
                        scanf("%d", &tipo);
                    } while(tipo != 1 && tipo != 2);

                    if (tipo == 1){
                        strcpy(archivo, ARCHIVOINICIALES);
                    }
                    else{
                        strcpy(archivo, ARCHIVOAVALIDAR);
                    }

                    espera_semaforo(id_semaforo);

                        leerArchivo(alumnos, archivo);

                    levanta_semaforo(id_semaforo);

                    if (alumnos->sig != NULL){
                        printf("\nAlumnos:\n");

                        if (alumnos->materias == 0){
                            printf("\nLEGAJO\tNOMBRE\tAPELLIDO\n");
                        }
                        else{
                            printf("\nLEGAJO\tNOMBRE\tAPELLIDO\tMATERIAS A VALIDAR\n");
                        }

                        mostrar(alumnos);
                    }
                    else{
                        printf("\nNo hay alumnos inscriptos en esta categoria.\n");
                    }

                }

            }
            else{

                remove(INICIO);

            }

            liberarLista(alumnos);
            

        }while (opcion != 0);

        printf("\nProceso terminado.\n");

    }

    fclose(inicio);

    return 0;
}
