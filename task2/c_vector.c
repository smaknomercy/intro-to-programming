#include <stdio.h>
#include <stdlib.h>
#include "c_vector.h"

void init_vector_methods(Vector* vector) {
    vector->push_back = push_back;
    vector->pop_back = pop_back;
    vector->get_size = get_size;
    vector->get_capacity = get_capacity;
    vector->clear = clear;
    vector->print = print;
    vector->destroy = destroy;
}

Vector* create(int initial_capacity) {
    if (initial_capacity <= 0) initial_capacity = 1;

    Vector* vector = (Vector*)malloc(sizeof(Vector));
    if (!vector) return NULL;

    vector->data = (int*)malloc(initial_capacity * sizeof(int));
    if (!vector->data) {
        free(vector);
        return NULL;
    }

    vector->size = 0;
    vector->capacity = initial_capacity;
    init_vector_methods(vector);
    return vector;
}

void push_back(Vector* vector, int value) {
    if (vector->size == vector->capacity) {
        int new_capacity = vector->capacity * 2;
        int* new_data = (int*)realloc(vector->data, new_capacity * sizeof(int));
        if (!new_data) return;

        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    vector->data[vector->size++] = value;
}

void pop_back(Vector* vector) {
    if (vector->size == 0) return;
    vector->size--;

    if (vector->size < vector->capacity / 2 && vector->capacity > 1) {
        int new_capacity = vector->capacity / 2;
        int* new_data = (int*)realloc(vector->data, new_capacity * sizeof(int));
        if (new_data) {
            vector->data = new_data;
            vector->capacity = new_capacity;
        }
    }
}

int get_size(const Vector* vector) {
    return vector->size;
}

int get_capacity(const Vector* vector) {
    return vector->capacity;
}

void clear(Vector* vector) {
    vector->size = 0;
}

void print(const Vector* vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}

void destroy(Vector* vector) {
    free(vector->data);
    free(vector);
}