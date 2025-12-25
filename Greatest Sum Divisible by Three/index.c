#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int maxSumDivThree(int* nums, int numsSize) {
    int dp[3] = {0};
    for (int i = 0; i < numsSize; i++) {
        int dp_copy[3] = { 0 };
        memcpy(dp_copy, dp, sizeof(int) * 3);
        for (int j = 0; j < 3; j++) {
            int k = dp_copy[j];
            int m = k + nums[i];
            int n = dp[m % 3];  // 取計算的m的餘數，代表這個餘數的最大值
            dp[m % 3] = n > m ? n : m;
        }
    }

    return dp[0];
}