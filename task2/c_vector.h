#ifndef C_VECTOR_H
#define C_VECTOR_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stddef.h>

typedef struct Vector
{
    int *data;    // Pointer to the integer array
    int size;     // Current number of elements in the vector
    int capacity; // Total allocated capacity for the vector
    // Function pointers for vector operations

    void (*push_back)(struct Vector *vector, int value); // Adds an integer to the end of the vector
    void (*pop_back)(struct Vector *vector);             // Removes the last element from the vector
    int (*get_size)(const struct Vector *vector);        // Returns the current size of the vector
    int (*get_capacity)(const struct Vector *vector);    // Returns the total capacity of the vector
    void (*clear)(struct Vector *vector);                // Empties the vector, freeing its elements
    void (*print)(const struct Vector *vector);          // Prints all elements in the vector
    void (*destroy)(struct Vector *vector);              // Frees memory associated with the vector
} Vector;

Vector *create(int initial_capacity);
void push_back(Vector *vector, int value);
void pop_back(Vector *vector);
int get_size(const Vector *vector);
int get_capacity(const Vector *vector);
void clear(Vector *vector);
void print(const Vector *vector);
void destroy(Vector *vector);

#ifdef __cplusplus
}
#endif

#endif