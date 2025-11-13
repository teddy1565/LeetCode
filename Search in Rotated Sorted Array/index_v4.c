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

    int min = 0;
    int max = numsSize - 1;
    int mid = numsSize / 2;
    int mid_num = (nums[min] + nums[max]) / 2;
    int ans = -1;
    // if (target == nums[mid]) {
    //     return mid;
    // }
    
    for (int i = 0; i < numsSize; i++) {
        if (mid >= numsSize) {
            break;
        }
        if (target == nums[mid]) {
            return mid;
        }
        int mid_left = (mid + min) / 2;
        int mid_right = (mid + max) / 2;
        if (nums[mid_left] == target) {
            return mid_left;
        } else if (nums[mid_right] == target) {
            return mid_right;
        }

        // if (nums[mid_right] < nums[mid_left]) {
        //     mid_right = mid_right ^ mid_left;
        //     mid_left = mid_right ^ mid_left;
        //     mid_right = mid_right ^ mid_left;
        // }

        if (target > nums[mid_right] && target < nums[mid_left]) {
            mid = (mid_right + max) / 2;
        } else if (target < nums[mid_right] && target > nums[mid_left]) {
            mid = (mid_left + min) / 2;
        } else {
            mid = (mid / 2 + mid_right + mid_left) / 2;
        }

        printf("L: %d, R: %d\n", mid_left, mid_right);
    }
    

    return ans;
}