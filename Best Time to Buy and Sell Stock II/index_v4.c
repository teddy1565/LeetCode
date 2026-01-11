#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize) {
    int answer = 0;
    int **dp = (int **) malloc(sizeof(int *) * pricesSize);
    // 儲存交易迭代的最新總獲利，如果新的交易總獲利或大於之前的獲利則更新
    dp[0][0] = 0;

    // 儲存交易迭代的最新成本，如果新的交易買入成本可以更少，則進行買入

    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        // 今天決定我繼續持有還是賣出，因為如果要賣出，必須要計算前一天的買入成本
        dp[i][0] = dp[i - 1][1] + prices[i] > dp[i - 1][0] ? dp[i - 1][1] + prices[i] : dp[i - 1][0];

        // 如果前一天的交易獲利總和，扣掉買入成本，會比之前的買入成本更低，那麼則進行買入
        dp[i][1] = dp[i - 1][0] - prices[i] > dp[i - 1][1] ? dp[i - 1][0] - prices[i] : dp[i - 1][1];
    }

    answer = dp[pricesSize - 1][0];
    
    for (int i = 0; i < pricesSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return answer;
}