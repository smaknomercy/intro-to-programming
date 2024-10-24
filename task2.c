#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n);
int binary_search_recursive(int arr[], int left, int right, int value);
int binary_search_loop(int arr[], int n, int value);
void print_array(int arr[], int n);

int main() {
    int arr[10];
    int n = 10, value, result;
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array: ");
    print_array(arr, n);

    printf("Enter value to search for: ");
    scanf("%d", &value);

    bubble_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    result = binary_search_recursive(arr, 0, n - 1, value);
    if (result != -1) {
        printf("Value %d found at index %d using recursive binary search.\n", value, result);
    } else {
        printf("Value %d not found using recursive binary search.\n", value);
    }

    result = binary_search_loop(arr, n, value);
    if (result != -1) {
        printf("Value %d found at index %d using loop-based binary search.\n", value, result);
    } else {
        printf("Value %d not found using loop-based binary search.\n", value);
    }

    return 0;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search_recursive(int arr[], int left, int right, int value) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binary_search_recursive(arr, left, mid - 1, value);
        }

        return binary_search_recursive(arr, mid + 1, right, value);
    }

    return -1;
}

int binary_search_loop(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
