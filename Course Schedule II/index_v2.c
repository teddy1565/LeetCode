#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int **)a)[1] - (*(int **)b)[1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    qsort(prerequisites, prerequisitesSize, sizeof(int) * 2, compare);

    int *ans = (int *) malloc(sizeof(int) * numCourses);
    (*returnSize) = numCourses;

    int ans_index = 0;
    int ans_base = 0;

    int *stack = (int *) malloc(sizeof(int) * prerequisitesSize);
    int stack_index = 0;

    for (int i = 0; i < prerequisitesSize; i++) {
        if (prerequisites[i][1] == 0) {
            stack[stack_index++] = i;
        }
    }

    for (int i = 0; i < stack_index; i++) {
        int current_course = prerequisites[stack[i]][0];
        ans[ans_index++] = 0;
        while (current_course < (numCourses - 1)) {
            for (int i = 0; i < prerequisitesSize; i++) {
                
            }
        }
    }

    return ans;
}