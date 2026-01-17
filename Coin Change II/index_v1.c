#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int change(int amount, int* coins, int coinsSize) {

    /**
     * @brief dp[i][j]
     * i: 使用前i種硬幣
     * j: 金額
     * 
     * 使用前i種硬幣兌換j金額有多少種組合
     */
    int **dp = (int **) malloc(sizeof(int *) * (coinsSize + 1));
    for (int i = 0; i <= coinsSize; i++) {
        dp[i] = (int *) malloc(sizeof(int) * (amount + 1));
        memset(dp[i], 0, sizeof(int) * (amount + 1));
    }

    dp[0][0] = 1;

    for (int i = 1; i <= coinsSize; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= amount; j++) {
            /**
             * @brief 
             * k是指只使用coins[i - 1]這個硬幣進行交換時，能組成的可能性數量
             * 當金額小於coins[i - 1]時候，能組成的組合k為0
             */
            int k = j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0;

            /**
             * @brief 
             * 能組成的總組合數量為，同一個金額j的情況下，上一個硬幣進行交換時的可能數 + 現有的硬幣可能數 進行疊代
             */
            dp[i][j] = dp[i - 1][j] + k;
        }
    }

    int ans = dp[coinsSize][amount];
    for (int i = 0; i <= coinsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}