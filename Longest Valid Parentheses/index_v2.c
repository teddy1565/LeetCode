/**
 * @file index_v2.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "index.h"


// ()(()
// )))()())
// ())(())(
// (()())(()()())
int longestValidParentheses(char* s) {
    int max_count = 0;

    int bracket_counter = 0;
    int valid_bracket_counter = 0;
    
    int tmp_bracket_counter = 0;
    bool need_close = false;
    char c = '\0';
    while (c = *(s++)) {

        if (c == '(' && need_close == false) {
            bracket_counter++;
        } else if (c == '(' && need_close == true) {
            need_close = false;
            bracket_counter = 1;
            valid_bracket_counter = 0;
        } else if (c == ')') {
            need_close = true;
            bracket_counter--;
            if (bracket_counter >= 0) {
                valid_bracket_counter++;
            }

            if (bracket_counter == 0) {
                valid_bracket_counter += tmp_bracket_counter;
                tmp_bracket_counter = 0;
                need_close = false;
            }
        }

        if (valid_bracket_counter > max_count) {
            max_count = valid_bracket_counter;
        }
        
        if (bracket_counter <= 0) {
            tmp_bracket_counter = valid_bracket_counter;
            valid_bracket_counter = 0;
            bracket_counter = 0;
        }
    }
    return max_count * 2;
}

int main(void) {
    return 0;
}