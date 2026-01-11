#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize) {
    int answer = 0;
    int **dp = (int **) malloc(sizeof(int *) * (pricesSize));
    for (int i = 0; i < pricesSize; i++) {
        dp[i] = (int *) malloc(sizeof(int) * 2);
        memset(dp[i], 0, sizeof(int) * 2);
    }
    dp[0][1] = -prices[0];

    for (int i = 1; i < pricesSize; i++) {
        // 如果前一天的股票今天賣出或繼續持有
        // 今天買入或不持有
        // 決定要不要賣出
        int when_buy = dp[i - 1][1] + prices[i];
        dp[i][0] = when_buy > dp[i - 1][0] ? when_buy : dp[i - 1][0];

        // 如果前一天買入的價格今天賣出，收益大於持有，則選擇賣出，否則繼續持有
        // 今天買入或不持有
        // 決定要不要買入
        int when_sell = dp[i - 1][0] - prices[i];
        dp[i][1] = when_sell > dp[i - 1][1] ? when_sell : dp[i - 1][1];
    }

    
    answer = dp[pricesSize - 1][0];

    for (int i = 0; i < pricesSize; i++) {
        free(dp[i]);
    }

    free(dp);

    return answer;
}