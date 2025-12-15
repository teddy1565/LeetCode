#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    bool hash_list[2000000000] = { false };
    for (int i = 0; i < numsSize; i++) {
        if (hash_list[nums[i] + 1000000000] == true) {
            return false;
        } else {
            hash_list[nums[i] + 1000000000] = true;
        }
    }
    return true;
}

int main(void) {
    return 0;
}