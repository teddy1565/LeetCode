#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int can_see(int* heights, int i, int j) {
    if (j == i + 1) return 1;
    int min = heights[i] < heights[j] ? heights[i] : heights[j];
    int max = heights[i + 1];
    for (int k = i + 1; k < j; k++) {
        if (heights[k] > max) {
            max = heights[k];
        }
    }

    if (min > max) {
        return 1;
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    (*returnSize) = heightsSize;
    int *answer = (int *) malloc(sizeof(int) * (*returnSize));
    memset(answer, 0, sizeof(int) * (*returnSize));

    int *height_stack = (int *) malloc(sizeof(int) * (*returnSize));
    int height_stack_index = 0;

    for (int i = heightsSize - 1; i >= 0; i--) {
        int n = 0;
        for (int j = height_stack_index - 1; j >= 0; j--) {
            if (height_stack[j] < heights[i]) {
                height_stack_index -= 1;
                n++;
            } else {
                n += 1;
                break;
            }
        }
        height_stack[height_stack_index++] = heights[i];
        answer[i] = n;
    }
    // for (int i = 0; i < heightsSize; i++) {
    //     int ans = 0;
    //     for (int j = i + 1; j < heightsSize; j++) {
    //         ans += can_see(heights, i, j);
    //     }
    //     answer[i] = ans;
    // }
    return answer;
}