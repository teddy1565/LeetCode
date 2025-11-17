#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize) {
    int n[50000] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        n[nums[i]] += 1;
    }
    for (int i = 0; i < 50000; i++) {
        if (n[i] > (numsSize / 2)) {
            return i;
        }
    }
    return 0;
}

int main(void) {
    return 0;
}