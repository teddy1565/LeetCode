#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
/**
 * @brief 
 * 
 * @param nums 
 * @param numsSize 
 * @return int 
 */
int maxSumDivThree(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int *dp = (int *) malloc(sizeof(int) * (numsSize));
    memset(dp, 0, sizeof(int) * (numsSize));
    // [1, 3, 5, 6, 8]
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        dp[i] = nums[i] % 3;
    }
    int target = sum % 3;
    if (target == 0) {
        free(dp);
        return sum;
    } else if (target == 1) {
        for (int i = 0; i < numsSize; i++) {
            if (dp[i] == 1) {
                free(dp);
                return sum - nums[i];
            }
        }
        sum = 0;
        for (int i = 0; i < numsSize; i++) {
            if (dp[i] == 0) {
                sum += nums[i];
            }
        }
    } else {
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < numsSize; i++) {
            if (dp[i] == 2) {
                a = nums[i];
                break;
            }
        }
        for (int i = 0; i < numsSize && c < 2; i++) {
            if (dp[i] == 1) {
                b += nums[i];
                c += 1;
            }
        }
        if (a != 0 && a < b || a != 0 && c != 2) {
            free(dp);
            return sum - a;
        } else if (b != 0 && c == 2 && b < a) {
            free(dp);
            return sum - b;
        }
        sum = 0;
        for (int i = 0; i < numsSize; i++) {
            if (dp[i] == 0) {
                sum += nums[i];
            }
        }
    }
    free(dp);
    return sum;
}

int main(void) {

    int test_a[5] = { 3,6,5,1,8 };
    int test_b[5] = { 1,2,3,4,4 };
    int test_c[1] = { 4 };

    return 0;
}