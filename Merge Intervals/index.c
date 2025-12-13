#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int **x = (int **)a;
    int **y = (int **)b;
    int n = (*x)[0] - (*y)[0];
    if (n == 0) {
        return (*x)[1] - (*y)[1];
    }
    return n;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int) * 2, compare);

    int **result_list = (int **) malloc(sizeof(int *) * intervalsSize);

    (*returnSize) = 0;
    free(*returnColumnSizes);

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][0] <= end) {
            if (intervals[i][1] > end) {
                end = intervals[i][1];
            }
        } else if (intervals[i][0] > end) {
            result_list[(*returnSize)] = (int *) malloc(sizeof(int) * 2);
            result_list[(*returnSize)][0] = start;
            result_list[(*returnSize)][1] = end;
            start = intervals[i][0];
            end = intervals[i][1];
            (*returnSize) += 1;
        }
    }

    result_list[(*returnSize)] = (int *) malloc(sizeof(int) * 2);
    result_list[(*returnSize)][0] = start;
    result_list[(*returnSize)][1] = end;
    (*returnSize) += 1;

    (*returnColumnSizes) = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result_list;
}
