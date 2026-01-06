#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    int k = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != k) {
            return false;
        }
    }
    return true;
}
