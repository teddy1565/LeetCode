/**
 * @file index_v1.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


//[0,1,0,3,12]
//[4, 2, 4, 0, 0, 3, 0, 5, 1, 0]
void moveZeroes(int* nums, int numsSize) {
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            j = i;
            while (j < numsSize && nums[j] == 0) j++;
            if (j == numsSize) break;
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
}

int main(void) {
    return 0;
}