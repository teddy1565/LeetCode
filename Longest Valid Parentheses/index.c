/**
 * @file index_v13.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-10-02
 * 
 * @copyright Copyright (c) 2025
 * 
 * stack implements
 * 
 */
#include "index.h"
int longestValidParentheses(char* s) {
    int str_length = strlen(s);
    if (str_length == 0 || str_length == 1) {
        return 0;
    } else if (str_length == 2) {
        if (s[0] == '(' && s[1] == ')') { 
             return 2;
         } else {
             return 0;
         }
    }

    int temp_length = 0;
    int max_length = 0;

    int *stack_list = (int *) malloc(sizeof(int) * (str_length + 1));
    memset(stack_list, 0, sizeof(int) * (str_length + 1));
    stack_list[0] = -1;
    int stack_index = 1;

    
    for (int i = 0; i < str_length; i++) {
        if (stack_index == 1 && s[i] == ')') {
            stack_list[0] = i;
            continue;
        } else if (s[i] == '(') {
            stack_list[stack_index++] = i;
        } else if (s[i] == ')') {
            int stack_list_index = --stack_index;
            int left_bracket_index = stack_list[stack_list_index - 1];
            
            int current_size = (i - left_bracket_index);
            stack_list[stack_list_index] = 0;
            if (current_size > max_length) {
                max_length = current_size;
            }
        }
    }

    free(stack_list);

    return max_length;
}
int main(void) {
    // printf("%d\n", longestValidParentheses(")(((((()())()()))()((())))"));
    assert(longestValidParentheses(")(((((()())()()))()((())))") == 24);
    assert(longestValidParentheses("(()(((()((((((((((") == 2);
    assert(longestValidParentheses(")()())") == 4);
    assert(longestValidParentheses("(()(((()()((((((((((") == 4);
    assert(longestValidParentheses("(()(((()()()((((((((((") == 6);
    assert(longestValidParentheses("(()(((()()()()((((((((((") == 8);
    assert(longestValidParentheses("(()(((()()()(()((((((((((") == 6);
    assert(longestValidParentheses("((((())))))((((((()))))))") == 14);
    assert(longestValidParentheses("(()") == 2);
    assert(longestValidParentheses("((((()))))((((((((()))))))))") == 28);
    assert(longestValidParentheses("))))))))))()()()((((((((((") == 6);
    assert(longestValidParentheses("(((((((((()()()))))))))))") == 24);
    assert(longestValidParentheses("((()))()))))))))))") == 8);
    assert(longestValidParentheses("()()((((((((((") == 4);
    assert(longestValidParentheses("((((()))))))") == 10);
    assert(longestValidParentheses("((((((((((()()") == 4);
    assert(longestValidParentheses("(((((((((((((((((()))))))))))))))))))") == 36);
    assert(longestValidParentheses("(()") == 2);
    assert(longestValidParentheses(")()())") == 4);
    assert(longestValidParentheses(")(((((()())()()))()(()))(") == 22);
    assert(longestValidParentheses("()(()") == 2);
    assert(longestValidParentheses("(()(((()") == 2);
    assert(longestValidParentheses("()(()(((") == 2);
    assert(longestValidParentheses("(((())))((()()())") == 8);
    assert(longestValidParentheses("(()((())()))") == 12);
    assert(longestValidParentheses("(()())(()()())") == 14);
    assert(longestValidParentheses("())(())(") == 4);
    assert(longestValidParentheses(")))()())") == 4);
    assert(longestValidParentheses("()())(()()()())(()))") == 14);
    return 0;
}