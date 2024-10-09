#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define RANGE 10

int main() {
    int numbers[N];
    int occurrences[RANGE + 1] = {0};
    int i, j;

    srand(time(NULL));
    for (i = 0; i < N; i++) {
        numbers[i] = rand() % RANGE + 1;
        occurrences[numbers[i]]++;
    }
    for (i = RANGE; i >= 1; i--) {
        if (occurrences[i] > 0) {
            printf("Number %d: %d times\n", i, occurrences[i]);
        }
    }
    return 0;
}

//Time Complexity: O(N)
//Space Complexity: O(N)