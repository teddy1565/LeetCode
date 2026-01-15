#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


long long int max(long long int x, long long int y, long long int z) {
    long long int max = x;
    if (y > max) max = y;
    if (z > max) max = z;
    return max;
}

long long maximumProfit(int* prices, int pricesSize, int k) {
    long long int ***dp = (long long int ***) malloc(sizeof(long long int **) * pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        dp[i] = (long long int **) malloc(sizeof(long long int *) * (k + 1));
        for (int j = 0; j <= k; j++) {
            dp[i][j] = (long long int *) malloc(sizeof(long long int) * 3);
            memset(dp[i][j], 0, sizeof(long long int) * 3);
        }
    }


    for (int j = 1; j <= k; j++) {
        dp[0][j][1] = -prices[0];
        dp[0][j][2] = prices[0];
    }
    
    for (int i = 1; i < pricesSize; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = max(
                                dp[i - 1][j][0],
                                dp[i - 1][j][1] + prices[i],
                                dp[i - 1][j][2] - prices[i]
                            );
            dp[i][j][1] = max(
                                dp[i - 1][j][1],
                                dp[i - 1][j - 1][0] - prices[i],
                                LLONG_MIN
                            );
            dp[i][j][2] = max(
                                dp[i - 1][j][2],
                                dp[i - 1][j - 1][0] + prices[i],
                                LLONG_MIN
                            );
        }
    }
    long long int answer = dp[pricesSize - 1][k][0];
    for (int i = 0; i < pricesSize; i++) {
        for (int j = 0; j <= k; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    return answer;
}