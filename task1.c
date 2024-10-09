#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int main() {
    int original[N][N], rotationed[N][N];
    srand(time(0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            original[i][j] = rand() % 10;

    printf("2D Array elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", original[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            rotationed[j][i] = original[i][j];

    printf("\n2D Array elements after rotation:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", rotationed[i][j]);
        printf("\n");
    }
    return 0;
}

//Time Complexity: O(N^2)
//Space Complexity: O(N^2)