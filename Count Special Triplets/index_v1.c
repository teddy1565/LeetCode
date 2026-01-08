#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// A special triplet is defined as a triplet of indices (i, j, k) such that:

// 0 <= i < j < k < n, where n = nums.length
// nums[i] == nums[j] * 2
// nums[k] == nums[j] * 2
// Return the total number of special triplets in the array.

// Since the answer may be large, return it modulo 109 + 7.


// Constraints:

// 3 <= n == nums.length <= 105
// 0 <= nums[i] <= 105

int specialTriplets(int* nums, int numsSize) {
    int n = numsSize;
    int count = 0;
    for (int k = 2; k < n; k++) {
        for (int j = 1; j < k; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[i] == nums[j] * 2 && nums[k] == nums[j] * 2) {
                    count += 1;
                }
            }
        }
    }



    if (count > 1000000000) {
        count %= 1000000000;
        count += 7;
    }
    return count;
}

int main(void) {
    srand(time(NULL));

    int min = 0;
    int max = 100000;
    int test_case_size = 10000;
    int *test_case = (int *) malloc(sizeof(int) * test_case_size);

    for (int i = 0; i < test_case_size; i++) {
        test_case[i] = i % (max - min + 1) + min;;
    }
    // printf("test_case: ");
    // for (int i = 0; i < (test_case_size % 50) + 50; i++) {
    //     printf("%d, ", test_case[i]);
    // }
    // printf("\n");
    int answer = specialTriplets(test_case, test_case_size);
    printf("answer: %d\n", answer);
    return 0;
}