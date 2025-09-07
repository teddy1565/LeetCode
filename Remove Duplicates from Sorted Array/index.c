#include "index.h"

int removeDuplicates(int* nums, int numsSize) {

    int k = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[(k - 1)]) {
            nums[(++k) - 1] = nums[i];
        }
    }

    return k;
}

int main(void) {
    return 0;
}