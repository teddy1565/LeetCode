#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    if (target == nums[mid]) {
        return mid;
    }
    

    if (target > nums[min] && target > nums[max]) {
        if (target < nums[mid]) {
            for (int i = mid-1; i >= 0; i--) {

            }
        } else {
            for (int i = mid+1; i < numsSize; i++) {
                
            }
        }
    } else if (target > nums[min] && target < nums[max]) {
        if (target < nums[mid]) {
            for (int i = mid-1; i >= 0; i--) {

            }
        } else {
            for (int i = mid+1; i < numsSize; i++) {

            }
        }
    } else if (target < nums[min] && target > nums[max]) {
        if (target < nums[mid]) {
            for (int i = mid-1; i >= 0; i--) {

            }
        } else {

        }
    } else if (target < nums[min] && target < nums[max]) {
        if (target < nums[mid]) {
        
        } else {

        }
    }
    

    return ans;
}