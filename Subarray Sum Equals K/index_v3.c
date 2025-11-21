#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// $$\text{Sum}(\text{Sub}_{i, j}) = \text{PrefixSum}[j] - \text{PrefixSum}[i-1]$$

#define LENG 10000000
#define ARRLENG 20000000
int hash_table[20000000] = { 0 };

int subarraySum(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        if (k == nums[0]) {
            return 1;
        }
        return 0;
    }

    memset(hash_table, 0, sizeof(int) * ARRLENG);

    int n = 0;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
        int c = nums[i];

        if (c < 0) {
            c = -c + LENG;
        }
        if (c != 0) {
            hash_table[c] += 1;
        }
    }
    if (nums[0] < 0) {
        hash_table[(-nums[0])+LENG] += 1;
    } else {
        hash_table[nums[0]] += 1;
    }

    for (int i = 0; i < numsSize; i++) {
        int c = nums[i];

        if (c < 0) {
            c = -c + LENG;
        }
        printf("n: %d | h: %d \n", nums[i], hash_table[c]);
    }


    for (int i = 0; i < numsSize; i++) {
        int m = nums[i] - k;
        if (m < 0) {
            m = -m + LENG;
        }
        if (m == 0) {
            n++;
        }
        n += hash_table[m];
    }

    return n;
}