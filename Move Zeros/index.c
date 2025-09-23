#include "index.h"


//[0,1,0,3,12]
//[4, 2, 4, 0, 0, 3, 0, 5, 1, 0]
void moveZeroes(int* nums, int numsSize) {
    int point = 0;
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[point++] = nums[i];
        }
    }
    for (int i = point; i < numsSize; i++) {
        nums[i] = 0;
    }
}

int main(void) {
    return 0;
}