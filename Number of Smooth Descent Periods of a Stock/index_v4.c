#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long getDescentPeriods(int* prices, int pricesSize) {
    long long int ans = 0;
    
    for (int start_index = 0, end_index = 0; start_index < pricesSize; start_index = end_index) {
        end_index = start_index + 1;
        while (end_index < pricesSize && prices[end_index - 1] - prices[end_index] == 1) {
            end_index += 1;
        }

        int sequence_length = end_index - start_index;

        // Add all possible subarrays in this descent sequence
        // For a sequence of length k, there are k*(k+1)/2 subarrays
        ans += (1LL + sequence_length) * sequence_length / 2;
    }
    return ans;
}