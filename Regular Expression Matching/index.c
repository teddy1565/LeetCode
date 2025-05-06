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
    char *temp_s = (char*) malloc(sizeof(char) * (source_string_length + 1) * 2);

    // 紀錄暫存的pattern，因為pattern可能不只一個
    char *temp_p = (char*) malloc(sizeof(char) * (source_string_length + 1));

    // 使用prev紀錄上一個是屬於string或pattern的狀態, 0表示string, 1表示pattern
    for (int i = 0, prev = 0, temp_s_k = 0, temp_p_k = 0; i < source_string_length; i++) {
        if ((s[i] == split_mark_dot && prev == 0) || (s[i] == split_mark_star && prev == 0)) {
            temp_s[temp_s_k] = '\0';
            temp_s_k++;
            continue;
        }
        if ((s[i] != split_mark_dot && prev == 1) && (s[i] != split_mark_star && prev == 1)) {
            temp_p[temp_p_k] = '\0';
            temp_p_k++;
            continue;
        }
        if (s[i] != split_mark_dot && s[i] != split_mark_star) {
            temp_s[temp_s_k] = s[i];
            temp_s_k++;
            continue;
        }
        if (s[i] == split_mark_dot || s[i] == split_mark_star) {
            temp_p[temp_p_k] = s[i];
            temp_p_k++;
            continue;
        }
    }
    
}
// @lc code=end

