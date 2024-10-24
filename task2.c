#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define RANGE 10

int main() {
    int numbers[N];
    int occurrences[RANGE + 1] = {0};
    int indices[RANGE + 1];
    int i, j, temp;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        numbers[i] = rand() % RANGE + 1;
        occurrences[numbers[i]]++;
    }

    for (i = 0; i <= RANGE - 1; i++) {
        indices[i] = i;
    }

    for (i = 0; i <= RANGE - 1; i++) {
        for (j = 1; j <= RANGE - i; j++) {
            if (occurrences[indices[j]] < occurrences[indices[j + 1]]) {
                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    for (i = 0; i <= RANGE - 1; i++) {
        if (occurrences[indices[i]] > 0) {
            printf("Number %d: %d times\n", indices[i], occurrences[indices[i]]);
        }
    }

    return 0;
}
//Time Complexity: O(N^2)
//Space Complexity: O(N^2)
