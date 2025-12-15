#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_splits(int *nums, int numsSize, int max_sum) {
    int count = 1;
    int current_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (current_sum + nums[i] <= max_sum) {
            current_sum += nums[i];
        } else {
            current_sum = nums[i];
            count += 1;
        }
    }

    return count;
}

int splitArray(int* nums, int numsSize, int k) {
    
    /**
     * 先找出上下界範圍，如果k = 1那麼high則為所有數字的加總
     * 如果k = numsSize那麼low則為最大的數字
     */

    int low = 0;
    int high = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) {
            low = nums[i];
        }
        high += nums[i];
    }
    
    int answer = high;
    
    // ===========================================

    /**
     * 使用二分法尋找目標
     * 這麼目標需要符合的條件是
     * 分組後的splits數量 要小於或等於K 那麼這個mid則可能是潛在答案
     */
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (count_splits(nums, numsSize, mid) <= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}