#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int change(int amount, int* coins, int coinsSize) {
    unsigned int *dp = (unsigned int *) malloc(sizeof(unsigned int) * (amount + 1));
    memset(dp, 0, sizeof(unsigned int) * (amount + 1));
    dp[0] = 1;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    int ans = (int) dp[amount];
    free(dp);
    return ans;
}