/*
 * @lc app=leetcode id=10 lang=c
 *
 * [10] Regular Expression Matching
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// @lc code=start
bool isMatch(char* s, char* p) {

    const int source_string_length = strlen(s);
    const int pattern_string_length = strlen(p);

    // case
    // single '*'
    // single '.'
    // multi '.*'
    // multi '*.'
    const char split_mark_star = '*';
    const char split_mark_dot = '.';

    // if no any pattern
    bool find_pattern = false;
    for (int i = 0; i < source_string_length; i++) {
        if (s[i] == split_mark_star || s[i] == split_mark_dot) {
            find_pattern = true;
            break;
        }
    }

    if (find_pattern == false) {
        if (source_string_length != pattern_string_length) {
            return false;
        } else {
            for (int i = 0; i < source_string_length; i++) {
                if (s[i] != p[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    

    // 記錄暫存的string
    const char *temp_s = (char*) malloc(sizeof(char) * (source_string_length + 1));

    // 紀錄暫存的pattern，因為pattern可能不只一個
    const char *temp_p = (char*) malloc(sizeof(char) * (source_string_length + 1));
    for (int i = 0; i < source_string_length; i++) {

    }
    
}
// @lc code=end

