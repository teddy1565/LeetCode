#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

bool check(int* nums, int numsSize) {
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= min) {
            min = nums[i];
            min_index = i;
        }
    }
    int *offset_list = (int *) malloc(sizeof(int) * numsSize);


    int offset_index = 0;
    for (int i = min_index; i < numsSize; i++) {
        offset_list[offset_index++] = nums[i];
    }

    for (int i = 0; i < min_index; i++) {
        offset_list[offset_index++] = nums[i];
    }

    min = offset_list[0];
    for (int i = 0; i < numsSize; i++) {
        if (offset_list[i] < min) {
            return false;
        }
        min = offset_list[i];
    }

    free(offset_list);
    return true;
}