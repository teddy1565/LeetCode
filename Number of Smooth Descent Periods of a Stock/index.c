#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long getDescentPeriods(int* prices, int pricesSize) {
    long long int ans = 0;
    for (int start_index = 0, end_index = 0; start_index < pricesSize ; start_index = end_index) {
        end_index = start_index + 1;
        while (end_index < pricesSize && prices[end_index - 1] - prices[end_index] == 1) {
            end_index += 1;
        }
        int sequency_length = end_index - start_index;
        ans += sequency_length * (sequency_length + 1LL) / 2;
    }
    return ans;
}