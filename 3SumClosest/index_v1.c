/**
 * @file index_v1.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * 這個解，原本是打算透過三個單一迴圈，嘗試找出最佳組合，但實際上找到的只是局部最佳解，而不是全局最佳解
 * 
 */

#include "index.h"

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {

    qsort(nums, numsSize, sizeof(int), &compare_cb);
    
    int answer[3] = { -1, -1, -1 };
    int answer_index = 0;
    int min_diff_index = 0;
    
    loop_body:

    min_diff_index = 0;


    for (int i = 0; i < numsSize; i++) {
        if (i == answer[0] || i == answer[1] || i == answer[2]) {
            if (min_diff_index == i) {
                min_diff_index++;
            }
            continue;
        }
        
        if (abs(target - nums[i]) <= abs(target - nums[min_diff_index])) {
            min_diff_index = i;
        }
    }

    answer[answer_index++] = min_diff_index;

    if (answer_index < 3) {
        goto loop_body;
    }

    printf("%d %d %d | %d %d %d\n", answer[0], answer[1], answer[2], nums[answer[0]], nums[answer[1]], nums[answer[2]]);

    return nums[answer[0]] + nums[answer[1]] + nums[answer[2]];
}

int main(void) {

    threeSumClosest(test_case_01, 4, 1);
    threeSumClosest(test_case_02, 3, 1);
    threeSumClosest(test_case_03, 3, 0);
    threeSumClosest(test_case_04, 9, 1);
    threeSumClosest(test_case_05, 9, -2);
    return 0;
}