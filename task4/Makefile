CC = gcc
CFLAGS = -Wall -Iinclude -fPIC
SRC_FILES = src/arraylist.c src/main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: static dynamic

# Створення статичної бібліотеки
static: $(OBJ_FILES)
	ar rcs lib/libarraylist.a src/arraylist.o
	$(CC) $(CFLAGS) -o bin/program_static src/main.c -Llib -larraylist

# Створення динамічної бібліотеки
dynamic: $(OBJ_FILES)
	$(CC) -shared -o lib/libarraylist.so src/arraylist.o
	$(CC) $(CFLAGS) -o bin/program_shared src/main.c -Llib -larraylist

# Правило для компіляції об'єктних файлів
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) bin/program_static bin/program_shared lib/libarraylist.a lib/libarraylist.so

