#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// [2,3,1,1,4] true
// [3,2,1,0,4] false
bool canJump(int* nums, int numsSize) {
    bool ans = false;
    int *dp = (int *) malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);

    dp[0] = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        for (int j = i - 1; j < dp[i - 1] && j < numsSize; j++) {
            int n = nums[j] + j;
            dp[i] = n > dp[i - 1] ? n : dp[i - 1];
        }
    }
    if (dp[numsSize - 1] >= (numsSize - 1)) {
        ans = true;
    }
    
    free(dp);
    return ans;
}