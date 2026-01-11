#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize) {
    int answer = 0;
    int **dp = (int **) malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        dp[i] = (int *) malloc(sizeof(int) * 2);
    }
    // 如果我今天要賣掉，代表我昨天要有買
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < pricesSize; i++) {
        // 我今天如果賣掉的話，收益會不會大於我繼續持有
        // 儲存我今天不持有的收益最大化，更新賣出收益
        dp[i][0] = dp[i - 1][1] + prices[i] > dp[i - 1][0] ? dp[i - 1][1] + prices[i] : dp[i - 1][0];

        // 如果我今天買入的收益
        // 儲存我今天持有的收益最大化，對於dp[i][0]而言更新買入價格
        dp[i][1] = dp[i - 1][0] - prices[i] > dp[i - 1][1] ? dp[i - 1][0] - prices[i] : dp[i - 1][1];

    }

    answer = dp[pricesSize - 1][0];

    for (int i = 0; i < pricesSize; i++) {
        free(dp[i]);
    }

    free(dp);

    return answer;
}