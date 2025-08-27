/**
 * @file index.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-27
 * 
 * @copyright Copyright (c) 2025
 * 
 * maybe need find the biggest weight number to small number
 * 
 */
#include "index.h"

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * @brief 
 * 
 * @param nums 
 * @param numsSize 
 * @param target 
 * @return int 
 * 
 * n ≈ a + b + c
 * n = a + b + c
 * 
 * a = n - (b + c)
 */
int threeSumClosest(int* nums, int numsSize, int target) {
    
    if (numsSize == 3) {
        return nums[0] + nums[1] + nums[2];
    }

    qsort(nums, numsSize, sizeof(int), &compare_cb);

    int answer_bias = abs(target - (nums[0] + nums[1] + nums[2]));
    int answer = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize-2; i++) {
        for (int left = i + 1, right = numsSize - 1; left < right;) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return sum;
            }
            if (sum > target) {
                right--;
            } else {
                left++;
            }
            int bias = abs(target - sum);
            if (bias < answer_bias) {
                answer_bias = bias;
                answer = sum;
            }
        }
    }
    
    return answer;
   
}

int main(void) {

    int answer = 0;

    answer = threeSumClosest(test_case_01, 4, 1);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_02, 3, 1);
    printf("answer: %d\n\n", answer);
    
    answer = threeSumClosest(test_case_03, 3, 0);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_04, 9, 1);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_05, 9, -2);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_06, 4, 100);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_07, 10, -14);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_08, 4, 16);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_09, 6, 15);
    printf("answer: %d\n\n", answer);

    answer = threeSumClosest(test_case_10, 13, 78);
    printf("answer: %d\n\n", answer);

    return 0;
}