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
        if (p[i] == split_mark_star || p[i] == split_mark_dot) {
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
    char *temp_s = (char*) malloc(sizeof(char) * (pattern_string_length + 1) * 2);

    // 紀錄暫存的pattern，因為pattern可能不只一個
    char *temp_p = (char*) malloc(sizeof(char) * (pattern_string_length + 1));

    int s_group_length = 0;
    int p_group_length = 0;


    // 使用prev紀錄上一個是屬於string或pattern的狀態, 0表示string, 1表示pattern
    for (int i = 0, prev = 0, temp_s_k = 0, temp_p_k = 0; i < pattern_string_length + 1; i++) {
        if (p[i] == '\0') {
            temp_s[temp_s_k] = '\0';
            temp_p[temp_p_k] = '\0';
            break;
        }
        if ((p[i] == split_mark_dot && prev == 0) || (p[i] == split_mark_star && prev == 0)) {
            temp_s[temp_s_k] = '\0';
            temp_s_k++;
            s_group_length++;

            temp_p[temp_p_k] = p[i];
            temp_p_k++;
            prev = 1;
            continue;
        }
        if ((p[i] != split_mark_dot && prev == 1) && (p[i] != split_mark_star && prev == 1)) {
            
            temp_p[temp_p_k] = '\0';
            temp_p_k++;
            p_group_length++;

            temp_s[temp_s_k] = p[i];
            temp_s_k++;
            prev = 0;
            continue;
        }



        if (p[i] != split_mark_dot && p[i] != split_mark_star) {
            temp_s[temp_s_k] = p[i];
            temp_s_k++;
            continue;
        }
        if (p[i] == split_mark_dot || p[i] == split_mark_star) {
            
            temp_p[temp_p_k] = p[i];
            temp_p_k++;
            continue;
        }
    }

    // 用於儲存字串片段，主要用於debug
    char *group_source_string_shared = (char*) malloc(sizeof(char) * (source_string_length + 1));
    char *group_pattern_string_shared = (char*) malloc(sizeof(char) * (source_string_length + 1));

    // 將分類好的組合對應與解析
    for (int i=0, j=0; (i <= s_group_length) && (j <= p_group_length); i++, j++) {
        int k = 0, m = 0;
        while(temp_s[i] != '\0') {
            group_source_string_shared[k] = temp_s[i];
            i++;
            k++;
        }
        group_source_string_shared[k] = '\0';
        k++;
        
        while(temp_p[j] != '\0') {
            group_pattern_string_shared[m] = temp_p[j];
            j++;
            m++;
        }
        group_pattern_string_shared[m] = '\0';
        m++;
        printf("%s\n", group_source_string_shared);
        printf("%s\n", group_pattern_string_shared);
        printf("\n");
    }
    
}
// @lc code=end

int main() {
    isMatch("fuck", "abc.g*.");
    return 0;
}
