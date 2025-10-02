/**
 * @file index_v3.c
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

    int valid_bracket_counter = 0;
    int max_bracket_counter = 0;
    int valid_bracket_pair_counter = 0;
    int tmp_bracket_counter = 0;

    bool need_close = false;
    char c = '\0';
    while (c = *(s++)) {
        if (c == '(') {
            if (need_close == true) {
                need_close = false;
                valid_bracket_pair_counter = 0;
                tmp_bracket_counter = 0;
                valid_bracket_counter = 0;
            }
            valid_bracket_counter++;
        } else if (c == ')') {
            need_close = true;
            if (valid_bracket_counter > 0) {
                valid_bracket_pair_counter++;
            }
            valid_bracket_counter--;
        }

        if (valid_bracket_counter == 0) {
            tmp_bracket_counter += valid_bracket_pair_counter;
            valid_bracket_pair_counter = 0;
            need_close = false;
        } else if (valid_bracket_counter < 0) {
            int total_bracket_counter = tmp_bracket_counter + valid_bracket_pair_counter;
            valid_bracket_counter = 0;
            tmp_bracket_counter = 0;
            valid_bracket_pair_counter = 0;
            need_close = false;
            if (total_bracket_counter > max_bracket_counter) {
                max_bracket_counter = total_bracket_counter;
            }
        }
    }

    int last_bracket_counter = valid_bracket_pair_counter;

    if (need_close == false) {
        last_bracket_counter += tmp_bracket_counter;
    }

    if (last_bracket_counter > max_bracket_counter) {
        max_bracket_counter = last_bracket_counter;
    }

    return max_bracket_counter * 2;
}

int main(void) {
    return 0;
}