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

    if (nums[mid] == target) {
        return mid;
    }


    int ans = -1;
    printf("min: %d | max: %d | mid: %d | min_num: %d\n", min, max, mid, mid_num);
    printf("mid | min | max | mid_num\n");
    for (int i = 0; i < numsSize; i++) {
        if (mid_num >= nums[max]) {
            if (mid_num >= nums[mid]) {
                mid = (mid + max) / 2;
            } else {
                mid = (mid + min) / 2;
            }
        } else if (mid_num < nums[min]) {
            if (mid_num >= nums[mid]) {
                mid = (mid + max) / 2;
            } else {
                mid = (mid + min) / 2;
            }
        }
        if (target == nums[mid]) {
            return mid;
        }
        printf("%d %d %d %d\n", mid, min, max, mid_num);
    }
    
    return ans;
}