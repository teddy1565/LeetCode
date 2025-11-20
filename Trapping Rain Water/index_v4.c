#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// [1,2,5,5,4,5,6,3]

int trap(int* height, int heightSize) {
    if (heightSize < 3) {
        return 0;
    }

    int left_index = 0;
    int right_index = heightSize - 1;
    int sum = 0;
    int left_barrier_value = height[0];
    int right_barrier_value = height[heightSize - 1];


    while (left_index < right_index) {
        if (height[left_index] < height[right_index]) {
            if (height[left_index + 1] > left_barrier_value) {
                left_barrier_value = height[left_index + 1];
            }

            left_index++;
            sum = sum + (left_barrier_value - height[left_index]);
        } else {
            if (height[right_index - 1] > right_barrier_value) {
                right_barrier_value = height[right_index - 1];
            }

            right_index--;
            sum = sum + (right_barrier_value - height[right_index]);
        }
    }

    return sum;
}