/*
 * @lc app=leetcode id=10 lang=c
 *
 * [10] Regular Expression Matching
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 相較於分析符號進行分組，直接將*當作斷點標籤

// @lc code=start
bool isMatch(char* s, char* p) {

    const int source_string_length = strlen(s);
    const int pattern_string_length = strlen(p);

    // * 意思是指0或多個前導元素
    const char split_mark_star = '*';

    // . 意思是指任意字元
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
            if (prev == 0) {
                s_group_length++;
            } else {
                p_group_length++;
            }
            break;
        }
        if ((p[i] == split_mark_star && prev == 0)) {
            temp_s[temp_s_k] = '\0';
            temp_s_k++;
            s_group_length++;

            temp_p[temp_p_k] = p[i];
            temp_p_k++;
            prev = 1;
            continue;
        }
        printf("[%c]{%d}\n", p[i], prev);
        if ((p[i] != split_mark_star && prev == 1)) {
            temp_p[temp_p_k] = '\0';
            temp_p_k++;
            p_group_length++;

            temp_s[temp_s_k] = p[i];
            temp_s_k++;
            prev = 0;
            continue;
        }



        if (p[i] != split_mark_star) {
            temp_s[temp_s_k] = p[i];
            temp_s_k++;
            continue;
        }
        if (p[i] == split_mark_star) {
            
            temp_p[temp_p_k] = p[i];
            temp_p_k++;
            continue;
        }
    }

    printf("\n");

    // 用於儲存字串片段，主要用於debug
    char *group_source_string_shared = (char*) malloc(sizeof(char) * (source_string_length + 1));
    char *group_pattern_string_shared = (char*) malloc(sizeof(char) * (source_string_length + 1));

    printf("%d\t%d\n", s_group_length, p_group_length);

    // 將分類好的組合對應與解析
    for (int i=0, j=0; (i <= s_group_length) || (j <= p_group_length); i++, j++) {
        int k = 0, m = 0;
        printf("(%d)\n", i);
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
