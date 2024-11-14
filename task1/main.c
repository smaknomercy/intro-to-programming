#include "rotation.h"
#define SIZE 4

int main() {
    int arr[SIZE][SIZE];
    int rotated[SIZE][SIZE];

    init_array((int *)arr, SIZE);
    printf("Original Array:\n");
    print_array((int *)arr, SIZE);

    rotate_array((int *)arr, (int *)rotated, SIZE);
    printf("\nRotated Array (Transposed):\n");
    print_array((int *)rotated, SIZE);

    return 0;
}