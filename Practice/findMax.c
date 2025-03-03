#include <stdio.h>

int *findMax(int *arr, int size) {
    if (size <= 0) {
        return NULL; // Handle empty array case
    }
    int *maxPtr = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }
    return maxPtr;
}

int main() {
    int arr[] = {10, 5, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *maxPtr = findMax(arr, size);
    printf("Maximum element: %d\n", *maxPtr);
    return 0;
}