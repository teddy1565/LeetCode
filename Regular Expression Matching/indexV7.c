#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p);
int match_main(int match_index, char *s, char *p);

int old_main(void) {
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
    printf("Answer: %d\n", isMatch("a", ".*..a*")); // 0
    printf("Answer: %d\n", isMatch("mississippi", "mis*is*ip*.")); // 1
    return 0;
}

int main(void) {


    // printf("Answer: %d\n", isMatch("acbdb", "aa*cbdb"));   //1
    // printf("Answer: %d\n", isMatch("aaa", "ab*a*c*a")); // 1
    // printf("Answer: %d\n", isMatch("a", "ab*")); // 1
    // printf("Answer: %d\n", isMatch("aa", "a*")); // 1

    // printf("Answer: %d\n", isMatch("ab", ".*c")); // 0
    // printf("Answer: %d\n", isMatch("mississippi", "mis*is*p*.")); // 0
    // printf("Answer: %d\n", isMatch("mississippi", "mis*is*p*.")); // 0
    // printf("Answer: %d\n", isMatch("abcd", "d*"));// 0
    // printf("Answer: %d\n", isMatch("a", ".*..a*")); // 0
    
    // printf("Answer: => %d\n", isMatch("a", "ab*a")); // 0
    // printf("Answer: => %d\n", isMatch("a", "a*a")); // 1
    // printf("Answer: => %d\n", isMatch("a", ".*.")); // 1
    // printf("Answer: => %d\n", isMatch("b", "b.*c")); // 0


    // printf("Answer: => %d\n", isMatch("aab", "b.*")); // 0
    // printf("Answer: => %d\n", isMatch("b", "b*")); // 1
    // printf("Answer: => %d\n", isMatch("a", ".*a*")); // 1
    printf("Answer: => %d\n", isMatch("bab", "..*")); // 1


    // printf("Answer: => %d\n", isMatch("aaag", "aaa*g")); // 1
    // printf("Answer: => %d\n", isMatch("aaag", ".*")); // 1
    // printf("Answer: => %d\n", isMatch("ab", ".*"));   //1
    // printf("Answer: => %d\n", isMatch("aab", "c*a*b"));   //1
    // printf("Answer: => %d\n", isMatch("acbdb", "aa*cbdb"));   //1
    // printf("Answer: => %d\n", isMatch("aaa", "ab*a*c*a")); // 1
    // printf("Answer: => %d\n", isMatch("a", "ab*")); // 1
    // printf("Answer: => %d\n", isMatch("mississippi", "mis*is*ip*.")); // 1
    
    // printf("Answer: %d\n", isMatch("aaa", "a*a")); // 1
    // printf("Answer: %d\n", isMatch("aaag", ".*g")); // 1
    return 0;
}

int match_main(int match_index, char *s, char *p) {
    printf("%d\t%s\t%s\n", match_index, s, p);
    const int pattern_str_len = strlen(p);
    bool next_char_is_be_zero_or_more = false;
    char latest_match_chr = '\0';
    for (int i = (pattern_str_len - 1); i >= 0; i--) {
        
        if (next_char_is_be_zero_or_more == true && p[i] != '.') {
            latest_match_chr = p[i];
            while(match_index >= 0 && p[i] == s[match_index]) {
                printf("%c\t%c\n", s[match_index], p[i]);
                match_index--;
            }
            next_char_is_be_zero_or_more = false;
        } else if (next_char_is_be_zero_or_more == true && p[i] == '.') {
            char barrier_chr = '\0';
            if ((i - 1) >= 0) {
                barrier_chr = p[i - 1];
            }
            while(match_index >= 0) {
                match_index--;
                if (barrier_chr != '\0' && match_index >= 0 && s[match_index] == barrier_chr) {
                    
                    break;
                }
            }
            next_char_is_be_zero_or_more = false;
        } else if (p[i] == '*') {
            next_char_is_be_zero_or_more = true;
        } else {
            if (match_index >= 0 && i >= 0) {
                printf("[%c\t%c\n", s[match_index], p[i]);
            }
            if (match_index < 0 && p[i] == latest_match_chr) {
                return -1;
            }
            if (match_index >= 0 && s[match_index] == p[i] || p[i] == '.') {
                printf("i%d\n", i);
                match_index--;
            } else {
                return -2;
            }
        }
    }

    return match_index;
}

bool isMatch(char *s, char* p) {
    printf("%s\t%s\n------\n", s, p);
    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    if (pattern_str_length == 2 && p[0] == '.' && p[1] == '*') {
        return true;
    } else if (source_str_length == 1 && pattern_str_length == 1) {
        if (s[0] == p[0] || p[0] == '.') {
            return true;
        }
        return false;
    } else if (source_str_length == 1 && pattern_str_length < 5) {
        int hit_count = 0;
        int star_count = 0;
        int not_hit_count = 0;
        for (int i = pattern_str_length-1; i >= 0; i--) {
            if (p[i] == s[0]) {
                hit_count++;
            } else if (p[i] == '*') {
                star_count++;
                if (p[i - 1] == s[0] || p[i - 1] == '.') {
                    hit_count--;
                } else {
                    not_hit_count--;
                }
            } else if (p[i] == '.') {
                hit_count++;
            } else if (p[i] != s[0]) {
                not_hit_count++;
            }
        }
        printf("%d\t%d\t%d\n", hit_count, star_count, not_hit_count);
        if (not_hit_count) {
            return false;
        } else if (hit_count == star_count) {
            return true;
        } else if (hit_count == 0 && star_count == 1) {
            return true;
        } else if (hit_count == 0 && star_count == 2) {
            return true;
        }
        return false;
    }

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
        if (p[i] == '*' || p[i] == '\0') {
            pattern_split[j][k] = '\0';
            k = 0;
            j++;
        }
    }

    bool result = false;

    int match_index = source_str_length - 1;
    for (int i = pattern_split_size - 1; i >= 0; i--) {
        printf("%s\n", pattern_split[i]);
        int p_index = match_main(match_index, s, pattern_split[i]);
        printf("%d\n--\n", p_index);
        if (p_index != -1) {
            match_index = p_index;
        } else if (p_index == -1) {
            result = true;
            break;
        }
        
    }
    for (int i = 0; i < pattern_split_size; i++) {
        free(pattern_split[i]);
    }
    free(pattern_split);
    printf("\n");
    return result;
}