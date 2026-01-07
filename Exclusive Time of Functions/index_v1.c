#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exec_time(char **logs, int logsSize, int log_index, int *ans, int ans_size, int ans_id) {

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    for (int i = 0; i < logsSize; i++) {
        printf("%s\n", logs[i]);
    }
    (*returnSize) = n;
    int *ans = (int *) malloc(sizeof(int) * n);
    exec_time(logs, logsSize, 0, ans, n, 0);
    return NULL;
}