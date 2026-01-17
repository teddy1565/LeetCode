#include <stdlib.h>


int coinChange(int* coins, int coinsSize, int amount) {

    if (amount == 0) {
        return 0;
    }


    /**
     * @brief dp[i]
     * 
     * i = 金額
     * 儲存在i金額時候，最小的硬幣數量
     * 
     */
    int *dp = (int *) malloc(sizeof(int) * (amount + 1));

    memset(dp, 0, sizeof(int) * (amount + 1));

    for (int i = 1; i <= amount; i++) {
        /**
         * @brief 宣告一個極大的正整數
         * 
         */
        int min = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            
            /**
             * @brief 如果遇到邊界則continue
             * 
             * 1. amount(i) - coins[j] < 0
             * 2. dp[i - coins[j]] 無法湊出此金額
             */
            if (i - coins[j] < 0 || dp[i - coins[j]] == -1) {
                continue;
            }
            /**
             * @brief 
             * traverse all element，find minimum
             * 
             * if i == coins[j], dp[i - coins[j]] is 0,
             * 
             * so can initial dp[coins[j]] is 1
             * 
             * example: target = 11, coins=[1,2,5]
             * 
             * dp
             * [0, 1, 1, x, x, 1, x, x, x, x, x, x]
             * 
             * basicaly, a number bigger then coins[j], should a coins[j] + n.
             * else before this, it continue, and wirte -1
             */
            min = min < dp[i - coins[j]] + 1 ? min : dp[i - coins[j]] + 1;
        }

        /**
         * @brief 如果min為INT_MAX代表湊不出組合，紀錄為-1，讓dp轉移過程中辨認到時，直接continue
         * 否則寫入數值
         */
        dp[i] = min == INT_MAX ? -1 : min;
    }

    int ans = dp[amount];

    free(dp);

    return ans;

}