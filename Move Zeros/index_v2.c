#include "index.h"


//[0,1,0,3,12]
//[4, 2, 4, 0, 0, 3, 0, 5, 1, 0]
void moveZeroes(int* nums, int numsSize) {
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            j = i;
            while (j < numsSize && nums[j] == 0) j++;
            if (j == numsSize) break;
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }
    }
}

int main(void) {
    return 0;
}