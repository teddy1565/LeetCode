#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int **)a)[1] - (*(int **)b)[1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * 1. 可能有任意選修課
 * 2. 可能存在dead lock
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    qsort(prerequisites, prerequisitesSize, sizeof(int) * 2, compare);

    int *ans = (int *) malloc(sizeof(int) * numCourses);
    (*returnSize) = numCourses;

    int ans_index_left = 0;
    int ans_index_right = numCourses - 1;

    int *stack = (int *) malloc(sizeof(int) * prerequisitesSize);
    int stack_index = 0;

    for (int i = numCourses - 1; i >= 0; i--) {

        for (int j = 0; j < stack_index; j++) {
            
        }

        stack_index = 0;

        for (int j = 0; j < prerequisitesSize; j++) {
            if (prerequisites[i][0] == i) {
                stack[stack_index++] = prerequisites[i][1];
            }
        }

        if (stack_index == 0) {
            ans[ans_index_left++] = i;
            continue;
        }
    }

    return ans;
}