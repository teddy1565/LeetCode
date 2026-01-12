#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int p = *a;
    *a = *b;
    *b = p;
}

int partition(int *nums, int low, int high) {
    int pivot = nums[high];

    int i = low - 1;

    for (int j = low; j <= high ; j++) {
        if (nums[j] < pivot) {
            i += 1;
            swap(&nums[i], &nums[j]);
        }
    }

    if (nums[i + 1] != nums[high]) {
        swap(&nums[i + 1], &nums[high]);
    }
    return i + 1;
}


void quickSort(int *nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        swap(&nums[mid], &nums[high]);
        int pivot_index = partition(nums, low, high);
        quickSort(nums, low, pivot_index - 1);
        quickSort(nums, pivot_index + 1, high);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int *ans = (int *) malloc(sizeof(int) * numsSize);
    memcpy(ans, nums, sizeof(int) * numsSize);


    quickSort(ans, 0, numsSize - 1);
    return ans;
}
