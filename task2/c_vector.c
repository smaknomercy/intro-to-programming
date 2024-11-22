#include <stdio.h>
#include <stdlib.h>
#include "c_vector.h"

// Create and return an array of integers with the initial size
int* create(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    return array;
}

// Add new element to the end of the array and updates its size
void push_back(int** ptr, int* size, int value) {
    int* new_array = (int*)realloc(*ptr, (*size + 1) * sizeof(int));
    if (new_array != NULL) {
        new_array[*size] = value;
        *ptr = new_array;
        (*size)++;
    }
}

// Print all elements in the array
void print(const int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

// Free the memory allocated for the array
void destroy(int* ptr) {
    free(ptr);
}