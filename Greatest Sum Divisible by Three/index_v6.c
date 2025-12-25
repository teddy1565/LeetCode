#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int maxSumDivThree(int* nums, int numsSize) {
    int dp[3] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        dp[nums[i] % 3] += nums[i];
    }
    int sum = dp[0] + dp[1] + dp[2];
    if (sum % 3 == 0) {
        return sum;
    }
    int a = sum;
    int b = sum;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 3 == 1) {
            a -= nums[i];
        }
        if (a % 3 == 0) {
            break;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 3 == 2) {
            b -= nums[i];
        }
        if (b % 3 == 0) {
            break;
        }
    }
    a = a % 3 == 0 ? a : 0;
    b = b % 3 == 0 ? b : 0;
    if (a > b) {
        return a;
    }
    return b;
}