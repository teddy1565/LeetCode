#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans[2] = { -1, -1 };
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *(returnSize) = 2;
    ans[0] = -1;
    ans[1] = -1;
    if (numsSize == 0) {
        return ans;
    } else if (numsSize == 1) {
        if (nums[0] == target) {
            ans[0] = 0;
            ans[1] = 0;
        }
        return ans;
    } else if (numsSize == 2) {
        if (nums[0] == target && nums[1] == target) {
            ans[0] = 0;
            ans[1] = 1;
        } else if (nums[0] == target && nums[1] != target) {
            ans[0] = 0;
            ans[1] = 0;
        } else if (nums[0] != target && nums[1] == target) {
            ans[0] = 1;
            ans[1] = 1;
        }

        return ans;
    }

    int min = 0;
    int max = numsSize - 1;
    int mid = (min + max) / 2;
    for (int i = 0; i < numsSize && mid < numsSize; i++) {
        if (target == nums[mid]) {
            ans[0] = mid;
            ans[1] = mid;
            for (int j = 0; mid - j >= 0; j++) {
                if (nums[mid - j] == target) {
                    ans[0] = mid-j;
                }
            }
            for (int j = 0; mid + j < numsSize; j++) {
                if (nums[mid + j] == target) {
                    ans[1] = mid+j;
                }
            }
            break;
        } else if (target > nums[mid]) {
            min = mid;
            mid = ((min + max) / 2) + 1;
        } else if (target < nums[mid]) {
            max = mid;
            mid = (min + max) / 2;
        }
    }
    return ans;
}