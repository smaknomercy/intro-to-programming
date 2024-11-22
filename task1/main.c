#include <stdio.h>
#include <stdlib.h>
#include "dynamic_2d_array.h"

int main() {
    int size;
    printf("Enter the number of rows in the 2D array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("%d is invalid input\n", size);
        return 0;
    }
    getchar();

    char** arr = allocate_2d_array(size);
    if (!arr) {
        return 1;
    }

    if (fill_2d_array(arr, size) == -1) {
        free_2d_array(arr, size);
        return 1;
    }

    printf("\nOriginal array:\n");
    print_2d_array((const char**)arr, size);

    sort_rows_2d_array(arr, size);
    printf("\nSorted rows:\n");
    print_2d_array((const char**)arr, size);

    sort_2d_array(arr, size);
    printf("\nSorted characters in the rows:\n");
    print_2d_array((const char**)arr, size);

    free_2d_array(arr, size);
    return 0;
}
