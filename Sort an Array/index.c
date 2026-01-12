#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void quick_sort(int *nums, int low, int high) {
    if (low >= high) {
        return;
    }

    int randomIndex = low + rand() % (high - low + 1);
    int mid = low + (high - low) / 2;
    swap(&nums[randomIndex], &nums[low]);
    int pivot = nums[low];
    int lt = low;
    int ht = high;
    int i = low + 1;

    while (i <= ht) {
        if (nums[i] < pivot) {
            swap(&nums[i], &nums[lt]);
            lt += 1;
            i += 1;
        } else if (nums[i] > pivot) {
            swap(&nums[i], &nums[ht]);
            ht -= 1;
        } else {
            i += 1;
        }
    }

    quick_sort(nums, low, lt - 1);
    quick_sort(nums, ht + 1, high);
}
/**
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int *ans = (int *) malloc(sizeof(int) * numsSize);
    memcpy(ans, nums, sizeof(int) * numsSize);
    // 在 sortArray 裡面初始化隨機種子
    srand(time(NULL));

    quick_sort(ans, 0, numsSize - 1);
    return ans;
}

