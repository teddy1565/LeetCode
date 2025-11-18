#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * @brief -10^9 ~ +10^9 numsSize <= 50000
 * 
 * @param nums 
 * @param numsSize 
 * @return int 
 */
int majorityElement(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    int n = nums[0];
    int k = numsSize / 2;
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            n = nums[i];
        } else if (count > k) {
            return n;
        }
        if (nums[i] == n) {
            count++;
        } else {
            count--;
        }
    }
    return n;
}

int main(void) {
    int test_case_01[5] = { 7, 7, 7, 7, 7 };
    int test_case_02[1] = { 1 };
    int test_case_03[3] = { 2, 2, 1 };
    int test_case_04[7] = { 5, 1, 5, 2, 5, 3, 5 };
    int test_case_05[7] = { 1, 2, 3, 4, 4, 4, 4 };
    int test_case_06[7] = { 1, 5, 5, 5, 2, 5, 3 };
    int test_case_07[5] = { -1, -1, 0, -1, 1 };
    int test_case_08[5] = { 1000000000, 1000000000, 5, 1000000000, 7 };
    printf("%d\n", majorityElement(test_case_01, 5));
    printf("%d\n", majorityElement(test_case_02, 1));
    printf("%d\n", majorityElement(test_case_03, 3));
    printf("%d\n", majorityElement(test_case_04, 7));
    printf("%d\n", majorityElement(test_case_05, 7));
    printf("%d\n", majorityElement(test_case_06, 7));
    printf("%d\n", majorityElement(test_case_07, 5));
    printf("%d\n", majorityElement(test_case_08, 5));
    return 0;
}