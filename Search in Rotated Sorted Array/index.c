#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int search(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return -1;
    } else if (numsSize == 1) {
        if (nums[0] != target) {
            return -1;
        }
        return 0;
    } else if (nums[0] == target) {
        return 0;
    } else if (nums[numsSize-1] == target) {
        return numsSize-1;
    }

    int mid = numsSize / 2;

    for (int i = 0, j = numsSize-1, k = mid; i <= mid && j >= mid; i++, j--) {
        if (target == nums[i]) {
            return i;
        } else if (target == nums[j]) {
            return j;
        } else if (target == nums[k + i]) {
            return k + i;
        } else if (target == nums[k - i]) {
            return k - i;
        }
    }
    

    return -1;
}