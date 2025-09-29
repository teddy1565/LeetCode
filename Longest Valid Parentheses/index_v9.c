/**
 * @file index_v9.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


// ()(()
// )))()())
// ())(())(
// (()())(()()())
// ((()))(()())
// ")(((((()())()()))()(()))("
// ()(()(() 
int longestValidParentheses(char* s) {

    int str_length = strlen(s);
    if (str_length == 0 || str_length == 1) {
        return 0;
    } else if (str_length == 2) {
        if (s[0] == '(' && s[1] == ')') return 2;
        else return 0;
    }
    
}

int main(void) {
    longestValidParentheses("(((())))((()()())");
    return 0;
}