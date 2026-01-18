#include <stdlib.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int ans = 0;
    int *dp = (int *) malloc(sizeof(int) * (amount + 1));
    memset(dp, 0, sizeof(int) * (amount + 1));
    // DP, bottom-up
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        int min = INT_MAX; // find each possible the minimum coins

        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] < 0) {
                /**
                 * Edge Case
                 * 
                 */
                continue;
            } else if (dp[i - coins[j]] == -1) {
                /**
                 * It means the possible out of the range
                 * 
                 */
                continue;
            }
            // dp[i - coins[j]] + 1 means that possible latest + 1 will == target
            min = (dp[i - coins[j]] + 1) < min ? (dp[i - coins[j]] + 1) : min;
        }
        /**
         * @brief if not found any vaild possible, record -1
         * 
         */
        dp[i] = min == INT_MAX ? -1 : min;
    }

    ans = dp[amount];
    free(dp);
    return ans;
}