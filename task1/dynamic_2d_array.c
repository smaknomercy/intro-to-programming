#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_2d_array.h"

// Allocate the 2D array
char** allocate_2d_array(int size) {
    char** arr = (char**)malloc(size * sizeof(char*));
    if (!arr) {
        printf("Failed to allocate memory for rows");
        return NULL;
    }
    return arr;
}

// Fills each row with a string entered by the user
int fill_2d_array(char** arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Enter string for row %d: ", i + 1);
        size_t len = 0;
        arr[i] = NULL;
        if (getline(&arr[i], &len) == -1) {
            printf("Failed to read line");
            return -1;
        }
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }
    return 0;
}

// Sort characters in every row
void sort_2d_array(char** arr, int size) {
    for (int i = 0; i < size; ++i) {
        int len = strlen(arr[i]);
        for (int j = 0; j < len - 1; ++j) {
            for (int k = j + 1; k < len; ++k) {
                if (arr[i][j] > arr[i][k]) {
                    char temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
            }
        }
    }
}

// Sort every row
void sort_rows_2d_array(char** arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Print the array
void print_2d_array(const char** arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s\n", arr[i]);
    }
}

// Free the allocated memory for the 2D array
void free_2d_array(char** arr, int size) {
    for (int i = 0; i < size; ++i) {
        free(arr[i]);
    }
    free(arr);
}