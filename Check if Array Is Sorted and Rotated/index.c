#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

bool check(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > nums[(i + 1) % numsSize]) {
            count += 1; // 由於ring結構，因此頭尾相連時，會count 1次，但除此之外代表不合格
        }
    }
    return count <= 1;
}