#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_splits(int* nums, int numsSize, long long int max_sum) {
    int count = 1;
    long long int current_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (current_sum + nums[i] <= max_sum) {
            current_sum += nums[i];
        } else {
            count++;
            current_sum = nums[i];
        }
    }
    return count;
}

int splitArray(int* nums, int numsSize, int k) {
    int low = 0;
    int high = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) {
            low = nums[i];
        }
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (count_splits(nums, numsSize, mid) <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;

}

int main(void) {
    return 0;
}