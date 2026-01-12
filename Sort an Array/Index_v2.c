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
    for (int j = low; j <= high; j++) {
        if (nums[j] < pivot) {
            i += 1;
            swap(&nums[j], &nums[i]);
        }
    }

    swap(&nums[high], &nums[i + 1]);
    return i + 1;
}


void quick_sort(int *nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        swap(&nums[mid], &nums[high]);
        int pivot_index = partition(nums, low, high);
        quick_sort(nums, low, pivot_index - 1);
        quick_sort(nums, pivot_index + 1, high);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int *ans = (int *) malloc(sizeof(int) * numsSize);
    memcpy(ans, nums, sizeof(int) * numsSize);


    quick_sort(ans, 0, numsSize - 1);
    return ans;
}
