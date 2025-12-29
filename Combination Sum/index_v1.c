#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool canbind(int* candidates, int candidatesSize, int index, int k, int limit) {
    if (index == candidatesSize) {
        if (k == limit) {
            return true;
        } else {
            return false;
        }
    }
    for (int i = index; i < candidatesSize; i++) {
        canbind(candidates, candidatesSize, i + 1, k + candidates[i], limit);
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    for (int i = 0; i < candidatesSize; i++) {
        int j = i;
        while (j < candidatesSize) {
            
        }
    }
    for (int i = candidatesSize - 1; i >= 0; i--) {
        int n = target;
        int tmp[40] = {0};
        int tmp_index = 0;
        for (int j = i; j >= 0;) {
            
            tmp[tmp_index++] = candidates[j];
            if (n - candidates[j] >= 0) {
                n -= candidates[j];
            }
        }
    }
}