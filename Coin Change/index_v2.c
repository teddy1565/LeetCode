#include <stdlib.h>


int coinChange(int* coins, int coinsSize, int amount) {

    if (amount == 0) {
        return 0;
    }


    int *dp = (int *) malloc(sizeof(int) * (amount + 1));

    memset(dp, 0, sizeof(int) * (amount + 1));

    for (int i = 1; i <= amount; i++) {
        int min = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] < 0 || dp[i - coins[j]] == -1) {
                continue;
            }
            min = min < (dp[i - coins[j]] + 1) ? min : (dp[i - coins[j]] + 1);
        }
        
        dp[i] = min == INT_MAX ? -1 : min;
    }
    int ans = dp[amount];
    free(dp);
    return ans;

}