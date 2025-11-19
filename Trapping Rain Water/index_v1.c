#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int trap(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int m = heightSize - 1;
    int k = heightSize / 2;
    int sum = 0;
    for (int i = 1; i < heightSize; i++) {
        if (height[left] - height[i] <= 0) {
            left = i;
        } else if (height[left] - height[i] > 0) {
            for (int j = i; j < heightSize - 1; j++) {
                if (height[left] - height[j] <= 0) {
                    left = j;
                } else if (height[j] - height[right] <= 0) {
                    sum += (height[left] - height[j]);
                } else if (height[j] - height[right] > 0) {
                    break;
                }
            }
        }

        if (height[right] - height[m - i] <= 0) {
            right = m - i;
        } else if (height[right] - height[m - i] > 0) {
            sum += (height[right] - height[m - i]);
        }
    }
    return sum;
}