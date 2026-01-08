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
    int right_map[100001] = { 0 };
    int left_map[100001] = { 0 };
    int answer = 0;
    const int MOD_V = 1000000007;
    for (int i = 0; i < numsSize; i++) {
        right_map[nums[i]] += 1;
    }
    for (int i = 0; i < numsSize; i++) {
        right_map[nums[i]] -= 1;

        int target_value = nums[i] * 2;
        
        int left_value = left_map[target_value];
        int right_value = right_map[target_value];
        answer = (answer + ((left_value * right_value) % MOD_V) % MOD_V);
        left_map[nums[i]] += 1;
    }

    return answer;
}
