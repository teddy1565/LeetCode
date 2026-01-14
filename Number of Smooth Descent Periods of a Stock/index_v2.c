#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long getDescentPeriods(int* prices, int pricesSize) {
    long long int ans = pricesSize; // minimum have pricesSize;
    int *diff = (int *) malloc(sizeof(int) * pricesSize);
    diff[0] = 1;

    for (int i = 1; i < pricesSize; i++) {
        diff[i] = prices[i - 1] - prices[i];
    }
    for (int window_size = 2; window_size <= pricesSize; window_size++) {
        int base[window_size];
        for (int i = 0; i < window_size; i++) {
            base[i] = 1;
        }
        for (int i = 0; i <= pricesSize - window_size; i++) {
            int cmp_result = memcmp(base, &diff[i], sizeof(int) * window_size);
            if (cmp_result == 0) {
                ans += 1;
            }
        }
    }

    return ans;
}