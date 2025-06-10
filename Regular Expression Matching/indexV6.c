#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p);
int match_main(int match_index, char *s, char *p);

int main(void) {
    printf("Answer: %d\n", isMatch("ab", ".*"));   //1

    printf("Answer: %d\n", isMatch("aab", "c*a*b"));   //1
    
    printf("Answer: %d\n", isMatch("acbdb", "aa*cbdb"));   //1
    printf("Answer: %d\n", isMatch("mississippi", "mis*is*p*.")); // 0
    printf("Answer: %d\n", isMatch("mississippi", "mis*is*p*.")); // 0
    printf("Answer: %d\n", isMatch("abcd", "d*"));// 0
    printf("Answer: %d\n", isMatch("aaa", "a*a")); // 1
    printf("Answer: %d\n", isMatch("ab", ".*c")); // 0
    printf("Answer: %d\n", isMatch("aaa", "ab*a*c*a")); // 1
    printf("Answer: %d\n", isMatch("a", "ab*")); // 1
    printf("Answer: %d\n", isMatch("a", ".*..a*")); // 1
    printf("Answer: %d\n", isMatch("mississippi", "mis*is*ip*.")); // 1
    return 0;
}

int match_main(int match_index, char *s, char *p) {
    // printf("%d\t%s\t%s\n", match_index, s, p);

    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    int find_star = -1;
    int next_match_index = -1;
    int back_space = -2;
    for (int i = 0; i < pattern_str_length; i++) {
        back_space++;
        if (p[i] == '*') {
            find_star = i;
            break;
        }
    }

    if (find_star != -1) {
        char barrier_chr = p[find_star + 1];
        if (back_space < 0) {
            back_space = 0;
        }
        for (int i = match_index + back_space; i <= source_str_length; i++) {
            if (s[i] == barrier_chr) {
                next_match_index = i + 1;
                if (next_match_index > source_str_length) {
                    next_match_index = -1;
                }
                break;
            }
        }
    } else {
        for (int i = 0; i < pattern_str_length; i++) {
            printf("%c{%c}\t", s[match_index + i], p[i]);
            if (s[match_index + i] == p[i] || p[i] == '.' || i == (pattern_str_length - 1)) {
                next_match_index = match_index + i;
            } else {
                break;
            }
            
        }
        printf("\n");
    }
    
    return next_match_index;
}

bool isMatch(char *s, char* p) {
    printf("%s\t%s\n", s, p);
    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    int pattern_split_size = 1;
    for (int i = 0; i < pattern_str_length; i++) {
        if (p[i] == '*') {
            pattern_split_size++;
        }
    }
    
    char **pattern_split = (char **)malloc(sizeof(char *) * pattern_split_size);
    for (int i = 0; i < pattern_split_size; i++) {
        pattern_split[i] = (char *)malloc(sizeof(char) * 25);
        memset(pattern_split[i], 0, 25);
    }
    for (int i = 0, j = 0, k=0; i <= pattern_str_length && j < pattern_split_size; i++) {
        pattern_split[j][k] = p[i];
        k++;
        if (p[i] == '*') {
            pattern_split[j][k] = p[i + 1];
            pattern_split[j][k + 1] = '\0';
            k = 0;
            j++;
        } else if (p[i] == '\0') {
            pattern_split[j][k] = '\0';
            k = 0;
            j++;
        }
    }
    
    int match_index = 0;
    for (int i = 0; i < pattern_split_size - 1; i++) {
        match_index = match_main(match_index, s, pattern_split[i]);
        printf("%d\t", match_index);
        if (match_index == -1) {
            break;
        }
    }
    printf("\n");
    return true;
}