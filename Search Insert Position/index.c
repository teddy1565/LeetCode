#include "index.h"

int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;
    for (; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
}

int main(void) {
    return 0;
}