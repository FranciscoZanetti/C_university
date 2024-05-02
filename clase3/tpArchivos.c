#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesTpArchivos.h"


/* Muestra los productos de la lista */
void mostrar(Result *p){
	if (p->sig != NULL){
		printf("%s\n", p->producto);
		mostrar(p->sig);
	}
}


int main(int argc, char *argv[]){
	int result, unidades;
	Result *p = NULL;
	/* Producir bien escrito */
	if (argc == 3 && (strcmp(argv[1], "producir") == 0)){
		result = producir(argv[2]);
		switch (result){
			case 1:
				printf("Ocurrio un error en el manejo de archivos.\n");
				break;
			case 2:
				printf("Error. Aun hay unidades del producto '%s' en stock.\n", argv[2]);
				break;
			default:
				printf("10 unidades del producto '%s'puestas en stock.\n", argv[2]);
				break;
		}
	}

	/* Consumir bien escrito */
	if (argc == 4 && (strcmp(argv[1], "consumir") == 0)){
		unidades = atoi(argv[3]);
		p = (Result *)malloc(sizeof(Result));
		consumir(p, argv[2], unidades);
		if (p->result == 1){
			printf("Ocurrio un error en el manejo de archivos.\n");
		}
		if (p->result == 2){
			printf("No quedan suficientes unidades en stock.\n");
		}
		else{
			printf("Productos consumidos:\n");
			mostrar(p);
		}
	}

	/* Parametros incorrectos */
	else{
		printf("Error. Los parametros ingresados son incorrectos.\n");
		printf("Forma de uso:\n");
		printf("./tpArchivos producir <producto>\n");
		printf("./tpArchivos consumir <producto> <unidades>\n");
	}
	
	free(p);
	return 0;
}
