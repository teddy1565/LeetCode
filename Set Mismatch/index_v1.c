#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int base = nums[0];
    (*returnSize) = 2;
    int *ans = (int *) malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + base) {
            ans[0] = nums[i];
            ans[1] = i + base;
        }
    }
    return ans;
}