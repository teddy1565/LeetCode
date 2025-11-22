#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// $$\text{Sum}(\text{Sub}_{i, j}) = \text{PrefixSum}[j] - \text{PrefixSum}[i-1]$$

#define LENG 10000000
#define ARRLENG 20000000


int subarraySum(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        if (k == nums[0]) {
            return 1;
        }
        return 0;
    }

    int hash_table[20000000] = { 0 };
    hash_table[LENG] = 1;

    int n = 0;
    for (int i = 0, sum = 0; i < numsSize; i++) {
        sum += nums[i];
        n += hash_table[sum - k + LENG];
        hash_table[sum + LENG]++;
    }

    return n;
}