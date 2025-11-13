#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int search(int* nums, int numsSize, int target) {
    if (numsSize == 0) {
        return -1;
    } else if (target == nums[0]) {
        return 0;
    }

    int ans = -1;
    int first_num = nums[0];
    if (target > first_num) {
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] > target) {
                break;
            } else if (nums[i] == target) {
                ans = i;
                break;
            }
        }
    } else {
        for (int i = numsSize-1; i >= 0; i--) {
            if (nums[i] < target) {
                break;
            } else if (nums[i] == target) {
                ans = i;
                break;
            }
        }
    }


    return ans;
}