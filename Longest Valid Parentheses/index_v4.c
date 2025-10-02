/**
 * @file index_v4.c
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

    int max_bracket_counter = 0;

    int bracket_counter = 0;
    int valid_bracket_pair_counter = 0;
    int right_bracket_counter = 0;

    int tmp_counter = 0;

    char c = '\0';

    while (c = *(s++)) {
        if (c == '(') {
            bracket_counter++;
            right_bracket_counter = 0;
        } else if (c == ')') {
            right_bracket_counter++;
            if (bracket_counter > 0) {
                valid_bracket_pair_counter++;
            }
            bracket_counter--;
        }
        
        if (bracket_counter == 0) {
            tmp_counter += valid_bracket_pair_counter;
            valid_bracket_pair_counter = 0;
            right_bracket_counter = 0;
        } else if (bracket_counter < 0) {
            valid_bracket_pair_counter += tmp_counter;
            if (valid_bracket_pair_counter > max_bracket_counter) {
                max_bracket_counter = valid_bracket_pair_counter;
            }
            valid_bracket_pair_counter = 0;
            tmp_counter = 0;
            bracket_counter = 0;
            right_bracket_counter = 0;
        }
    }

    if (bracket_counter > 0) {
        valid_bracket_pair_counter = right_bracket_counter;
        if (valid_bracket_pair_counter > max_bracket_counter) {
            max_bracket_counter = valid_bracket_pair_counter;
        }
    } else if (bracket_counter == 0) {
        valid_bracket_pair_counter += tmp_counter;
        if (valid_bracket_pair_counter > max_bracket_counter) {
            max_bracket_counter = valid_bracket_pair_counter;
        }
    }
    

    return max_bracket_counter * 2;
}

int main(void) {
    return 0;
}