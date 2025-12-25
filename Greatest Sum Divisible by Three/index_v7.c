#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int maxSumDivThree(int* nums, int numsSize) {
    int dp[3] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        int dp_copy[3] = { 0 };
        memcpy(dp_copy, dp, sizeof(int) * 3);

        for (int j = 0; j < 3; j++) {
            int k = dp_copy[j];
            int m = (dp[(k + nums[i]) % 3]);
            int n = (k + nums[i]);
            dp[(k + nums[i]) % 3] = (m > n) ? m : n;
        }
    }
    return dp[0];
}