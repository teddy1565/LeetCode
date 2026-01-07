#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {

    int **status = (int **) malloc(sizeof(int *) * n);
    // [[action, tick].....]
    for (int i = 0; i < n; i++) {
        status[i] = (int *) malloc(sizeof(int) * 2);
    }
    int *ans = (int *) malloc(sizeof(int) * n);
    (*returnSize) = n;
    memset(ans, 0, sizeof(int) * n);

    for (int i = 0; i < logsSize; i++) {
        int log_str_length = strlen(logs[i]);
        int j = 0;

        int id = 0;
        int action = 0; // 1 == start, 2 == end
        int tick = 0;
        // <id> : <action> : <tick>
        for (; j < log_str_length; j++) {
            
            if (logs[i][j] == ':') {
                break;
            }
            id = (id * 10) + (logs[i][j] - '0');
        }
        j += 1;
        if (logs[i][j] == 'e') {
            action = 2;
        } else {
            action = 1;
        }
        for (; j < log_str_length; j++) {
            if (logs[i][j] == ':') {
                break;
            }
        }
        j += 1;
        for (; j < log_str_length; j++) {
            tick = (tick * 10) + (logs[i][j] - '0');
        }
        
        printf("%d %d %d\n", id, action, tick);
        

        if (status[id][0] == 1) {
            if (action == 1) {
                ans[id] += ((tick - status[id][1]));
            } else if (action == 2) {
                ans[id] += ((tick - status[id][1]) + 1);
            }
        } else if (status[id][0] == 2) {
            if (action == 1) {

            } else if (action == 2) {
                ans[id] += ((tick - status[id][1]));
            }
        }

        status[id][0] = action;
        status[id][1] = tick;
        
    }

    for (int i = 0; i < n; i++) {
        free(status[i]);
    }

    free(status);

    return ans;
}