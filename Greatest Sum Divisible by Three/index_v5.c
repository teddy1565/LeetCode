#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxSumDivThree(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ans[5] = { 0 };

    int three_sum = 0;
    int not_three_sum = 0;
    int left_max_sum = 0;
    int right_max_sum = 0;
    int left_target_sum = 0;
    int right_target_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 3 == 0) {
            three_sum += nums[i];
            nums[i] = 0;
        }
    }
    
    for (int i = 0; i < numsSize; i++) {
        not_three_sum += nums[i];
    }
    left_max_sum = not_three_sum;
    right_max_sum = not_three_sum;
    left_target_sum = not_three_sum;
    right_target_sum = not_three_sum;
    int target = not_three_sum % 3;
    if (target == 0) {
        return three_sum + not_three_sum;
    }

    for (int i = 0; i < numsSize; i++) {
        if (left_max_sum % 3 != 0) {
            left_max_sum -= nums[i];
        } else {
            break;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 3 == target) {
            left_target_sum -= nums[i];
            break;
        }
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        if (right_max_sum % 3 != 0) {
            right_max_sum -= nums[i];
        } else {
            break;
        }
    }
    
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] % 3 == target) {
            right_target_sum -= nums[i];
            break;
        }
    }
    
    ans[0] = (((three_sum + left_max_sum) % 3) == 0) ? (three_sum + left_max_sum) : 0;
    ans[1] = (((three_sum + left_target_sum) % 3) == 0) ? (three_sum + left_target_sum) : 0;
    ans[2] = (((three_sum + right_max_sum) % 3) == 0) ? (three_sum + right_max_sum) : 0;
    ans[3] = (((three_sum + right_target_sum) % 3) == 0) ? (three_sum + right_target_sum) : 0;
    ans[4] = three_sum;
    int answer = 0;
    for (int i = 0; i < 5; i++) {
        if (ans[i] > answer) {
            answer = ans[i];
        }
    }
    
    return answer;
}