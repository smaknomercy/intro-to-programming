#include "rotation.h"

void init_array(int *arr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(arr + i * n + j) = rand() % 101; // 1111 2222 3333 4444
        }
    }
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", *(arr + i * n + j));
        }
        printf("\n");
    }
}

void rotate_array(int *arr, int *rotated, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(rotated + j * n + i) = *(arr + i * n + j);
        }
    }
}