/**
 * @file index_v5.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

void lg(char *s) {
    char c = *(s++);
    if (c == '(') {

    }
}

// ()(()
// )))()())
// ())(())(
// (()())(()()())
int longestValidParentheses(char* s) {

    int str_length = strlen(s);
    if (str_length == 0 || str_length == 1) {
        return 0;
    } else if (str_length == 2) {
        if (s[0] == '(' && s[1] == ')') return 2;
        else return 0;
    }

    char c = '\0';
    
    char *s_stack = (char *) malloc(sizeof(char) * (str_length + 1));
    memset(s_stack, 0, sizeof(char) * (str_length + 1));

    int *count_stack = (int *) malloc(sizeof(int) * (str_length + 1));
    memset(count_stack, 0, sizeof(int) * (str_length + 1));

    int s_stack_index = 0;

    while (c = *(s++)) {
        if (c == '(') {
            s_stack[s_stack_index++] = '(';
        } else if (c == ')') {
            if (s_stack_index > 0 && s_stack[s_stack_index - 1] == '(') {
                count_stack[s_stack_index] += 1;
                s_stack[--s_stack_index] = '\0';
                
            } else {
                s_stack[s_stack_index++] = ')';
                s_stack_index++;
            }
        }
    }

    for (int i = 0; i < (str_length + 1); i++) {
        printf("%d ", count_stack[i]);
    }

    int max = 0;
    int temp = 0;
    for (int i = 0; i < (str_length + 1); i++) {
        if (count_stack[i] == 0) {
            if (temp > max) max = temp;
            temp = 0;
        } else {
            temp += count_stack[i];
        }
    }
    if (temp > max) max = temp;

    return max * 2;
}

int main(void) {
    return 0;
}