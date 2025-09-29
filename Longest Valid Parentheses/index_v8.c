/**
 * @file index_v8.c
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
int longestValidParentheses(char* s) {

    int str_length = strlen(s);
    if (str_length == 0 || str_length == 1) {
        return 0;
    } else if (str_length == 2) {
        if (s[0] == '(' && s[1] == ')') return 2;
        else return 0;
    }

    int a = 0, b = 1;
    int temp_length = 0;
    int real_temp = 0;
    int max = 0;
    for (int i = 0; i < str_length - 1;) {
        printf("%d %d %d | %c %c %c\n", a, i, b, s[a], s[i], s[b]);

        if (s[i] == '(' && s[b] == '(') {
            i++;
            b++;
        } else if (s[i] == '(' && s[b] == ')') {
            
            temp_length++;
            printf("%d %d %d %d\n", a, i, b, temp_length);
            if (i == a) {
                b += 2;
                i = b - 1;
                a = b - 1;
                real_temp += temp_length;
                temp_length = 0;
            } else if (s[b + 1] == '(') {
                i += 2;
                b += 2;
            } else if (s[b + 1] == ')') {
                b++;
                i--;
            } else if (s[b + 1] == '\0' || s[b + 1] != '(' && s[b + 1] != ')') {
                if (a == i && s[i] == '(' && s[b] == ')') {
                    temp_length++;
                    real_temp += temp_length;
                    temp_length = 0;
                } else if (a != i && a != 0) {
                    temp_length--;
                    if (real_temp > max) {
                        max = real_temp;
                    }
                    real_temp = temp_length;
                    temp_length = 0;
                } else {
                    real_temp = temp_length;
                }
                break;
            }
        } else if (s[a] == '(' && s[i] == ')' && s[b] == ')') {
            i -= 2;
        } else if (s[a] == ')') {
            i++;
            a++;
            b++;
            real_temp += temp_length;
            temp_length = 0;
            if (real_temp > max) {
                max = real_temp;
            }
            real_temp = 0;
        }
    }

    

    if (real_temp > max) {
        max = real_temp;
    }
    printf("%d\n", max * 2);
    
    return max * 2;
}

int main(void) {
    longestValidParentheses("(((())))((()()())");
    return 0;
}