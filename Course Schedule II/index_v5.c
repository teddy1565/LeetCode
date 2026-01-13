#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct course_node {
    int val;
    int child_size;
    int *child_list;
};

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
    int ans_index = 0;

    struct course_node *list = (struct course_node *) malloc(sizeof(struct course_node) * numCourses);

    for (int i = 0; i < numCourses; i++) {
        list[i].child_size = 0;
        list[i].child_list = (int *) malloc(sizeof(int) * (numCourses - 1));
        list[i].val = i;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int target = prerequisites[i][1];
        int n = prerequisites[i][0];
        int find = 0;
        for (int j = 0; j < list[n].child_size; j++) {
            if (list[n].child_list[j] == target) {
                find = 1;
                break;
            }
        }
        if (find == 0) {
            list[n].child_list[list[n].child_size] = target;
            list[n].child_size += 1;
        }
    }

    for (int i = numCourses - 1; i >= 0; i--) {
        if (list[i].child_size == 0) {
            ans[ans_index++] = list[i].val;
        }
    }
    for (int i = numCourses - 1; i >= 0; i--) {
        if (list[i].child_size == 0) {
            continue;
        }
        for (int j = 0; j < list[i].child_size; j++) {
            int target = list[i].child_list[j];
            int find = 0;
            for (int k = 0; k < ans_index; k++) {
                if (target == ans[k]) 
                {
                    find = 1;
                    break;
                }
            }

            if (find == 1) {
                continue;
            }
            
        }
    }

    return ans;
}