#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "c_vector.h"

int main() {
    int initial_size;
    printf("Enter the initial size of the array: ");
    scanf("%d", &initial_size);

    if (initial_size <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int* array = create(initial_size);
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < initial_size; i++) {
        array[i] = (rand() % 201) - 100;
    }

    printf("Original array:\n");
    print(array, initial_size);

    int add_elements = 5;
    for (int i = 0; i < add_elements; i++) {
        int random_value = (rand() % 201) - 100;
        push_back(&array, &initial_size, random_value);
    }

    printf("Array after adding new elements:\n");
    print(array, initial_size);

    destroy(array);
    return 0;
}