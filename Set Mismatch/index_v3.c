#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int hashTable[100001] = { 0 };
    (*returnSize) = 2;
    int *ans = (int *) malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        if (hashTable[nums[i]] == 1) {
            ans[0] = nums[i];
        } else {
            hashTable[nums[i]] = 1;
        }
    }
    
    for (int i = 1; i < 100001; i++) {
        if (hashTable[i] == 0) {
            ans[1] = i;
            break;
        }
    }
    return ans;
}