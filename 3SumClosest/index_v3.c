/**
 * @file index_v3.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 * 我的想法是，我發現排序過後的陣列，我們可以把負數加總，正數加總
 * 分為兩個方向
 * 
 * target再找n1時，可以根據target減去負數總數或正數總數，確定第一次查詢的方向
 * 然後找n2時也同樣的作法，最後如果等於0而且nums中也有0直接補0即可，沒有的話，就找一個差異最小數
 * 
 * 修正一下說明
 * 
 * 我們將正數視為正量
 * 將負數視為反量
 * 
 * 如果用target減去總量的差，代表target與總量的差距，得到的結果，越小更近，也就代表target本身在哪個方向
 * 如果用target加上總量的差，代表總量，加上target之後，如果得到的結果縮小，代表target的反向解，在這個群裡面，因為target的量與這個群的量抵銷
 * 因為
 * n ≈ a + b + c
 * 0 ≈ n - (a + b + c)
 * 
 * 
 * 
 */
#include "index.h"

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


/**
 * @brief 
 * @todo 記得去重
 * 
 * @param nums 
 * @param numsSize 
 * @param target 
 * @return int 
 */
int threeSumClosest(int* nums, int numsSize, int target) {

    qsort(nums, numsSize, sizeof(int), &compare_cb);

    printf("[ ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("]\n\n");
    
    int answer[3] = { -1, -1, -1 };

    int answer_sum = 0;
    int answer_index = 0;
    
    int nagitave_sum = 0;
    int positive_sum = 0;
    
    int direction = target;
    int direction_base = target;
    int base_reference = target;
    int base_reference_index = -1;
    int min_n = (target + nums[numsSize-1]);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            nagitave_sum += nums[i];
        } else {
            positive_sum += nums[i];
        }
    }

    search_main:

    /**
     * @brief 如果加上正總量 大於 負總量相加組合
     * 
     */
    if (abs(direction + positive_sum) < abs(direction + nagitave_sum)) {
        for (int i = numsSize - 1; i >= 0 && nums[i] > 0; i--) {
            if (i == answer[0] || i == answer[1] || i == answer[2]) {
                continue;
            }
            int n = (direction_base + nums[i]);
            if (abs(target - n) < abs(target - min_n)) {
                base_reference = nums[i];
                base_reference_index = i;
                min_n = n;
            }
        }
    } else {
        for (int i = 0; i < numsSize && nums[i] < 0; i++) {
            if (i == answer[0] || i == answer[1] || i == answer[2]) {
                continue;
            }
            int n = (direction_base + nums[i]);
            if (abs(target - n) < abs(target - min_n)) {
                base_reference = nums[i];
                base_reference_index = i;
                min_n = n;
            }
        }
    }
    // printf("%d %d\n", base_reference, min_n);
    direction_base = base_reference;
    direction = min_n;
    answer_sum += base_reference;
    answer[answer_index] = base_reference_index;
    
    if (answer[answer_index] == -1) {
        answer[answer_index] = answer[answer_index >> 1] + 1;
    }
    
    answer_index++;
    if (answer_index == 2) {
        goto end_func;
    }

    goto search_main;

    end_func:

    

    
    for (int i = 0, K = abs(answer_sum + nums[0]) - target; i < numsSize; i++) {
        if (abs(answer_sum + nums[i]) - target < K) {
            K = abs(answer_sum + nums[i]);
            answer[answer_index] = i;
        }
    }

    if (answer[answer_index] == -1) {
        answer[answer_index] = answer[answer_index >> 1] + 1;
    }

    printf("%d %d %d | %d %d %d\n------------\n\n", nums[answer[0]], nums[answer[1]], nums[answer[2]], answer[0], answer[1], answer[2]);
    

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