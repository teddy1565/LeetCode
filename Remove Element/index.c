#include "index.h"

int removeElement(int* nums, int numsSize, int val) {

    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1 && nums[0] == val) {
        return 0;
    }

    int counter = 0;

    for (int i = 0, j = numsSize - 1; i < numsSize && i <= j;) {
        if (nums[j] == val) {
            j--;
            continue;
        }
        if (nums[i] == val) {
            nums[i] = nums[j--];
        }

        counter++;
        i++;
    }

    return counter;
}

int main(void) {
    return 0;
}