#include "index.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    for (int i = 0; i < numsSize; i++) {

        int target = nums[i];
        
        for (int j = 0; j < numsSize; j++) {
            if (j == i) {
                continue;
            }
            int another = (-target) - nums[j];
            for (int k = 0; k < numsSize; k++) {
                if (k == j || k == i) {
                    continue;
                }
                if (nums[k] == another) {
                    printf("[%d|%d|%d]: %d\t%d\t%d\n", i, j, k, nums[i], nums[j], nums[k]);
                    break;
                }
            }
        }
        
    }
}


int main(void) {
    return 0;
}