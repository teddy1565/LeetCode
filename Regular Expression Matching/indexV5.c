#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int source_str_length = strlen(s);
    int pattern_str_length = strlen(p);

        // * 意思是指0或多個前導元素
    const char split_mark_star = '*';

    // . 意思是指任意字元
    const char split_mark_dot = '.';

    // if no any pattern
    bool find_pattern = false;
    for (int i = 0; i < pattern_str_length; i++) {
        if (p[i] == split_mark_star || p[i] == split_mark_dot) {
            find_pattern = true;
            break;
        }
    }

    if (find_pattern == false) {
        if (source_str_length != pattern_str_length) {
            return false;
        } else {
            for (int i = 0; i < source_str_length; i++) {
                if (s[i] != p[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    if (pattern_str_length == 2 && p[0] == '.' && p[1] == '*') {
        return true;
    }

    if (pattern_str_length == 2 && p[1] == '*') {
        if (p[0] != s[0] && s[0] != '\0') {
            return false;
        }
    }

    // ==== 結束pattern如果沒有split_mark檢查

    printf("GG\n");
    char *must_equal = (char *)malloc(sizeof(char) * 21);
    char *str_header = must_equal;
    memset(str_header, 0, 21);
    char pattern_chr = '\0';

    int match_index = 0;
    for (int i = 1; i <= pattern_str_length; i++) {
        if (p[i] == '*') {
            // 先處理必須一樣的部分
            pattern_chr = p[i - 1];
            *(must_equal)++ = '\0';
            for (int k = 0, g = 0; k < strlen(str_header); k++) {
                if (str_header[k] == '.') {
                    continue;
                } else if (str_header[k] != '.' && s[match_index + g] != str_header[k]) {
                    printf("%c\t%c\t%d\t%d\n", str_header[k], s[match_index + g] ,match_index, g);
                    free(str_header);
                    return false;
                }
                match_index++;
                g++;
            }
            // match_index = match_index + (strlen(str_header));
            must_equal = str_header;
            // 接著處理在意的部分
            if (pattern_chr == '.' && (i + 1) < pattern_str_length) {
                char n = p[i + 1];
                while(match_index < source_str_length && s[match_index] != n) {
                    match_index++;
                }
            } else if ((i + 1) < pattern_str_length) {
                while(match_index < source_str_length) {
                    if (s[match_index] == pattern_chr && s[match_index + 1] != '\0') {
                        match_index++;
                    } else {
                        break;
                    }
                }
            }
            i++;
        } else if (p[i] == '\0') {
            if (match_index == source_str_length && match_index == pattern_str_length) {
                free(str_header);
                return true;
            }
            
            *(must_equal)++ = p[i - 1];
            *(must_equal)++ = '\0';
            for (int k = 0; k < strlen(str_header); k++) {
                if (s[match_index + k] != str_header[k] && str_header[k] != '.') {
                    return false;
                }
            }
            match_index = match_index + (strlen(str_header));
            
            must_equal = str_header;
            if (match_index != source_str_length) {
                free(str_header);
                return false;
            }
        } else {
            *(must_equal)++ = p[i - 1];
        }
    }
    free(str_header);
    return true;
}


int main(void) {
    printf("[res: %d\n", isMatch("ab", ".*"));   //1

    printf("[res: %d\n", isMatch("aab", "c*a*b"));   //1
    
    printf("[res: %d\n", isMatch("acbdb", "aa*cbdb"));   //1
    printf("[res: %d\n", isMatch("mississippi", "mis*is*p*.")); // 0
    printf("[res: %d\n", isMatch("mississippi", "mis*is*p*.")); // 0
    printf("[res: %d\n", isMatch("abcd", "d*"));// 0
    printf("[res: %d\n", isMatch("aaa", "a*a")); // 1
    printf("[res: %d\n", isMatch("ab", ".*c")); // 0
    printf("[res: %d\n", isMatch("aaa", "ab*a*c*a")); // 1
    printf("[res: %d\n", isMatch("a", "ab*")); // 1
    printf("[res: %d\n", isMatch("a", ".*..a*")); // 1
    printf("[res: %d\n", isMatch("mississippi", "mis*is*ip*.")); // 1
    return 0;
}