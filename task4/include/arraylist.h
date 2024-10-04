#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

// Функції для роботи зі списком
ArrayList* create_list(int capacity);
void add(ArrayList *list, int item);
void insert(ArrayList *list, int index, int item);
int size(ArrayList *list);
void remove_item(ArrayList *list, int index);
void set(ArrayList *list, int index, int item);
int get(ArrayList *list, int index);
void free_list(ArrayList *list);

#endif
