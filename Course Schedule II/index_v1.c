#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int *ans = (int *) malloc(sizeof(int) * numCourses);
    (*returnSize) = numCourses;

    ans[0] = 0;
    int ans_index = 1;
    int ans_base = 0;

    int *stack = (int *) malloc(sizeof(int) * prerequisitesSize);
    int stack_index = 0;

    while (ans_index < numCourses) {
        for (int i = ans_base; i < ans_index; i++) {
            for (int j = 0; j < prerequisitesSize; j++) {
                if (prerequisites[j][1] == ans[i]) {
                    
                }
            }
        }
        for (int i = 0; i < prerequisitesSize; i++) {

        }
    }
    
    return ans;
}