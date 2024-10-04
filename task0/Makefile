CC = gcc
CFLAGS = -Wall
OBJ = main.o points.o
LIBS = -lm

all: program

program: $(OBJ)
	$(CC) -o program $(OBJ) $(LIBS)

main.o: main.c points.h
	$(CC) $(CFLAGS) -c main.c

points.o: points.c points.h
	$(CC) $(CFLAGS) -c points.c

clean:
	rm -f *.o program


