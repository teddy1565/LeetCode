#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Log {
    int id;
    char action_code;
    int tick;  
};


void parse_log(char *log_text, struct Log *log) {
    int log_length = strlen(log_text);
    int log_text_index = 0;
    int id = 0;
    int tick = 0;
    
    for (; log_text[log_text_index] != ':'; log_text_index++) {
        id = id * 10 + (log_text[log_text_index] - '0');
    }
    log_text_index += 1;
    log->id = id;
    log->action_code = log_text[log_text_index];
    for (; log_text[log_text_index] != ':'; log_text_index++);
    log_text_index += 1;
    for (; log_text_index < log_length; log_text_index++) {
        tick = tick * 10 + (log_text[log_text_index] - '0');
    }
    log->tick = tick;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int *ans = (int *) malloc(sizeof(int) * n);
    memset(ans, 0, sizeof(int) * n);
    (*returnSize) = n;
    
    int prev_tick = 0;
    int *action_stack = (int *) malloc(sizeof(int) * logsSize);
    int action_stack_index = 0;
    struct Log *log = (struct Log *) malloc(sizeof(struct Log));
    for (int i = 0; i < logsSize; i++) {
        parse_log(logs[i], log);
        if (log->action_code == 's') {
            if (action_stack_index > 0) {
                int prev_id = action_stack[action_stack_index - 1];
                ans[prev_id] += (log->tick - prev_tick);
            }
            action_stack[action_stack_index++] = log->id;
            prev_tick = log->tick;
        } else {
            ans[log->id] += ((log->tick - prev_tick) + 1);
            action_stack_index -= 1;
            prev_tick = log->tick + 1;
        }
    }

    free(log);
    free(action_stack);

    return ans;
}