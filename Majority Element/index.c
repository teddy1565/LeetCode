#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    int n = nums[0];
    int k = numsSize / 2;
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            n = nums[i];
        } else if (count > k) {
            return n;
        }
        if (nums[i] == n) {
            count++;
        } else {
            count--;
        }
    }
    return n;
}