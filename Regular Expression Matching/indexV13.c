#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {

    printf("==========================================\n\n");
    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    printf("s: %d\n", strlen(s));
    printf("p: %d\n", strlen(p));

    int v[20][20] = { 0 };

    for (int i=0; i < pattern_str_length; i++) {
        for (int j=0; j < source_str_length; j++) {
            if (p[i] == s[j] || p[i] == '.') {
                v[i][j] = 1;
            } else if (p[i] == '*') {
                if (s[j] == p[i - 1] || p[i - 1] == '.') {
                    v[i][j] = 1;
                } else {
                    v[i][j] = 0;
                }
            } else if (p[i] != s[j]) {
                v[i][j] = 0;
            }
        }
    }

    bool result = false;

    for (int i=0; i < pattern_str_length; i++) {
        if (p[i] == '*') {
            continue;
        }
        if (v[i][0] == 0 && p[i + 1] != '*') {
            result = false;
            break;  // 代表根本不通
        }
        if (v[i][0] == 1) {
            for (int j=0, k=0; j < source_str_length; j++) {
                if (v[i][j] == 0) {
                    result = false;
                    break;
                } else if ((i + 1) == pattern_str_length && p[i] == '*') {
                    break;
                }

                int x = j, y = i;
                
                if (p[i + 1] != '*' && p[i + 1] != '\0' && v[i + 1][j + 1] == 1) {
                    
                    x = j + 1;
                    y = i + 1;
                    printf("[%d %d %d %d]\n", j, i, x, y);
                } else if (p[i + 1] == '*') {
                    if ((i + 2) < pattern_str_length && v[i + 2][j + 1] == 1) {
                        x = j + 1;
                        y = i + 2;
                        printf("[%d %d %d %d]\n", j, i, x, y);
                    } else if ((i + 2) >= pattern_str_length) {
                        x = j;
                        y = i + 1;
                        printf("[%d %d %d %d]\n", j, i, x, y);
                    }
                } else {
                    printf("[%d %d %d %d]\n", j, i, x, y);
                }

                // 以v[x][y]為起點
                for (; x < source_str_length && y < pattern_str_length;) {
                    
                    if ((y + 1) < pattern_str_length && p[y + 1] == '*') {   // 直接狀態往下轉移
                        y = y + 1;
                        continue;
                    }

                    printf(" -> [x:%d, y:%d]: %d\n", x, y, v[y][x]);

                    if (v[x][y] == 0) {
                        if (p[y] != '*') {
                            result = false;
                            break;
                        }
                    } else {
                        printf(" -> [x:%d, y:%d]: %d\n", x, y, v[y][x]);
                        x = x + 1;
                        result = true;
                    }
                    
                    y = y + 1;
                    
                    
                    // if (v[y + 1][x + 1] == 1) {
                    //     x = x + 1;
                    //     y = y + 1;
                    // } else if (v[y + 1][x + 1] == 0) {    // 如果下一格狀態不匹配，代表路徑中斷
                    //     printf(" -> [x:%d, y:%d]: %d\n", x + 1, y + 1, v[y + 1][x + 1]);
                    //     break;
                    // }
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
    // isMatch("aa", "a*"); // true
    // isMatch("mississippi", "mis*is*ip*."); // true
    // isMatch("mississippi", "mis*is*p*."); // false
    // isMatch("bbcaccbabbcbaaccabc", "...*"); // true
    isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"); // false
    // isMatch("bbacbcabbbbbcacabb", "aa*c*b*a*.*a*a.*."); // false
    // isMatch("a", "ab*a"); // false
    // isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"); // false
    // isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"); // false
    // isMatch("bbb", "b"); // true
    // isMatch("bbb", "b"); // true
    
    return 0;
}