CC = gcc-4.1
CFLAGS = -Wall -Wextra -std=gnu89 -pedantic-errors -O3
LIBS = -pthread

TARGET1 = carga1
TARGET2 = reserva1
SRC1 = carga1.c funciones1.c semaforos.c
SRC2 = reserva1.c funciones1.c semaforos.c
HDR = funciones1.h semaforos.h

all: clean $(TARGET1) $(TARGET2)

$(TARGET1): $(SRC1) $(HDR)
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET1) $(LIBS)

$(TARGET2): $(SRC2) $(HDR)
	$(CC) $(CFLAGS) $(SRC2) -o $(TARGET2) $(LIBS)

clean:
	rm -f $(TARGET1) $(TARGET2)
