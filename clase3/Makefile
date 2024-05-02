CC = gcc
CFLAGS = -Wall -Wextra -std=gnu89 -pedantic-errors -O3

TARGET = tpArchivos
SRC = tpArchivos.c funcionesTpArchivos.c
HDR = funcionesTpArchivos.h

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
