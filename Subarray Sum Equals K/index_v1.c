#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// $$\text{Sum}(\text{Sub}_{i, j}) = \text{PrefixSum}[j] - \text{PrefixSum}[i-1]$$
int subarraySum(int* nums, int numsSize, int k) {
    int n = 0;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    for (int i = 0; i < numsSize; i++) {
        int m = nums[i] - k;
        if (m == 0) {
            n++;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (m == nums[j]) {
                n++;
            }
        }
    }

    return n;
}