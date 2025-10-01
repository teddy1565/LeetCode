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
    // )((()())(()))
    int i = 0, a = 1, b = 2;
    int loop_limit = 500;
    int loop_count = 0;
    printf("=======================\n");
    printf("str_length: %d\n", str_length);
    while (i < str_length && b < str_length) {
        if (loop_count > loop_limit) {
            break;
        }
        printf("%d %d %d\n", i, a, b);
        if (s[i] == ')') {
            i++; a++; b++;
            if (temp_length > max_length) {
                max_length = temp_length;
            }
            temp_length = 0;
        } else if (s[b] == '(') {
            if (s[b + 1] == ')') {
                b += 2;
                temp_length++;
            } else if (s[b + 1] == '(') {
                b += 1;
                if (a == i + 1) {
                    if (s[i] == '(' && s[a] == ')') {
                        temp_length++;
                        i = b - 2;
                    }
                    a = b - 1;
                } else {
                    a += 1;
                }
            }
        } else if (s[b] == ')') {
            b += 1;
            if (s[a] == '(') {
                a--;
                temp_length++;
            } else if (s[a] == ')') {
                if (s[i] == '(' && s[a] == ')') {
                    temp_length++;
                    i = b - 2;
                    a = b - 1;
                }
            }

            if (a < i) {
                printf("debug: %d %d %d\n", i, a, b);
                i = b;
                a = i + 1;
                b = i + 2;
            }
        }
        loop_count++;
    }
    if (temp_length > max_length) {
        max_length = temp_length;
    }
    printf("topic:\n\t");
    printf("%s\n", s);
    printf("max: %d, temp: %d\n", max_length, temp_length);
    return max_length * 2;
}
int main(void) {
    // printf("%d\n", longestValidParentheses(")(((((()())()()))()((())))"));
    assert(longestValidParentheses(")(((((()())()()))()((())))") == 24);
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