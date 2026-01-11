#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize) {
    int answer = 0;
    int **dp = (int **) malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        dp[i] = (int *) malloc(sizeof(int) * pricesSize);
        memset(dp[i], 0, sizeof(int) * pricesSize);
    }
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i; j < pricesSize; j++) {
            dp[i][j] = prices[j] - prices[i];
        }
    }

    for (int i = 0, limit = 0; i < pricesSize; i++) {
        int max = 0;
        
        for (int j = limit; j < pricesSize; j++) {
            if (dp[j][i] > max) {
                max = dp[j][i];
                limit = j + 1;
            }
        }

        answer += max;
    }

    for (int i = 0; i < pricesSize; i++) {
        for (int j = 0; j < pricesSize; j++) {


            printf("%d, ", dp[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < pricesSize; i++) {
        free(dp[i]);
    }

    free(dp);

    return answer;
}