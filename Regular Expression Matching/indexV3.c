#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int m(char *s, char *p, int match_index) {
    int source_str_length = strlen(s);
    int pattern_str_length = strlen(p);
    int m_index = match_index;
    printf("%s\t%s\n", s, p);
    
    for (int i = 0; i < pattern_str_length; i++) {
        if (s[m_index] == p[i] || p[i] == '.') {
            m_index++;
        } else {
            return -1;
        }
    }
    return m_index - 1;
}

bool isMatch(char* s, char* p) {
    int source_str_length = strlen(s);
    int pattern_str_length = strlen(p);

        // * 意思是指0或多個前導元素
    const char split_mark_star = '*';

    // . 意思是指任意字元
    const char split_mark_dot = '.';

    // if no any pattern
    bool find_pattern = false;
    for (int i = 0; i < source_str_length; i++) {
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
    
    char *pattern_str_shared = (char *)malloc(sizeof(char) * 21);

    int pattern_str_shared_index = 0;

    int match_str_index = 0;
    for (int i = 0; i <= pattern_str_length; i++) {
        if (p[i] == '*' || p[i] == '\0') {
            pattern_str_shared[pattern_str_shared_index] = '\0';
            pattern_str_shared_index = 0;

            int t = m(s, pattern_str_shared, match_str_index);
            if (t == -1) {
                return false;
            }

            if (p[i] == '\0') {
                break;
            }

            match_str_index = t + 1;
            int find_align = -1;
            if (s[match_str_index] != p[i + 1]) {
                for (int k = match_str_index; k < source_str_length; k++) {
                    if (s[k] == p[i + 1]) {
                        match_str_index = k;
                        find_align = 1;
                        break;
                    }
                }
            }
            if (find_align == -1) {
                break;
            }
            printf("%c\t%c\n", p[i + 1], s[match_str_index]);
        } else {
            pattern_str_shared[pattern_str_shared_index] = p[i];
            pattern_str_shared_index++;
        }
        
    }

    return true;
}


int main(void) {
    bool res = isMatch("aa", "a");
    printf("res: %d\n", res);
    return 0;
}