#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int trap(int* height, int heightSize) {
    if (heightSize < 3) {
        return 0;
    }

    int left_index = 0;
    int right_index = heightSize - 1;
    int sum = 0;
    int left_barrier_value = 0;
    int right_barrier_value = 0;


    while (left_index < right_index) {
        if (height[left_index] < height[right_index]) {
            if (height[left_index] >= left_barrier_value) {
                left_barrier_value = height[left_index];
            } else {
                sum += (left_barrier_value - height[left_index]);
            }

            left_index++;
        } else {
            if (height[right_index] >= right_barrier_value) {
                right_barrier_value = height[right_index];
            } else {
                sum += (right_barrier_value - height[right_index]);
            }
            right_index--;
        }
    }

    return sum;
}