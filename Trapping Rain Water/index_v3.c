#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// [1,2,5,5,4,5,6,3]

int trap(int* height, int heightSize) {
    if (heightSize < 3) {
        return 0;
    }
    int left = 0;
    int right = heightSize - 1;
    int sum = 0;
    int left_n = height[0];
    int right_n = height[heightSize - 1];
    while (left < right) {
        if (left_n > right_n) {
            right_n = (right_n >= height[right - 1] ? right_n : height[right - 1]);
            sum += right_n - height[--right];
        } else {
            left_n = (left_n >= height[left + 1] ? left_n : height[left + 1]);
            sum += left_n - height[++left];
        }
    }
    return sum;
}