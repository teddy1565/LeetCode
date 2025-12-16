#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int *dp = (int *) malloc(sizeof(int) * n);
    memset(dp, 0, sizeof(int) * n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int c = dp[n - 1];
    free(dp);
    return c;
}