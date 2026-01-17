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
    unsigned int **dp = (unsigned int **) malloc(sizeof(unsigned int *) * (coinsSize + 1));
    for (int i = 0; i <= coinsSize; i++) {
        dp[i] = (unsigned int *) malloc(sizeof(unsigned int) * (amount + 1));
        memset(dp[i], 0, sizeof(unsigned int) * (amount + 1));
    }

    /**
     * @brief 使用前 0 種硬幣，湊出金額 0 的方法數
     * 
     */
    dp[0][0] = 1;

    for (int i = 1; i <= coinsSize; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= amount; j++) {
            /**
             * @brief 
             * k是指只使用coins[i - 1]這個硬幣進行交換時，能組成的可能性數量
             * 當金額小於coins[i - 1]時候，能組成的組合k為0
             * 
             * 修正：k (也就是 dp[i][j - coin]) 並不代表「只使用這枚硬幣」。
             * 正確理解：k 代表的是**「如果我決定『這次』要用這枚硬幣，那麼剩下的金額 j - coin 有多少種湊法？」
             * 為什麼重要：剩下的金額 j - coin 依然可以使用前 i 種硬幣來湊（包含剛剛用過的那枚）。
             * 所以 k 裡面可能已經包含了前面用過很多次第一種、第二種硬幣的組合，而不僅僅是「只用當前這枚」。
             * 
             * 舉例說明：假設硬幣有 [1, 5]，現在要湊 6。
             * 當我們處理硬幣 5 時：我們決定拿一枚 5。
             * 剩下金額是 1。
             * dp 表格會告訴我們湊出 1 的方法數是 1 (就是拿一枚硬幣 1)。
             * 所以這裡的 k 來源其實是用到了硬幣 1 的歷史紀錄，而不只是硬幣 5。
             */
            unsigned int k = j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0;

            /**
             * @brief 
             * 能組成的總組合數量為，同一個金額j的情況下，上一個硬幣進行交換時的可能數 + 現有的硬幣可能數 進行疊代
             */
            dp[i][j] = dp[i - 1][j] + k;
        }
    }

    int ans = (int) dp[coinsSize][amount];
    for (int i = 0; i <= coinsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}