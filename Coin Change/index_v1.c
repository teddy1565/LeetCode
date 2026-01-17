#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int coinChange(int* coins, int coinsSize, int amount) {

    if (amount == 0) {
        return 0;
    }

    qsort(coins, coinsSize, sizeof(int), compare);

    int **dp = (int **) malloc(sizeof(int *) * (amount + 1));
    for (int i = 0; i <= amount; i++) {
        dp[i] = (int *) malloc(sizeof(int) * 2);
        memset(dp[i], 0, sizeof(int) * 2);
    }

    for (int i = coinsSize - 1; i >= 0; i--) {
        for (int j = coins[i]; j <= amount; j++) {
            int k = (j - dp[j][1]) / coins[i];
            dp[j][0] += k;
            dp[j][1] += (coins[i] * k);
        }
    }

    if (dp[amount][1] != amount) {
        return -1;
    }
    
    return dp[amount][0];
}