#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int minimumOperations(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] % 3) != 0) count += 1;
    }
    return count;
}