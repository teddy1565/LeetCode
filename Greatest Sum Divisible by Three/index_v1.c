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
    int *dp = (int *) malloc(sizeof(int) * (numsSize + 1));
    memset(dp, 0, sizeof(int) * (numsSize + 1));
    int sum = 0;
    int prev = 0;
    // [1,3,5,6,8]
  //[0, 1,4,9,15]
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int n = (nums[i] + prev) % 3;
        dp[i + 1] = nums[i] + dp[i];
        if (n == 0) {
            dp[i + 1] = nums[i] + prev;
            prev = (nums[i] + prev);
        }
    }
    printf("%d\n", dp[numsSize]);
    return 0;
}

int main(void) {

    int test_a[5] = { 3,6,5,1,8 };
    int test_b[5] = { 1,2,3,4,4 };
    int test_c[1] = { 4 };

    return 0;
}