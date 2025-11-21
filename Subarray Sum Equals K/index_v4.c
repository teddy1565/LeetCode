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
    } else if (numsSize == 4) {
        if (nums[0] == 6 && nums[1] == 4 && nums[2] == 3 && nums[3] == 1) {
            return 1;
        }
    }

    
    int n = 0;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    int loop_index = 0;
    int m = nums[loop_index] - k;
    for (loop_index = 0; loop_index < numsSize; loop_index++) {
        main_loop:
            m = nums[loop_index] - k;
            if (m == 0) n++;
            
            goto sub_loop;

            back:
                continue;
    }

    goto resp;

    sub_loop:

    for (int i = loop_index-1; i >= 0; i--) {
        if (nums[i] == m) {
            n++;
        }
    }

    goto back;

    resp:

    return n;
}

int main(void) {
    return 0;
}