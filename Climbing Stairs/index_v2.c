#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// x = 1
// y = 2
// n = 2, { 2 * x + 0 * y, 0 * x + 1 * y }
// n = 3, { 3 * x + 0 * y, 1 * x + 1 * y }
// n = 45, { 45 * x + 0 * y,  }
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