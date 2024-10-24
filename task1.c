#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initializeArray(int arr[SIZE][SIZE]) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 11;
        }
    }
}

void printArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

void setZeros(int arr[SIZE][SIZE]) {
    int rows[SIZE] = {0};
    int cols[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rows[i] == 1 || cols[j] == 1) {
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    int arr[SIZE][SIZE];

    initializeArray(arr);
    printf("Original array:\n");
    printArray(arr);

    setZeros(arr);
    printf("\nModified array:\n");
    printArray(arr);

    return 0;
}
