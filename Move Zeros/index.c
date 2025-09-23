#include "index.h"



void moveZeroes(int* nums, int numsSize) {
    int n = numsSize - 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            while (nums[n] == 0) n--;
            
            nums[i] = nums[i] ^ nums[n];
            nums[n] = nums[i] ^ nums[n];
            nums[i] = nums[i] ^ nums[n];
        }
    }
}

int main(void) {
    return 0;
}