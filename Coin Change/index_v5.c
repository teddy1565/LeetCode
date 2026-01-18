#include <stdlib.h>
#include <limits.h>

int dfs(int *coins, int coinsSize, int amount, int current_amount, int current_coins_nums, int current_coin) {
    unsigned int k = (unsigned int) current_amount + (unsigned int) current_coin;
    if (k > (unsigned int) amount) {
        return INT_MAX;
    } else if (k == (unsigned int) amount) {
        return current_coins_nums + 1;
    }

    int ans = INT_MAX;
    for (int i = 0 ; i < coinsSize; i++) {
        int d = dfs(coins, coinsSize, amount, current_amount + current_coin, current_coins_nums + 1, coins[i]);
        if (d < ans) {
            ans = d;
        }
    }

    return ans;

}

int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < coinsSize; i++) {
        int d = dfs(coins, coinsSize, amount, 0, 0, coins[i]);
        if (d < ans) {
            ans = d;
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    return ans;
}