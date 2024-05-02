CC = gcc
CFLAGS1 = -Wall -Wextra -std=gnu89 -pedantic-errors -O3
CFLAGS2 = -Wall -Wextra -std=gnu89 -pedantic-errors -O3 -pthread

TARGET1 = controller
SRC1 = controller.c semaforos.c mensajes.c clave.c global.c memoriaCompartida.c
HDR1 = semaforos.h mensajes.h clave.h global.h memoriaCompartida.h

TARGET2 = lavarropas
SRC2 = lavarropas.c threads.c semaforos.c mensajes.c clave.c global.c memoriaCompartida.c
HDR2 = threads.h semaforos.h mensajes.h clave.h global.h memoriaCompartida.h

all: clean $(TARGET1) $(TARGET2)

$(TARGET1): $(SRC1) $(HDR1)
	$(CC) $(CFLAGS1) $(SRC1) -o $(TARGET1)

$(TARGET2): $(SRC2) $(HDR2)
	$(CC) $(CFLAGS2) $(SRC2) -o $(TARGET2)
clean:
	rm -f $(TARGET1) $(TARGET2)
