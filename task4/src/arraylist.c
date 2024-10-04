#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

ArrayList* create_list(int capacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(ArrayList *list, int item) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = item;
}

void insert(ArrayList *list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds\n");
        return;
    }
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = item;
    list->size++;
}

int size(ArrayList *list) {
    return list->size;
}

void remove_item(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

void set(ArrayList *list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }
    list->data[index] = item;
}

int get(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }
    return list->data[index];
}

void free_list(ArrayList *list) {
    free(list->data);
    free(list);
}
