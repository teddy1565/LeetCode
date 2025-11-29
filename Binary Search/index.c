#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int search(int* nums, int numsSize, int target) {

    if (numsSize == 0) return -1;
    else if (numsSize == 1 && nums[0] != target) return -1;
    else if (numsSize == 1) return 0;

    int middle = numsSize / 2;
    int max = numsSize - 1;
    int min = 0;
    
    while (min < max) {
        middle = (max + min) / 2;
        if (nums[middle] == target) return middle;
        else if (nums[max] == target) return max;

        if (nums[middle] > target) max = middle;
        else min = middle + 1;
    }

    return -1;
}