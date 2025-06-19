#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    bool result = false;
    printf("==========================================\n\n");
    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    printf("s: %d\n", strlen(s));
    printf("p: %d\n", strlen(p));

    bool v[20][20] = { false };

    for (int i=0; i < pattern_str_length; i++) {
        for (int j=0; j < source_str_length; j++) {
            if (p[i] == s[j] || p[i] == '.') {
                v[i][j] = true;
            } else if (p[i] == '*') {
                if (s[j] == p[i - 1] || p[i - 1] == '.') {
                    v[i][j] = true;
                } else {
                    v[i][j] = false;
                }
            } else if (p[i] != s[j]) {
                v[i][j] = false;
            }
        }
    }

    for (int i=0; i < pattern_str_length; i++) {
        if (p[i] == '*') {
            continue;
        }
        if (v[i][0] == 0 && p[i + 1] != '*') {
            result = false;
            break;  // 代表根本不通
        }
        if (v[i][0] == 1) {
            for (int j=0; j < source_str_length; j++) {
                if (v[i][j] == 0) {
                    break;
                }

                if (((i + 1) < pattern_str_length) && ((j + 1) < source_str_length)) {
                    if (p[i + 1] != '*' && v[i + 1][j + 1] == 1) {
                        printf("[%d %d]: %d\n", i + 1, j + 1, v[i + 1][j + 1]);
                    } else if (p[i + 1] == '*') {   // 如果匹配到 '*'
                        if ((i + 2) < pattern_str_length && v[i + 2][j + 1] == 1) { // 而且剩餘pattern長度還足夠
                            printf("[%d %d]: %d\n", i + 2, j + 1, v[i + 2][j + 1]);
                        } else if ((i + 2) >= pattern_str_length) {
                            printf("[%d %d]: %d\n", i + 1, j + 1, v[i + 1][j + 1]);
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i < 20; i++) {
        if (i < source_str_length) {
            printf("%c ", s[i]);
        }
    }

    printf("\n--------------------\n");

    for (int i=0; i < 20; i++) {
        // if (p[i] == '*') {
        //     continue;
        // }
        for (int j=0; j < 20; j++) {
            if (v[i][j] == 0) {
                printf("  ");
                continue;
            }
            printf("%d ", v[i][j]);
        }
        if (i < pattern_str_length) {
            printf("| %c", p[i]);
        }
        printf("\n");
    }

    printf("\n\n");

    printf("answer: %d\n", result);
    
    return result;
}

int main(void) {
    // isMatch("abd", "ab*a"); // false
    isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"); // false
    // isMatch("asdvcavsdrfte", ".");
    return 0;
}