#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize) {
    int answer = 0;
    int **dp = (int **) malloc(sizeof(int *) * pricesSize);

    for (int i = 0; i < pricesSize; i++) {
        dp[i] = (int *) malloc(sizeof(int) * 2);
    }

    // 儲存交易迭代的最新總獲利，如果新的交易總獲利或大於之前的獲利則更新
    // 股票的收益
    dp[0][0] = 0;

    // 儲存交易迭代的最新成本，如果新的交易買入成本可以更少，則進行買入
    // 手上剩餘的資金
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        // 選擇繼續休息還是選擇脫手賣出，如果選擇賣出，則是昨天的餘額加上今日的收益
        // 獲利了結或繼續休息
        dp[i][0] = dp[i - 1][1] + prices[i] > dp[i - 1][0] ? dp[i - 1][1] + prices[i] : dp[i - 1][0];

        // 選擇繼續持有股票還是進場買入，如果選擇買入就會消耗前一天的收益
        // 繼續持有或進場買入
        dp[i][1] = dp[i - 1][0] - prices[i] > dp[i - 1][1] ? dp[i - 1][0] - prices[i] : dp[i - 1][1];
    }

    answer = dp[pricesSize - 1][0];
    
    for (int i = 0; i < pricesSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return answer;
}