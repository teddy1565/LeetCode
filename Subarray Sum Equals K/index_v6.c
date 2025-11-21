#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// $$\text{Sum}(\text{Sub}_{i, j}) = \text{PrefixSum}[j] - \text{PrefixSum}[i-1]$$


int subarraySum(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        if (k == nums[0]) {
            return 1;
        }
        return 0;
    }
    int n = 0;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    for (int loop_index = 0; loop_index < numsSize; loop_index++) {
        int m = nums[loop_index] - k;
        if (m == 0) n++;
        for (int i = loop_index-1; i >= 0; i--) {
            if (nums[i] == m) n++;
        }
    }

    return n;
}

int main(void) {
    return 0;
}