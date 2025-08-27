/**
 * @file index_v2.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * 這個解，原本是意識到，經過排序的nums，左邊的組合偏向負數，右邊的組合偏向正數
 * 突然腦抽，想說，那是否有可能經過連續查找，比對鄰近的組合，找出最優解，但仍然是局部最佳解
 * 
 * 但給我一個靈感，既然是經過排序後的局部最佳解，如果重複多個這樣的步驟，是否可以找到全局最佳解組合?
 * 
 * 直覺上效能應該不好看，但感覺蠻有趣的
 *  -5  -5  -4  0   0   3   3   4   5   target = -2
 * [n1, n2, n3, n4, n5, n6, n7, n8, n9]
 * [n1, n2, n3]                             -14
 *     [n2, n3, n4]                         -9
 *         [n3, n4, n5]                     -4
 *             [n4, n5, n6]                 3
 *                 [n5, n6, n7]             6
 *                     [n6, n7, n8]         10
 *                         [n7, n8, n9]     15
 */
#include "index.h"

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {

    qsort(nums, numsSize, sizeof(int), &compare_cb);
    
    int answer[3] = { -1, -1, -1 };
    int answer_index = 0;
    int min_diff_sum = nums[0] + nums[1] + nums[2];

    for (int i = 1; i < numsSize - 2; i++) {
        int min_diff_n = nums[i] + nums[i + 1] + nums[i + 2];
        if (abs(target - min_diff_n) < abs(target - min_diff_sum)) {
            min_diff_sum = min_diff_n;
        }
    }

    printf("%d\n", min_diff_sum);
   

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