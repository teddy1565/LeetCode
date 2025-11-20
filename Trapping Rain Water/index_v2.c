#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// [1,2,5,5,4,5,6,3]

int trap(int* height, int heightSize) {
    if (heightSize < 3) {
        return 0;
    } else if (heightSize == 3) {
        if (height[1] >= height[0] || height[1] >= height[2]) {
            return 0;
        } else if (height[0] >= height[2]) {
            return height[2] - height[1];
        }
        return height[0] - height[1];
    }

    int left_index = 0;
    int right_index = heightSize - 1;
    int sum = 0;

    for (int i = 1; i < heightSize; i++) {
        if (height[i] >= height[left_index]) {
            left_index = i;
        } else {
            break;
        }
    }

    /**
     * @brief
     * means, if initial stage
     * 
     * left_barrier position locate Bigger then right_barrier postion
     * 
     * no any water
     */
    if (left_index >= (right_index - 1)) {
        return 0;
    }

    for (int i = heightSize - 1; i >= 0; i--) {
        if (height[i] >= height[right_index]) {
            right_index = i;
        } else {
            break;
        }
    }
    

    /**
     * @brief 
     * means, if initial stage
     * 
     * right_barrier position locate Bigger then left_barrier position
     * 
     * no any water
     */
    if (right_index <= left_index + 1) {
        return 0;
    }

    while (left_index < right_index) {
        int stop_index = left_index + 1;
        int left_base_n = height[left_index];
        int right_base_n = height[right_index];
        while (height[stop_index] < height[left_index] && stop_index < right_index) {
            stop_index++;
        }

        if (height[left_index] >= height[stop_index]) {
            left_base_n = height[stop_index];
        }

        for (int i = left_index + 1; i < stop_index; i++) {
            if (height[i] > left_base_n) {
                sum += (height[i] - left_base_n);
            } else {
                sum += (left_base_n - height[i]);
            }
        }

        if (stop_index == right_index) {
            break;
        }

        left_index = stop_index;
        stop_index = right_index - 1;

        while (height[stop_index] < height[right_index] && stop_index > left_index) {
            stop_index--;
        }

        if (height[right_index] >= height[stop_index]) {
            right_base_n = height[stop_index];
        }

        for (int i = right_index - 1; i > stop_index; i--) {
            if (height[i] > right_base_n) {
                sum += (height[i] - right_base_n);
            } else {
                sum += (right_base_n - height[i]);
            }
        }

        if (stop_index == left_index) {
            break;
        }

        right_index = stop_index;
    }

    return sum;
}