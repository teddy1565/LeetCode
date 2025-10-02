/**
 * @file index_v6.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-28
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
int longestValidParentheses(char* s) {

    int str_length = strlen(s);
    if (str_length == 0 || str_length == 1) {
        return 0;
    } else if (str_length == 2) {
        if (s[0] == '(' && s[1] == ')') return 2;
        else return 0;
    }

    char c = '\0';
    int a = 0;
    int b = 1;
    int *length_list = (int *) malloc(sizeof(int) * (str_length + 1));
    memset(length_list, 0, sizeof(int) * (str_length + 1));

    int stack_size = 0;
    
    int temp = 0;
    
    while (s[a] != '\0' && s[b] != '\0') {
        printf("%d %d %d\n", a, b, stack_size);
        if (s[a] == '(' && s[b] == ')') {
            if (stack_size == 0) {
                b += 2;
                a = b - 1;
            } else if (stack_size > 0) {
                stack_size--;
                a-=1;
                b+=1;
            }
        } else if (s[a] == '(' && s[b] == '(') {
            
            b++;
            a = b - 1;
            stack_size++;
        } else if (s[a] == ')') {
            
            b++;
            a = b - 1;
        }
    }
    
    return 0;
}

int main(void) {
    return 0;
}