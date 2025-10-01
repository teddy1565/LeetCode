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

    // )((()())(()))
    int i = 0, a = 1, b = 2;
    while (b < str_length) {
        if (s[i] == ')') {
            i++; a++; b++;
        } else if (s[b] == '(') {
            if (s[b + 1] == ')') {
                b += 2;
            } else if (s[b + 1] == '(') {
                b += 1;
                if (a == i + 1) {
                    a = b - 1;
                } else {
                    a += 1;
                }
            }
        } else if (s[b] == ')') {
            b += 1;
            if (a == i) {
                a = b - 1;
                if (s[a] == ')' && s[i] == '(') {
                    a++; b++;
                    i = a - 1;
                }
            } else if (s[a] == '(') {
                a--;
            } else if (s[a] == ')') {
                if (s[i] == '(') {
                    i = a + 1;
                    a = b - 1;
                }
            }
        }
    }
    return 0;
}
int main(void) {
    return 0;
}