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
        int sum = 0;
        for (int i = 0; i < window_size; i++) {
            sum += diff[i];
        }
        if (sum == window_size) {
            ans += 1;
        }
        for (int i = window_size; i < pricesSize; i++) {
            sum += diff[i];
            sum -= diff[i - window_size];
            if (sum == window_size) {
                ans += 1;
            }
        }
    }

    return ans;
}