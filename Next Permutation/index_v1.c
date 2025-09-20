/**
 * @file index_v1.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

//arr: , , 

/**
 * @brief 
 * [1,2,3], [1,3,2]
 * [2,1,3], [2,3,1]
 * [3,1,2], [3,2,1]
 */

/**
 * @brief 
 * [1,5,5]
 * [5,1,5]
 * [5,5,1]
 */

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * @brief 
 * 
 * @param nums 
 * @param numsSize 
 */
void nextPermutation(int* nums, int numsSize) {

    if (numsSize == 1 || numsSize == 0) {
        return;
    } else if (numsSize == 2) {
        nums[0] = nums[0] ^ nums[1];
        nums[1] = nums[0] ^ nums[1];
        nums[0] = nums[0] ^ nums[1];
        return;
    }

    bool is_changed = false;
    bool need_resort = false;

    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            int head_n_index = i;
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] > nums[i - 1] && nums[j] < nums[head_n_index]) {
                    head_n_index = j;
                }
            }

            nums[head_n_index] = nums[head_n_index] ^ nums[i - 1];
            nums[i - 1] = nums[head_n_index] ^ nums[i - 1];
            nums[head_n_index] = nums[head_n_index] ^ nums[i - 1];
            is_changed = true;
            if (need_resort == true) {
                qsort(&nums[i], numsSize - i, sizeof(int), &compare_cb);
            }
            return;
        } else if (nums[i] < nums[i - 1]) {
            need_resort = true;
        }
    }

    if (is_changed == false) {
        int start = 0;
        int end = numsSize - 1;
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        return;
    }

    return;
}

int main(void) {
    int *list = (int *) malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        list[i] = (10 - i);
    }

    qsort(&list[5], 5, sizeof(int), &compare_cb);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", list[i]);
    }
    return 0;
}