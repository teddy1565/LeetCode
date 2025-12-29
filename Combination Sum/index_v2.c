#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void backtrack( int target, int* candidates, int candidatesSize, int start_index, int sum,
                int **answer, int *returnSize, int** returnColumnSizes,
                int *path, int path_index
            ) {
    
    if (sum > target) {
        return;
    }
    if (sum == target) {
        int *temp_path = (int *) malloc(sizeof(int) * path_index);
        memcpy(temp_path, path, sizeof(int) * path_index);
        answer[(*returnSize)] = temp_path;
        (*returnColumnSizes)[(*returnSize)] = path_index;
        (*returnSize) += 1;
        return;
    }

    for (int i = start_index; i < candidatesSize; i++) {
        if ((sum + candidates[i]) > target) {
            continue;
        }
        
        sum += candidates[i];
        path[path_index++] = candidates[i];
        backtrack(target, candidates, candidatesSize, i, sum, answer, returnSize, returnColumnSizes, path, path_index);
        sum -= candidates[i];
        path_index -= 1;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **res = (int **) malloc(sizeof(int *) * 150);
    int *path = (int *) malloc(sizeof(int) * 40);
    (*returnSize) = 0;
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * 150);
    memset(path, 0, sizeof(int) * 40);
    qsort(candidates, candidatesSize, sizeof(int), compare);
    backtrack(target, candidates, candidatesSize, 0, 0, res, returnSize, returnColumnSizes, path, 0);
    return res;
}