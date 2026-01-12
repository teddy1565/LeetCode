#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// [2,3,1,1,4] true
// [3,2,1,0,4] false
bool canJump(int* nums, int numsSize) {
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > max) return false;
        int current = nums[i] + i;  // possible step + offset
        if (current > max) max = current;
        if (max >= numsSize - 1) return true; // if possible bigger then last element
    }

    return false;
}