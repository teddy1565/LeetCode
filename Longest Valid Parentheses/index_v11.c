/**
 * @file index_v11.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-30
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
// ((((())))) ) ((((((()))))))
// 1234
// (((())))
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
    int max_size = 0;
    int a = 0, i = 0;
    int b = 1;
    int temp_size = 0;
    int stack_size = 0;
    // 遇到）時，可以先決斷是否斷句，反之，需要等到結尾
    for (;a < str_length && b < str_length;) {
        if (s[i] == ')') {
            i++;a++;b++;
            if (temp_size > max_size) {
                max_size = temp_size;
            }
            temp_size = 0;
        } else if (s[a] == '(' && s[b] == ')') {
            temp_size++;
            if (s[a - 1] == '(') {
                stack_size--;
            } else if (s[b + 1] == ')') {
                stack_size++;
            }
            b += 2;
            a = b - 1;
        } else if (s[a] == '(' && s[b] == '(') {
            a++;
            b++;
            stack_size++;
        } else if (s[a] == ')' && s[b] == ')') {
            stack_size--;
            if (stack_size < 0) {
                stack_size = 0;
                if (temp_size > max_size) {
                    max_size = temp_size;
                }
                temp_size = 0;
                i = a;
            }
        } else if (s[a] == ')' && s[b] == '(') {
            if (stack_size > 0) {
                temp_size++;
            }
            stack_size--;
            b++;
            a = b - 1;
            if (stack_size == 0) {
                i = a;
            }
        }
    }

    return max_size;
}

int main(void) {
    // longestValidParentheses("(((())))((()()())");

    /**
     * @brief 
     * 6, 7
     * 8, 9
     * 5, 10
     * 11, 12
     * 13, 14
     */
    printf("%d\n", longestValidParentheses("(()()))))))()()"));

    // assert(longestValidParentheses("((((())))))((((((()))))))") == 14);
    // assert(longestValidParentheses("(()") == 2);
    // assert(longestValidParentheses("((((()))))((((((((()))))))))") == 28);
    // assert(longestValidParentheses("))))))))))()()()((((((((((") == 6);
    // assert(longestValidParentheses("(((((((((()()()))))))))))") == 24);
    // assert(longestValidParentheses("((()))()))))))))))") == 8);
    // assert(longestValidParentheses("()()((((((((((") == 4);
    // assert(longestValidParentheses("((((()))))))") == 10);
    // assert(longestValidParentheses("((((((((((()()") == 4);
    // assert(longestValidParentheses("(((((((((((((((((()))))))))))))))))))") == 36);
    // assert(longestValidParentheses("(()") == 2);
    // assert(longestValidParentheses(")()())") == 4);
    // assert(longestValidParentheses(")(((((()())()()))()(()))(") == 22);
    // assert(longestValidParentheses("()(()") == 2);
    // assert(longestValidParentheses("(()(((()") == 2);
    // assert(longestValidParentheses("()(()(((") == 2);
    // assert(longestValidParentheses("(((())))((()()())") == 8);
    // assert(longestValidParentheses("(()((())()))") == 12);
    // assert(longestValidParentheses("(()())(()()())") == 14);
    // assert(longestValidParentheses("())(())(") == 4);
    // assert(longestValidParentheses(")))()())") == 4);
    // assert(longestValidParentheses("()())(()()()())(()))") == 14);
    return 0;
}